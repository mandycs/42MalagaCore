# Developer Documentation - Inception

This document describes how to set up, build, and maintain the Inception project as a developer.

## Setting Up the Environment from Scratch

### Prerequisites

1. **Docker** (version 20.10+)
   ```bash
   # Install Docker on Debian/Ubuntu
   sudo apt-get update
   sudo apt-get install docker.io docker-compose
   sudo usermod -aG docker $USER
   # Log out and back in for group changes to take effect
   ```

2. **Make** utility
   ```bash
   sudo apt-get install make
   ```

3. **Git** (for version control)
   ```bash
   sudo apt-get install git
   ```

### Configuration Files

#### 1. Environment Variables (srcs/.env)

Create or edit `srcs/.env` with your configuration:

```bash
# Domain Configuration
DOMAIN_NAME=mancorte.42.fr

# MariaDB Configuration
MYSQL_ROOT_PASSWORD=your_root_password
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser
MYSQL_PASSWORD=your_db_password

# WordPress Configuration
WP_ADMIN_USER=mancorte
WP_ADMIN_PASSWORD=your_admin_password
WP_ADMIN_EMAIL=mancorte@student.42malaga.com
WP_TITLE=Inception WordPress
WP_URL=https://mancorte.42.fr

# WordPress Regular User
WP_USER=regular_user
WP_USER_PASSWORD=your_user_password
WP_USER_EMAIL=user@mancorte.42.fr

# Volumes
DATA_DIR=/home/mancorte/data
WP_DATA_DIR=/home/mancorte/data/wordpress
DB_DATA_DIR=/home/mancorte/data/mariadb
```

#### 2. Secrets Files

Create the `secrets/` directory with credential files:

```bash
mkdir -p secrets

# Database root password
echo "your_root_password" > secrets/db_root_password.txt

# Database user password
echo "your_db_password" > secrets/db_password.txt

# All credentials summary
cat > secrets/credentials.txt << EOF
WordPress Admin: mancorte / your_admin_password
WordPress User: regular_user / your_user_password
Database Root: rootpass
Database User: wpuser / your_db_password
EOF
```

#### 3. Domain Configuration

Add the domain to your hosts file:

```bash
echo "127.0.0.1 mancorte.42.fr" | sudo tee -a /etc/hosts
```

### Git Ignore Configuration

Ensure `.gitignore` includes sensitive files:

```
.env
secrets/
/home/mancorte/data/
```

## Building and Launching the Project

### Using the Makefile

| Command | Description |
|---------|-------------|
| `make` | Complete setup: create dirs, build images, start containers |
| `make setup` | Create data directories only |
| `make build` | Build Docker images only |
| `make up` | Start containers (assumes images exist) |
| `make down` | Stop containers |
| `make start` | Start stopped containers |
| `make stop` | Stop containers without removing |
| `make status` | Show container status |
| `make logs` | Follow container logs |
| `make clean` | Stop and remove volumes |
| `make fclean` | Full cleanup (images + data directories) |
| `make re` | Rebuild from scratch |

### Using Docker Compose Directly

```bash
# Build images
docker compose -f srcs/docker-compose.yml build

# Start services
docker compose -f srcs/docker-compose.yml up -d

# Stop services
docker compose -f srcs/docker-compose.yml down

# View logs
docker compose -f srcs/docker-compose.yml logs -f
```

## Managing Containers and Volumes

### Container Management

```bash
# List all containers
docker ps -a

# Access container shell
docker exec -it nginx sh
docker exec -it wordpress sh
docker exec -it mariadb sh

# Restart a specific container
docker restart nginx

# View container resource usage
docker stats
```

### Volume Management

```bash
# List volumes
docker volume ls

# Inspect a volume
docker volume inspect srcs_wordpress-data
docker volume inspect srcs_mariadb-data

# Remove unused volumes
docker volume prune
```

### Network Management

```bash
# List networks
docker network ls

# Inspect network
docker network inspect srcs_inception-network

# See which containers are connected
docker network inspect srcs_inception-network --format='{{range .Containers}}{{.Name}} {{end}}'
```

