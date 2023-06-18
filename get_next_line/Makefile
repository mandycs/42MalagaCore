#Variables‹

NAME		= Get_new_line
GNL			= get_next_line.a
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar rcs

#Sources

SRC_FILES	=	get_next_line get_next_line_utils

# Files
SRC 		= 	$($(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))


OBJF		=	.cache_exists

all:		$(NAME)


$(NAME): $(GNL)
			$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(GNL) -o $(NAME)
			$(RM) -f $(GNL)
			$(RM) -rf $(OBJ_DIR)

$(GNL):	$(OBJ)
			$(AR) $(GNL) $(OBJ)

$(OBJ_DIR)%.o: %.c | $(OBJF)
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


$(OBJF):
			mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)

fclean:		clean
			$(RM) -f $(NAME)
			$(RM) -f $(GNL)

re:			fclean all

.PHONY:		all clean fclean test re