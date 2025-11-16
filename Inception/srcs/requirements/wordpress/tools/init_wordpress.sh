#!/bin/sh

echo "Waiting for MariaDB to be ready..."
# Wait for MariaDB to be available
while ! nc -z mariadb 3306; do
    sleep 1
done
echo "MariaDB is ready!"

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
        --dbhost=mariadb:3306 \
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
