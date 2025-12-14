*This project has been created as part of the 42 curriculum by mancorte.*

# Inception

## Description

Inception is a System Administration project that introduces Docker containerization. The goal is to set up a small infrastructure composed of different services (NGINX, WordPress, MariaDB) running in separate Docker containers, orchestrated with Docker Compose.

The infrastructure includes:
- **NGINX**: Web server with TLSv1.2/TLSv1.3 SSL encryption (port 443)
- **WordPress + PHP-FPM**: Content management system
- **MariaDB**: Database server for WordPress

## Instructions

### Prerequisites

- Docker and Docker Compose installed
- Make utility
- Root/sudo access (for creating data directories)

### Quick Start

1. **Configure the domain name:**
```bash
echo "127.0.0.1 mancorte.42.fr" | sudo tee -a /etc/hosts
```

2. **Build and start the infrastructure:**
```bash
make
```

3. **Access the website:**
```
https://mancorte.42.fr
```

### Available Commands

| Command | Description |
|---------|-------------|
| `make` | Build and start all containers |
| `make build` | Build Docker images |
| `make up` | Start containers |
| `make down` | Stop containers |
| `make logs` | View container logs |
| `make clean` | Stop and remove volumes |
| `make fclean` | Full cleanup (images + data) |
| `make re` | Rebuild from scratch |

## Resources

### Documentation

- [Docker Documentation](https://docs.docker.com/)
- [Docker Compose Documentation](https://docs.docker.com/compose/)
- [NGINX Documentation](https://nginx.org/en/docs/)
- [WordPress Developer Resources](https://developer.wordpress.org/)
- [MariaDB Documentation](https://mariadb.com/kb/en/documentation/)

### AI Usage

AI tools were used in this project for:
- Generating initial Dockerfile templates and configuration files
- Writing documentation and README files
- Debugging configuration issues
- Understanding Docker best practices

All AI-generated content was reviewed, tested, and understood before implementation.

---

## Project Description

### Docker Architecture

This project uses Docker to create isolated containers for each service. Unlike virtual machines, Docker containers share the host OS kernel, making them lightweight and fast to start.

### Comparisons

#### Virtual Machines vs Docker

| Aspect | Virtual Machines | Docker |
|--------|------------------|--------|
| **Isolation** | Full OS isolation | Process-level isolation |
| **Resource Usage** | Heavy (full OS per VM) | Lightweight (shared kernel) |
| **Startup Time** | Minutes | Seconds |
| **Portability** | Hardware-dependent | Highly portable |
| **Use Case** | Full OS environments | Microservices, applications |

**Why Docker for this project:** Docker provides sufficient isolation for web services while being resource-efficient. Each service (NGINX, WordPress, MariaDB) runs in its own container with only the necessary dependencies.

#### Secrets vs Environment Variables

| Aspect | Environment Variables | Docker Secrets |
|--------|----------------------|----------------|
| **Storage** | Plain text in .env | Encrypted at rest |
| **Access** | Available to all processes | Only to authorized services |
| **Visibility** | Can be exposed in logs | Never exposed in logs |
| **Best For** | Non-sensitive config | Passwords, API keys |

**Implementation:** This project uses `.env` files for configuration variables and a `secrets/` directory for sensitive credentials, both ignored by git.

#### Docker Network vs Host Network

| Aspect | Docker Network (Bridge) | Host Network |
|--------|------------------------|--------------|
| **Isolation** | Containers isolated | No network isolation |
| **Port Mapping** | Required | Direct access |
| **Security** | Better (controlled exposure) | Less secure |
| **Communication** | Via container names | Via localhost |

**Implementation:** This project uses a custom bridge network (`inception-network`) allowing containers to communicate by service name while only exposing port 443 to the host.

#### Docker Volumes vs Bind Mounts

| Aspect | Docker Volumes | Bind Mounts |
|--------|---------------|-------------|
| **Management** | Managed by Docker | Direct host path |
| **Portability** | More portable | Host-dependent |
| **Performance** | Optimized by Docker | Native filesystem |
| **Backup** | Docker commands | Standard file tools |

**Implementation:** This project uses bind mounts to `/home/mancorte/data/` for data persistence, allowing easy access and backup of WordPress files and database data.

### Design Choices

1. **Alpine Linux 3.19**: Chosen as base image for minimal footprint and security
2. **PHP-FPM 8.2**: Modern PHP version with FastCGI Process Manager for WordPress
3. **TLSv1.2/1.3 Only**: Secure protocols, older versions disabled
4. **Self-signed SSL**: Appropriate for development/testing environment
5. **WP-CLI**: Automated WordPress installation without manual setup

## Author

**mancorte** - 42 Malaga
