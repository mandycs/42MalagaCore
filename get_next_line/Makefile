# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jucortes <jucortes@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/28 17:00:00 by jucortes          #+#    #+#              #
#    Updated: 2026/10/29 00:00:00 by jucortes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= gnl
BONUS_NAME	= gnl_bonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# Permite fijar el tamano del buffer desde la linea de ordenes:
#   make BUFFER_SIZE=42
ifdef BUFFER_SIZE
CFLAGS		+= -D BUFFER_SIZE=$(BUFFER_SIZE)
endif

SRC			= get_next_line.c get_next_line_utils.c
BONUS_SRC	= get_next_line_bonus.c get_next_line_utils_bonus.c
MAIN		= main.c

OBJS		= $(SRC:.c=.o)
BONUS_OBJS	= $(BONUS_SRC:.c=.o)
MAIN_OBJ	= $(MAIN:.c=.o)

HEADERS		= get_next_line.h get_next_line_bonus.h

all: $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJ) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(MAIN_OBJ) -o $(BONUS_NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(MAIN_OBJ)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
