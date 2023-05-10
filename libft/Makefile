CC = gcc
NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c ft_bzero.c ft_memmove.c ft_toupper.c \
ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memcmp.c ft_strnstr.c \
ft_atoi.c ft_strlcpy.c ft_strlcat.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_itoa.c ft_numlen.c ft_invert.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_split.c ft_count_words.c ft_fill_array.c 
BSRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_memcpy.c ft_memchr.c
BOBJS = $(BSRC:.c=.o)
OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) $(BOBJS)
	ar rcs $(NAME) $(OBJS) $(BOBJS)

$(OBJS) : $(SRC) 
	$(CC) $(CFLAGS) -c $(SRC)
$(BOJS) : $(BSRC)
	$(CC) $(CFLAGS) -c $(SRC)

bonus : $(BOBJS)
	ar rcs $(NAME) $(BOBJS)
clean:
	rm -f $(OBJS) $(BOBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: clean fclean re all bonus