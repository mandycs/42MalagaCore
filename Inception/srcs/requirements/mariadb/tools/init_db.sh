#!/bin/sh

# Fix permissions on mounted volume (ignore errors on bind mounts)
if [ -d "/var/lib/mysql" ]; then
    chown -R mysql:mysql /var/lib/mysql 2>/dev/null || true
fi

# Initialize MariaDB data directory if it doesn't exist
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB data directory..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    # Start MariaDB temporarily in background
    mysqld --user=mysql &
    pid=$!

    # Wait for MariaDB to be ready
    echo "Waiting for MariaDB to start..."
    sleep 5
    while ! mysqladmin ping -h localhost --silent; do
        sleep 1
    done
    echo "MariaDB started."

    # Execute setup commands
    echo "Configuring database and users..."
    mysql -u root << EOF
DELETE FROM mysql.user WHERE User='';
DROP DATABASE IF EXISTS test;
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'localhost' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'localhost';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
CREATE USER IF NOT EXISTS 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EOF

    echo "MariaDB initialization complete."

    # Stop temporary MariaDB
    kill $pid
    wait $pid 2>/dev/null
    sleep 2
fi

# Start MariaDB
echo "Starting MariaDB..."
exec mysqld --user=mysql --console
