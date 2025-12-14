# User Documentation - Inception

This document explains how to use the Inception infrastructure as an end user or administrator.

## Services Provided

The Inception stack provides the following services:

| Service | Description | Access |
|---------|-------------|--------|
| **WordPress** | Content Management System for creating and managing websites | https://mancorte.42.fr |
| **MariaDB** | Database server storing WordPress data | Internal only (port 3306) |
| **NGINX** | Web server handling HTTPS connections | Port 443 |

## Starting and Stopping the Project

### Start the Project

To start all services:

```bash
cd /home/mandycs/Escritorio/42MalagaCore/Inception
make
```

This command will:
1. Create necessary data directories
2. Build Docker images
3. Start all containers

### Stop the Project

To stop all services (containers remain):
```bash
make down
```

To stop and remove all data:
```bash
make fclean
```

### Check Status

To see running containers:
```bash
make status
```

Or using Docker directly:
```bash
docker ps
```

## Accessing the Website

### WordPress Site

1. Open your web browser
2. Navigate to: **https://mancorte.42.fr**
3. Accept the SSL certificate warning (self-signed certificate)
4. You will see the WordPress homepage

### WordPress Administration Panel

1. Navigate to: **https://mancorte.42.fr/wp-admin**
2. Enter your credentials:
   - **Username:** mancorte
   - **Password:** (see credentials section below)

### SSL Certificate Warning

The first time you access the site, your browser will show a security warning because the SSL certificate is self-signed. This is normal for development environments.

- **Chrome:** Click "Advanced" → "Proceed to mancorte.42.fr"
- **Firefox:** Click "Advanced" → "Accept the Risk and Continue"
- **Safari:** Click "Show Details" → "visit this website"

## Credentials Management

### Location of Credentials

All credentials are stored in the `secrets/` directory:

```
secrets/
├── credentials.txt      # All credentials summary
├── db_password.txt      # Database user password
└── db_root_password.txt # Database root password
```

### Default Credentials

| Service | Username | Password Location |
|---------|----------|-------------------|
| WordPress Admin | mancorte | secrets/credentials.txt |
| WordPress User | regular_user | secrets/credentials.txt |
| Database Root | root | secrets/db_root_password.txt |
| Database User | wpuser | secrets/db_password.txt |

### Changing Credentials

To change credentials:

1. Stop the project: `make down`
2. Edit the `.env` file in `srcs/` directory
3. Update the corresponding secrets files in `secrets/`
4. Remove existing data: `make fclean`
5. Restart: `make`

**Warning:** Changing credentials after initial setup requires a full rebuild.

## Verifying Services

### Check All Services Are Running

```bash
make status
```

Expected output shows 3 running containers:
- `nginx`
- `wordpress`
- `mariadb`

### Check Service Logs

View all logs:
```bash
make logs
```

View specific service logs:
```bash
docker logs nginx
docker logs wordpress
docker logs mariadb
```

### Test NGINX (SSL)

```bash
curl -k https://mancorte.42.fr
```

Should return HTML content.

### Test Database Connection

```bash
docker exec -it mariadb mysql -u wpuser -p
```

Enter the password from `secrets/db_password.txt`.

### Test WordPress

1. Access https://mancorte.42.fr
2. Navigate to /wp-admin
3. Log in with admin credentials
4. Create a test post to verify functionality

## Troubleshooting

### Site Not Accessible

1. Check if containers are running: `make status`
2. Check if domain is configured: `ping mancorte.42.fr`
3. View logs: `make logs`

### Database Connection Error

1. Check MariaDB is running: `docker ps | grep mariadb`
2. Check MariaDB logs: `docker logs mariadb`
3. Verify credentials in `.env` match those used during setup

### Permission Issues

```bash
sudo chmod -R 755 /home/mancorte/data/
sudo chown -R $USER:$USER /home/mancorte/data/
```

### Reset Everything

To completely reset the project:

```bash
make fclean
make
```

**Warning:** This will delete all WordPress content and database data.

## Data Backup

### WordPress Files

Located at: `/home/mancorte/data/wordpress/`

To backup:
```bash
tar -czvf wordpress_backup.tar.gz /home/mancorte/data/wordpress/
```

### Database

To backup the database:
```bash
docker exec mariadb mysqldump -u root -p wordpress > backup.sql
```

To restore:
```bash
docker exec -i mariadb mysql -u root -p wordpress < backup.sql
```
