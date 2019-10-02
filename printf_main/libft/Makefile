#=========EDITABLE=========
NAME:= libft.a

FT_MEM_PATH:=ft_memory/
FT_MEM_SRC:= ft_memset \
		     ft_bzero \
		     ft_memcpy \
		     ft_memccpy \
		     ft_memmove \
		     ft_memchr \
		     ft_memcmp \
		     ft_memalloc \
		     ft_memdel \

FT_STR_PATH:= ft_string/
FT_STR_SRC:= ft_strlen \
		     ft_strdup \
		     ft_strcpy \
		     ft_strncpy \
		     ft_strcat \
		     ft_strncat \
		     ft_strlcat \
		     ft_strchr \
		     ft_strrchr \
		     ft_strstr \
		     ft_strnstr \
		     ft_strcmp \
		     ft_strncmp \
		     ft_atoi \
		     ft_isalpha \
		     ft_isdigit \
		     ft_isalnum \
		     ft_isascii \
		     ft_isprint \
		     ft_toupper \
		     ft_tolower \
		     ft_strnew \
		     ft_strdel \
		     ft_strclr \
		     ft_striter \
		     ft_striteri \
		     ft_strmap \
		     ft_strmapi \
		     ft_strequ \
		     ft_strnequ \
		     ft_strsub \
		     ft_strjoin \
		     ft_strtrim \
		     ft_strsplit \
		     ft_itoa \
		     ft_putchar \
		     ft_putstr \
		     ft_putendl \
		     ft_putnbr \
		     ft_putchar_fd \
		     ft_putstr_fd \
		     ft_putendl_fd \
		     ft_putnbr_fd \
		     ft_itoa_base \
		     ft_hexisdigit

FT_LST_PATH:= ft_list/
FT_LST_SRC:= ft_lstnew \
			 ft_lstdelone \
		   	 ft_lstdel \
		     ft_lstadd \
		   	 ft_lstiter \
		   	 ft_lstmap 

FT_MAT_PATH:= ft_math/
FT_MAT_SRC:= ft_polynomial \
		   	 ft_power \
		   	 ft_derivative \
		   	 ft_abs \

FT_VEC_PATH:= ft_vector/
FT_VEC_SRC:= ft_vec_alloc \
			 ft_vec_clear \
			 ft_vec_popback \
			 ft_vec_replace \
			 ft_vec_resize \
			 ft_vec_trim \
			 ft_vec_append \
			 ft_vec_new \
			 ft_vec_popindex \
			 ft_vec_reserve \
			 ft_vec_string \
			 ft_vec_segswap

FILES:= get_next_line

#==========================

#=========STANDART=========
CC:=gcc
OBJPATH:=obj/
SRCPATH:=src/
INCPATH:=include/
CFLAGS:= -Wall -Wextra -Werror -I $(INCPATH)
#==========================

#=========COLORS===========
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
#==========================

#=========SUBST============
FILES+=$(addprefix $(FT_VEC_PATH),$(FT_VEC_SRC))
FILES+=$(addprefix $(FT_LST_PATH),$(FT_LST_SRC))
FILES+=$(addprefix $(FT_MAT_PATH),$(FT_MAT_SRC))
FILES+=$(addprefix $(FT_STR_PATH),$(FT_STR_SRC))
FILES+=$(addprefix $(FT_MEM_PATH),$(FT_MEM_SRC))

SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(OBJPATH),$(addsuffix .o,$(FILES)))
#==========================
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(END)
	@echo $(CYAN) " - Compiling $@ \xF0\x9F\x8E\x89  \xF0\x9F\x8E\x89  \xF0\x9F\x8E\x89" $(RED)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN) " - Done \xF0\x9F\x98\x98  \xF0\x9F\x98\x98  \xF0\x9F\x98\x98" $(END)

$(OBJPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo $(GREEN) "\xE2\x9C\x94 \c"
	@$(CC) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED) "Missing file : $@ \xF0\x9F\x98\xA1  \xF0\x9F\x98\xA1  \xF0\x9F\x98\xA1" 

$(CCHF):
	@mkdir $(OBJPATH)
	@mkdir $(OBJPATH)$(FT_VEC_PATH)
	@mkdir $(OBJPATH)$(FT_LST_PATH)
	@mkdir $(OBJPATH)$(FT_MAT_PATH)
	@mkdir $(OBJPATH)$(FT_STR_PATH)
	@mkdir $(OBJPATH)$(FT_MEM_PATH)
	@touch $(CCHF)

clean:
	@rm -rf $(OBJPATH)
	@rm -f $(CCHF)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all

norm:
	@echo $(RED)
	@echo "\xE2\x9D\x8C\n"
	@norminette $(SRC) $(INCPATH) | grep -v Norme -B1 || true
	@echo $(END)

.PHONY: all clean fclean re test norme
