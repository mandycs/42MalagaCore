#STANDARD
NAME		=	libft.a
INCLUDE	=	../include
SRCS_DIR	=	src/
OBJS_DIR	=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I
RM			=	rm -f
AR			=	ar rcs


#SOURCES
FTIS_DIR	=	ft_is/
FTIS		=	ft_isalnum ft_isalpha ft_isascii ft_isblank ft_iscntrl ft_isdigit \
				ft_isgraph ft_isprint ft_ispunct ft_isspace ft_isxdigit

FTMEM_DIR	=	ft_mem/
FTMEM		=	ft_bzero ft_calloc ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset

FTPUT_DIR	=	ft_put/
FTPUT		=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FTTO_DIR	=	ft_to/
FTTO		=	ft_atoi ft_itoa ft_tolower ft_toupper

FTSTR_DIR	=	ft_str/
FTSTR		=	ft_count_words ft_fill_array ft_indexchar ft_invert ft_split ft_strcat \
				ft_strchr ft_strcmp ft_strcpy ft_strdup ft_striteri	ft_strjoin ft_strlcat \
				ft_strlcpy ft_strlen_2 ft_strlen ft_strmapi ft_strncat ft_strncmp ft_strncpy \
				ft_strndup ft_strncmp ft_strnstr ft_strrchr ft_strstr ft_strtrim ft_substr

FTLST_DIR	=	ft_lst/
FTLST		=	ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter ft_lstlast \
				ft_lstmap ft_lstnew ft_lstsize

FTNUM_DIR	=	ft_num/
FTNUM		=	ft_double ft_numlen ft_sqrt

SRC_FILES+=$(addprefix $(FTIS_DIR),$(FTIS))
SRC_FILES+=$(addprefix $(FTMEM_DIR),$(FTMEM))
SRC_FILES+=$(addprefix $(FTLST_DIR),$(FTLST))
SRC_FILES+=$(addprefix $(FTNUM_DIR),$(FTNUM))
SRC_FILES+=$(addprefix $(FTPUT_DIR),$(FTPUT))
SRC_FILES+=$(addprefix $(FTSTR_DIR),$(FTSTR))
SRC_FILES+=$(addprefix $(FTTO_DIR),$(FTTO))

SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))


###

OBJSF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJS)
					@$(AR) $(NAME) $(OBJS)
					@ranlib $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJSF)
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJSF):
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)$(FTIS_DIR)
					@mkdir -p $(OBJS_DIR)$(FTTO_DIR)
					@mkdir -p $(OBJS_DIR)$(FTMEM_DIR)
					@mkdir -p $(OBJS_DIR)$(FTLST_DIR)
					@mkdir -p $(OBJS_DIR)$(FTNUM_DIR)
					@mkdir -p $(OBJS_DIR)$(FTPUT_DIR)
					@mkdir -p $(OBJS_DIR)$(FTSTR_DIR)

clean:
					@$(RM) -rf $(OBJS_DIR)
					@$(RM) -rf $(OBJSF)

fclean:		clean
					@$(RM) -f $(NAME)
re:			fclean all

.PHONY: clean fclean re all