# Inception

Proyecto de infraestructura con Docker del curriculum de 42.

## Descripción

Este proyecto configura una pequeña infraestructura compuesta por diferentes servicios usando Docker Compose:
- **NGINX** con TLSv1.2/TLSv1.3 (puerto 443)
- **WordPress + PHP-FPM** (puerto 9000)
- **MariaDB** (puerto 3306)

## Requisitos

- Docker
- Docker Compose
- Make

## Configuración Inicial

### 1. Configurar /etc/hosts

Añade el dominio al archivo /etc/hosts:

```bash
echo "127.0.0.1 mancorte.42.fr" | sudo tee -a /etc/hosts
```

### 2. Verificar variables de entorno

Revisa y ajusta las variables en `srcs/.env` según tus necesidades. Las contraseñas actuales son de ejemplo y deberían cambiarse en producción.

### 3. Verificar archivos de secretos

Los archivos en `secrets/` contienen credenciales sensibles. Asegúrate de que están en el `.gitignore`.

## Uso

### Construir e iniciar el proyecto

```bash
make
```

Este comando:
1. Crea los directorios de datos en `/home/mancorte/data/`
2. Construye las imágenes Docker
3. Levanta los contenedores

### Comandos disponibles

```bash
make build          # Construir las imágenes
make up             # Levantar los contenedores
make down           # Detener los contenedores
make start          # Iniciar contenedores detenidos
make stop           # Detener contenedores sin eliminarlos
make status         # Ver estado de los contenedores
make logs           # Ver logs en tiempo real
make clean          # Detener y eliminar volúmenes
make fclean         # Limpieza completa (imágenes + datos)
make re             # Reconstruir todo desde cero
```

## Acceso a los Servicios

### WordPress
- URL: https://mancorte.42.fr
- Admin: mancorte / admin123secure
- Usuario regular: regular_user / user123secure

### Base de Datos
- Host: mariadb
- Database: wordpress
- User: wpuser
- Password: wppass123secure
- Root password: rootpass123secure

## Estructura del Proyecto

```
Inception/
├── Makefile
├── secrets/                    # Credenciales (git-ignored)
│   ├── credentials.txt
│   ├── db_password.txt
│   └── db_root_password.txt
└── srcs/
    ├── .env                    # Variables de entorno
    ├── docker-compose.yml      # Orquestación de servicios
    └── requirements/
        ├── mariadb/
        │   ├── Dockerfile
        │   ├── conf/
        │   └── tools/
        ├── nginx/
        │   ├── Dockerfile
        │   ├── conf/
        │   └── tools/
        └── wordpress/
            ├── Dockerfile
            ├── conf/
            └── tools/
```

## Características Técnicas

### NGINX
- Alpine Linux 3.19
- SSL/TLS con certificado autofirmado
- Solo TLSv1.2 y TLSv1.3
- Proxy reverso a PHP-FPM

### WordPress
- Alpine Linux 3.19
- PHP 8.2 con PHP-FPM
- WP-CLI para instalación automatizada
- 2 usuarios (admin + regular)

### MariaDB
- Alpine Linux 3.19
- Inicialización automática de base de datos
- Persistencia de datos en volumen

## Volúmenes

Los datos se almacenan en:
- `/home/mancorte/data/wordpress` - Archivos de WordPress
- `/home/mancorte/data/mariadb` - Base de datos MariaDB

## Troubleshooting

### Los contenedores no inician
```bash
make logs
```

### Permiso denegado en directorios de datos
```bash
sudo chmod -R 755 /home/mancorte/data/
```

### Reiniciar desde cero
```bash
make fclean
make
```

### Ver contenedores en ejecución
```bash
docker ps
```

## Notas de Seguridad

- Las contraseñas en `.env` y `secrets/` son de ejemplo
- Cambiar todas las credenciales antes de usar en producción
- Los archivos sensibles están en `.gitignore`
- El certificado SSL es autofirmado (solo para desarrollo)

## Autor

**mancorte** - 42 Málaga
