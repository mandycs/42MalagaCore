# pipex
PIPEX = pipex
PIPEX_SRC_DIR = src/
PIPEX_OBJ_DIR = obj/
PIPEX_SRC_FILES = pipex pipex_utils pipex_utils_2 pipex_utils_3
PIPEX_SRC = $(addprefix $(PIPEX_SRC_DIR), $(addsuffix .c, $(PIPEX_SRC_FILES)))
PIPEX_OBJ = $(addprefix $(PIPEX_OBJ_DIR), $(addsuffix .o, $(PIPEX_SRC_FILES)))

# Variables Generales
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

# ft_printf
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a


# Compilación
all: $(FT_PRINTF_LIB) $(PIPEX)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(PIPEX): $(PIPEX_OBJ)
	$(CC) $(CFLAGS) -o $(PIPEX) $(PIPEX_OBJ) -L$(FT_PRINTF_DIR) -lftprintf

$(PIPEX_OBJ_DIR)%.o: $(PIPEX_SRC_DIR)%.c
	mkdir -p $(PIPEX_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza
clean:
	$(RM) -r $(PIPEX_OBJ_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(PIPEX)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
