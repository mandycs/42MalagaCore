# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mancorte <mancorte@student.42malaga.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 00:00:00 by mancorte          #+#    #+#              #
#    Updated: 2025/01/08 00:00:00 by mancorte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = inception

DATA_DIR = /home/mancorte/data
WP_DIR = $(DATA_DIR)/wordpress
DB_DIR = $(DATA_DIR)/mariadb

COMPOSE = docker compose -f srcs/docker-compose.yml

all: setup build up

setup:
	@echo "Creating data directories..."
	@sudo mkdir -p $(WP_DIR)
	@sudo mkdir -p $(DB_DIR)
	@echo "Data directories created."

build:
	@echo "Building Docker images..."
	@$(COMPOSE) build
	@echo "Build complete."

up:
	@echo "Starting containers..."
	@$(COMPOSE) up -d
	@echo "Containers started."

down:
	@echo "Stopping containers..."
	@$(COMPOSE) down
	@echo "Containers stopped."

start:
	@echo "Starting containers..."
	@$(COMPOSE) start
	@echo "Containers started."

stop:
	@echo "Stopping containers..."
	@$(COMPOSE) stop
	@echo "Containers stopped."

status:
	@$(COMPOSE) ps

logs:
	@$(COMPOSE) logs -f

clean: down
	@echo "Removing volumes..."
	@$(COMPOSE) down -v
	@echo "Volumes removed."

fclean: clean
	@echo "Removing images..."
	@docker rmi -f $$(docker images -q inception-*) 2>/dev/null || true
	@echo "Removing data directories..."
	@sudo rm -rf $(DATA_DIR)
	@echo "Full clean complete."

re: fclean all

.PHONY: all setup build up down start stop status logs clean fclean re
