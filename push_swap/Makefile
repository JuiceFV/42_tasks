NAME:= checker
NAME_PS:= push_swap

C_SRC:= checker
PS_SRC:= push_swap
FILES:= a_stack_functions \
		   b_stack_functions \
		   commands \
		   errors_handler \
		   median \
		   solver \
		   stack_opers \
		   run_cmnds


LFTDIR:=./Libft

COMPILER:=gcc
SRCPATH:=src/
INCLPATH:=include/
OBJPATH:=obj/
IFLAGS:=-I $(INCLPATH) -I $(LFTDIR)/include
LFLAGS:=-L $(LFTDIR) -lft
CFLAGS:=-Wall -Wextra -Werror $(IFLAGS)

BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(OBJPATH),$(addsuffix .o,$(FILES)))
SRC_PS:=$(addprefix $(SRCPATH),$(addsuffix .c,$(PS_SRC)))
OBJ_PS:=$(addprefix $(OBJPATH),$(addsuffix .o,$(PS_SRC)))
SRC_C:=$(addprefix $(SRCPATH),$(addsuffix .c,$(C_SRC)))
OBJ_C:=$(addprefix $(OBJPATH),$(addsuffix .o,$(C_SRC)))
CCHF:=.cache_exists

all: $(NAME_PS) $(NAME)

$(NAME): $(OBJ) $(OBJ_C)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(COMPILER) $(CFLAGS) $(SRC) $(LFLAGS) $(SRCPATH)$(C_SRC).c -o $(NAME)
	@echo $(GREEN) " - OK" $(EOC)

$(NAME_PS): $(OBJ) $(OBJ_PS)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(COMPILER) $(CFLAGS) $(SRC) $(LFLAGS) $(SRC_PS) -o $(NAME_PS)
	@echo $(GREEN) " - OK" $(EOC)

$(OBJPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo $(PURPLE) " - Compiling $< into $@" $(EOC)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED)"Missing file : $@" $(EOC)

$(CCHF):
	@mkdir $(OBJPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(OBJPATH)
	@rm -f $(CCHF)
	@cd $(LFTDIR) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_PS)
	@cd $(LFTDIR) && $(MAKE) fclean

re: fclean
	@$(MAKE) all