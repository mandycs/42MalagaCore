# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 19:44:49 by mancorte          #+#    #+#              #
#    Updated: 2023/05/13 21:23:43 by mancorte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INC_DIR = ../inc
OBJ_DIR = ../obj
SRC_DIR = .
CC = gcc
SRC = ft_printf.c
OBJS = $(addprefix $(OBJ_DIR)/$(SRC:.c=.o))
LIBFT = LIBFT
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS) : $(SRC_DIR)/$(SRC)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $@ -o $<

clean:
	rm -rf $(OBJ_DIR)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY : clean fclean re all 