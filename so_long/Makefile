# Project Variables
NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I include -I $(LIBFTPRINTF_DIR)/include -I $(GNL_DIR) -D BUFFER_SIZE=32
LIBFTPRINTF_DIR = ft_printf
GNL_DIR = get_next_line
SRC_DIR = src
OBJ_DIR = obj
RM = rm -f

# Source and Object Files
SRC_FILES = check_map.c check_map_2.c so_long.c \
            get_next_line.c get_next_line_utils.c
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

# Compile and Link the Project
all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling ft_printf and libft..."
	@make -C $(LIBFTPRINTF_DIR)
	@echo "Compiling so_long..."
	@$(CC) $(OBJ) -L$(LIBFTPRINTF_DIR) -lftprintf -o $(NAME)

# Object File Compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Cleaning Rules
clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -C $(LIBFTPRINTF_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFTPRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