### Image Management

```bash
# List images
docker images | grep inception

# Remove specific image
docker rmi inception-nginx:1.0

# Remove all project images
docker rmi $(docker images -q inception-*)
```

## Data Storage and Persistence

### Data Locations

| Data Type | Host Path | Container Path |
|-----------|-----------|----------------|
| WordPress files | `/home/mancorte/data/wordpress` | `/var/www/html` |
| MariaDB database | `/home/mancorte/data/mariadb` | `/var/lib/mysql` |

### How Persistence Works

Data persists through Docker bind mounts defined in `docker-compose.yml`:

```yaml
volumes:
  wordpress-data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/mancorte/data/wordpress
  mariadb-data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/mancorte/data/mariadb
```

### Backup and Restore

**Backup WordPress:**
```bash
sudo tar -czvf wp_backup_$(date +%Y%m%d).tar.gz /home/mancorte/data/wordpress
```

**Backup Database:**
```bash
docker exec mariadb mysqldump -u root -p$MYSQL_ROOT_PASSWORD --all-databases > db_backup_$(date +%Y%m%d).sql
```

**Restore WordPress:**
```bash
sudo tar -xzvf wp_backup_YYYYMMDD.tar.gz -C /
```

**Restore Database:**
```bash
docker exec -i mariadb mysql -u root -p$MYSQL_ROOT_PASSWORD < db_backup_YYYYMMDD.sql
```

## Project Structure

```
Inception/
├── Makefile                    # Build automation
├── README.md                   # Project overview
├── USER_DOC.md                 # User documentation
├── DEV_DOC.md                  # Developer documentation (this file)
├── .gitignore                  # Git ignore rules
├── secrets/                    # Credentials (git-ignored)
│   ├── credentials.txt
│   ├── db_password.txt
│   └── db_root_password.txt
└── srcs/
    ├── .env                    # Environment variables (git-ignored)
    ├── docker-compose.yml      # Service orchestration
    └── requirements/
        ├── mariadb/
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   ├── conf/
        │   │   └── my.cnf
        │   └── tools/
        │       └── init_db.sh
        ├── nginx/
        │   ├── Dockerfile
        │   ├── .dockerignore
        │   ├── conf/
        │   │   ├── nginx.conf
        │   │   └── default.conf
        │   └── tools/
        │       └── generate_ssl.sh
        └── wordpress/
            ├── Dockerfile
            ├── .dockerignore
            ├── conf/
            │   ├── php.ini
            │   └── www.conf
            └── tools/
                └── init_wordpress.sh
```

## Debugging

### View Real-time Logs

```bash
# All services
make logs

# Specific service
docker logs -f nginx
docker logs -f wordpress
docker logs -f mariadb
```

### Check Container Health

```bash
docker inspect --format='{{.State.Health.Status}}' mariadb
```

### Test Database Connection

```bash
docker exec -it wordpress sh -c 'nc -zv mariadb 3306'
```

### Test PHP-FPM

```bash
docker exec -it nginx sh -c 'nc -zv wordpress 9000'
```

### Check SSL Certificate

```bash
openssl s_client -connect mancorte.42.fr:443 -servername mancorte.42.fr
```

## Common Issues and Solutions

### Issue: Containers won't start

**Solution:** Check for port conflicts
```bash
sudo lsof -i :443
sudo lsof -i :3306
```

### Issue: WordPress can't connect to database

**Solution:** Verify MariaDB is ready before WordPress starts
```bash
docker logs mariadb | grep "ready for connections"
```

### Issue: Permission denied on volumes

**Solution:** Fix ownership
```bash
sudo chown -R 1000:1000 /home/mancorte/data/wordpress
sudo chown -R 999:999 /home/mancorte/data/mariadb
```

### Issue: SSL certificate errors

**Solution:** Regenerate certificates
```bash
docker exec nginx /usr/local/bin/generate_ssl.sh
docker restart nginx
```
