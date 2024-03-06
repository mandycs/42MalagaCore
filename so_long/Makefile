NAME    = so_long
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra
INCLUDE = -I include/
LIBS    = -ldl -lglfw -pthread -lm -L"/Users/mancorte/.brew/opt/glfw/lib/" -lglfw
MLX42   = -L MLX42 -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit

SRC_DIR = src
OBJ_DIR = obj
SRC_FILES = so_long.c get_next_line.c get_next_line_utils.c check_map.c check_map_2.c check_map_3.c init_map.c move.c move_2.c
SRCS    = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS    = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(MLX42) -o $(NAME)

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
