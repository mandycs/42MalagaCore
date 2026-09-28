NAME = main
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): main.c get_next_line.c get_next_line_utils.c get_next_line.h
	$(CC) $(CFLAGS) main.c get_next_line.c get_next_line_utils.c -o $(NAME)

bonus:
	$(CC) $(CFLAGS) main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o $(NAME)

re: fclean all

fclean:
	rm -f $(NAME) *.o

clean:
	rm -f *.o

.PHONY: all bonus re fclean clean
