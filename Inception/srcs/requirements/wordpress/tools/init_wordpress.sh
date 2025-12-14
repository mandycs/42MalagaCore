#!/bin/sh

echo "Waiting for MariaDB to be ready..."
# Wait for MariaDB port to be available
while ! nc -z mariadb 3306; do
    sleep 1
done

# Wait extra time for MariaDB to fully initialize
echo "MariaDB port open, waiting for database to be fully ready..."
sleep 10

# Test actual database connection with retries
max_retries=30
retry=0
while [ $retry -lt $max_retries ]; do
    if mysql -h mariadb -u ${MYSQL_USER} -p${MYSQL_PASSWORD} -e "SELECT 1" >/dev/null 2>&1; then
        echo "MariaDB is ready!"
        break
    fi
    retry=$((retry + 1))
    echo "Waiting for database connection... ($retry/$max_retries)"
    sleep 2
done

if [ $retry -eq $max_retries ]; then
    echo "Error: Could not connect to MariaDB after $max_retries attempts"
    exit 1
fi

# Change to WordPress directory
cd /var/www/html

# Download WordPress if not already present
if [ ! -f wp-config.php ]; then
    echo "Downloading WordPress..."
    wp core download --allow-root

    echo "Creating wp-config.php..."
    wp config create \
        --dbname=${MYSQL_DATABASE} \
        --dbuser=${MYSQL_USER} \
        --dbpass=${MYSQL_PASSWORD} \
        --dbhost=mariadb \
        --allow-root

    echo "Installing WordPress..."
    wp core install \
        --url=${WP_URL} \
        --title="${WP_TITLE}" \
        --admin_user=${WP_ADMIN_USER} \
        --admin_password=${WP_ADMIN_PASSWORD} \
        --admin_email=${WP_ADMIN_EMAIL} \
        --skip-email \
        --allow-root

    echo "Creating regular user..."
    wp user create \
        ${WP_USER} \
        ${WP_USER_EMAIL} \
        --role=author \
        --user_pass=${WP_USER_PASSWORD} \
        --allow-root

    echo "WordPress installation complete!"
else
    echo "WordPress already installed."
fi

# Set proper permissions
chown -R nobody:nobody /var/www/html

echo "Starting PHP-FPM..."
# Start PHP-FPM in foreground
exec php-fpm82 -F
