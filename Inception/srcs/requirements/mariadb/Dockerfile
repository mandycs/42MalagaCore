FROM alpine:3.19

# Install MariaDB and MariaDB client
RUN apk update && \
    apk add --no-cache \
    mariadb \
    mariadb-client && \
    rm -rf /var/cache/apk/*

# Create necessary directories
RUN mkdir -p /var/run/mysqld && \
    chown -R mysql:mysql /var/run/mysqld && \
    mkdir -p /var/lib/mysql && \
    chown -R mysql:mysql /var/lib/mysql

# Copy initialization script
COPY tools/init_db.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/init_db.sh

# Copy MariaDB configuration
COPY conf/my.cnf /etc/my.cnf

# Expose port 3306
EXPOSE 3306

# Run initialization script
ENTRYPOINT ["/usr/local/bin/init_db.sh"]
