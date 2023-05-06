CC = gcc
NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c ft_bzero.c ft_memmove.c ft_toupper.c \
ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memcmp.c ft_strnstr.c \
ft_atoi.c ft_strlcpy.c ft_strlcat.c
OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror


all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

.PHONY: clean fclean re all
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all