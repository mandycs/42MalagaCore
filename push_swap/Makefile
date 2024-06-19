# @--------------------------------------------------------------------------@ #
# |                                 Colors                                   | #
# @--------------------------------------------------------------------------@ #

T_BLACK := \033[30m
T_RED := \033[31m
T_GREEN := \033[32m
T_YELLOW := \033[33m
T_BLUE := \033[34m
T_MAGENTA := \033[35m
T_CYAN := \033[36m
T_WHITE := \033[37m

BOLD := \033[1m
ITALIC := \033[2m
UNDERLINE := \033[3m
STRIKETHROUGH := \033[4m

CLEAR_LINE := \033[1F\r\033[2K

RESET := \033[0m

# @--------------------------------------------------------------------------@ #
# |                                 Macros                                   | #
# @--------------------------------------------------------------------------@ #

NAME := push_swap

INCLUDE_DIR := include/
SRC_DIR := src/
UTILS_DIR := utils/
OBJ_DIR := obj/

INCLUDE_FILES := push_swap.h
SRC_FILES := push_swap.c push_swap_2.c push_swap_3.c stacks_utils.c memo.c moves.c moves_2.c moves_3.c
UTILS_FILES := utils.c utils_2.c

INCLUDE = $(addprefix $(INCLUDE_DIR), $(INCLUDE_FILES))
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC)) \
 		$(patsubst $(UTILS_DIR)%.c, $(OBJ_DIR)%.o, $(UTILS))

CC = clang
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I $(INCLUDE_DIR)
LDFLAGS := 
LDLIBS := 

RM := rm -rf

# @--------------------------------------------------------------------------@ #
# |                                Messages                                  | #
# @--------------------------------------------------------------------------@ #

COMPILE_MSG = @echo "$(CLEAR_LINE)$(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
OBJ_MSG = @echo "$(T_MAGENTA)$(BOLD)$(NAME) $(T_YELLOW)Objects $(RESET)$(T_GREEN)created successfully!$(RESET)"
OUTPUT_MSG = @echo "$(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_GREEN)created successfully!$(RESET)"
CLEAN_MSG = @echo "$(T_MAGENTA)$(BOLD)$(NAME) $(T_YELLOW)Objects $(RESET)$(T_RED)destroyed successfully!$(RESET)"
FCLEAN_MSG = @echo "$(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_RED)destroyed successfully!$(RESET)"

# @--------------------------------------------------------------------------@ #
# |                                 Targets                                  | #
# @--------------------------------------------------------------------------@ #

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(OBJ_MSG)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LD_LIBS) # Use this if you want to create a program
	$(OUTPUT_MSG)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(UTILS_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	$(CLEAN_MSG)

fclean: clean
	@$(RM) $(NAME) *.out
	$(FCLEAN_MSG)

re:
	@make -s fclean
	@make -s all

.PHONY: all clean fclean re
