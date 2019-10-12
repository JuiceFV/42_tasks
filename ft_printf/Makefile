#----EDITABLE-----
NAME:=libftprintf.a
FILES:= evaluate_char \
		evaluate_color \
		evaluate_date \
		evaluate_double \
		evaluate_double_2 \
		evaluate_double_3 \
		evaluate_memory \
		evaluate_num \
		evaluate_num_2 \
		evaluate_num_3 \
		ft_evaluator \
		ft_printf \
		ft_vasprintf \
		ft_vprintf \
		utils 
#-----------------

#----LIBFTDIR-----
LFTDIR:=./libft
#-----------------

#----STANDART-----
CC:= gcc
LINKER:=ar rc
SRCPATH:=src/
INCPATH:=include/
OBJPATH:=obj/
INCFLAGS:= -I $(INCPATH) -I $(LFTDIR)/include
LFTFLAGS:= -L $(LFTDIR) -lft
CCFLAGS:=-Wall -Wextra -Werror $(INCFLAGS)
#-----------------

#----COLORS-------
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
#-----------------

#----SUBST--------
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(OBJPATH),$(addsuffix .o,$(FILES)))
#-----------------
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@ \xF0\x9F\x8E\x89  \xF0\x9F\x8E\x89  \xF0\x9F\x8E\x89" $(RED)
	@$(LINKER) $(NAME) $(OBJ) $(LFTDIR)/$(OBJPATH)*.o $(LFTDIR)/$(OBJPATH)*/*.o
	@ranlib $(NAME)
	@echo $(CREEN) " - OK \xF0\x9F\x98\x98  \xF0\x9F\x98\x98  \xF0\x9F\x98\x98" $(EOC)

$(OBJPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo $(PURPLE) " - Compiling $< into $@" $(EOC)
	@$(CC) $(CCFLAGS) -c $< -o $@

%.c:
	@echo $(RED)"Missing file : $@ \xF0\x9F\x98\xA1  \xF0\x9F\x98\xA1  \xF0\x9F\x98\xA1" $(EOC)

$(CCHF):
	@mkdir $(OBJPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(OBJPATH)
	@rm -f $(CCHF)
	@cd $(LFTDIR) && $(MAKE) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -f test_me
	@rm -rf test_me.dSYM/
	@rm -rf a.out.dSYM/
	@cd $(LFTDIR) && $(MAKE) fclean

re: fclean
	@$(MAKE) all

test: $(NAME)
	@echo "Files :" $(FILES)
	$(CC) -g -w $(CCFLAGS) main.c $(SRC) $(LFTFLAGS) -o test_me

debug: $(NAME)
	@echo "Files :" $(FILES)
	@$(CC) -g $(INCFLAGS) main.c $(SRC) $(LFTFLAGS)

norm:
	@echo $(RED)
	@echo "\xE2\x9D\x8C\n"
	@norminette $(SRC) $(INCPATH) | grep -v Norme -B1 || true
	@echo $(END)
	@cd $(LFTDIR) && $(MAKE) norm

.PHONY: all clean fclean re test debug norm


