# This is a minimal set of ANSI/VT100 color codes
END			=	\e[0m
BOLD		=	\e[1m
UNDER		=	\e[4m
REV			=	\e[7m

# Colors

DEF_COLOR 	= 	\033[0;39m
GRAY 		= 	\033[0;90m
GREY_01		=	\033[30m
RED 		= 	\033[0;91m
RED_01		=	\033[31m
GREEN 		= 	\033[0;92m
GREEN_01	=	\033[32m
YELLOW 		= 	\033[0;93m
YELLOW_01	=	\033[33m
BLUE 		= 	\033[0;94m
BLUE_01		=	\033[34m
PURPLE		=	\033[35m
MAGENTA 	= 	\033[0;95m
CYAN 		= 	\033[0;96m
CYAN_01		=	\033[36m
WHITE 		= 	\033[0;97m
WHITE_01	=	\033[37m

# Inverted, i.e. colored backgrounds
IGREY		=	\e[40m
IRED		=	\e[41m
IGREEN		=	\e[42m
IYELLOW		=	\e[43m
IBLUE		=	\e[44m
IPURPLE		=	\e[45m
ICYAN		=	\e[46m
IWHITE		=	\e[47m

# **************************************************************************** #

#Variables‹

NAME			= philo
SRC_DIR			= src/
OBJ_DIR			= obj/
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g
RM				= rm -f
AR				= ar rcs

# =========================================================================== #


#Sources

SRC_FILES	=	main parse error init_data eat time getters routine\
				setters print sleep philo_n_meal take_fork drop_fork\
				checker free think

SRCS 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME)
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(MAGENTA)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(OBJF):
			@mkdir -p $(OBJ_DIR)

# Rules

clean:
			@$(RM) -rf $(OBJ_DIR)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(NAME2)
			@$(RM) -f $(NAME_TEST)
			@$(RM) -f $(NAME_DEBUG)
			@echo "$(CYAN)$(NAME) executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(YELLOW)$(NAME) recompiled!$(DEF_COLOR)"
			@echo "\n"

.PHONY:		all clean fclean re git