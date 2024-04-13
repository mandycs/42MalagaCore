NAME    = push_swap
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra

SRC_DIR = src
OBJ_DIR = obj
SRC_FILES = push_swap.c push_swap_2.c push_swap_3.c push_swap_4.c push_swap_5.c push_swap_utils.c push_swap_utils_2.c moves.c moves_2.c moves_3.c

SRCS    = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS    = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
