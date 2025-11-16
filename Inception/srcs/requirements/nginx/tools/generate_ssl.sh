#!/bin/sh

# Generate self-signed SSL certificate for mancorte.42.fr
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/mancorte.42.fr.key \
    -out /etc/nginx/ssl/mancorte.42.fr.crt \
    -subj "/C=ES/ST=Malaga/L=Malaga/O=42Malaga/OU=mancorte/CN=mancorte.42.fr"

# Set proper permissions
chmod 600 /etc/nginx/ssl/mancorte.42.fr.key
chmod 644 /etc/nginx/ssl/mancorte.42.fr.crt

echo "SSL certificates generated successfully!"
