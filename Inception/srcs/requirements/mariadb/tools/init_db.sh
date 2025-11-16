#!/bin/sh

# Initialize MariaDB data directory if it doesn't exist
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB data directory..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql > /dev/null

    # Start MariaDB temporarily to execute setup commands
    mysqld --user=mysql --bootstrap << EOF
USE mysql;
FLUSH PRIVILEGES;

-- Remove anonymous users
DELETE FROM mysql.user WHERE User='';

-- Remove test database
DROP DATABASE IF EXISTS test;

-- Create WordPress database
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;

-- Create WordPress user with full privileges on WordPress database
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';

-- Set root password and allow root from anywhere
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
CREATE USER IF NOT EXISTS 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;

FLUSH PRIVILEGES;
EOF

    echo "MariaDB initialization complete."
else
    echo "MariaDB data directory already exists. Skipping initialization."
fi

# Start MariaDB
echo "Starting MariaDB..."
exec mysqld --user=mysql --console
