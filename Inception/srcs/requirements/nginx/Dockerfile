FROM alpine:3.22

# Install NGINX and OpenSSL
RUN apk update && \
    apk add --no-cache \
    nginx \
    openssl && \
    rm -rf /var/cache/apk/*

# Create directory for SSL certificates
RUN mkdir -p /etc/nginx/ssl

# Copy NGINX configuration
COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY conf/default.conf /etc/nginx/http.d/default.conf

# Copy SSL certificate generation script
COPY tools/generate_ssl.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/generate_ssl.sh

# Generate SSL certificates
RUN /usr/local/bin/generate_ssl.sh

# Create directory for PID file
RUN mkdir -p /run/nginx

# Expose port 443 only (HTTPS)
EXPOSE 443

# Start NGINX in foreground
CMD ["nginx", "-g", "daemon off;"]
