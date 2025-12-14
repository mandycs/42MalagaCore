FROM alpine:3.22

# Install PHP-FPM and required PHP extensions
RUN apk update && \
    apk add --no-cache \
    php82 \
    php82-fpm \
    php82-mysqli \
    php82-json \
    php82-curl \
    php82-dom \
    php82-exif \
    php82-fileinfo \
    php82-mbstring \
    php82-openssl \
    php82-xml \
    php82-zip \
    php82-phar \
    php82-intl \
    php82-session \
    php82-tokenizer \
    php82-xmlwriter \
    php82-simplexml \
    php82-ctype \
    php82-iconv \
    php82-gd \
    wget \
    tar \
    curl \
    netcat-openbsd \
    mariadb-client && \
    rm -rf /var/cache/apk/* && \
    ln -s /usr/bin/php82 /usr/bin/php

# Create PHP-FPM directories and set permissions
RUN mkdir -p /var/www/html && \
    chown -R nobody:nobody /var/www/html && \
    mkdir -p /run/php

# Download and install WP-CLI
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# Copy PHP-FPM configuration
COPY conf/www.conf /etc/php82/php-fpm.d/www.conf
COPY conf/php.ini /etc/php82/php.ini

# Copy WordPress initialization script
COPY tools/init_wordpress.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/init_wordpress.sh

# Set working directory
WORKDIR /var/www/html

# Expose port 9000 for PHP-FPM
EXPOSE 9000

# Run initialization script
ENTRYPOINT ["/usr/local/bin/init_wordpress.sh"]
