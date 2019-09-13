# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olongbot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 21:54:00 by olongbot          #+#    #+#              #
#    Updated: 2019/09/14 01:53:00 by olongbot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit
INCLUDES := includes/
CC := gcc

SRC := src/main.c src/read.c src/tetra_functions.c src/tools.c src/valid.c
OBJ := $(patsubst src/%.c, %.o, $(SRC))

LIB_FLAG := -Llibft/ -lft
CFLAGS := -Wall -Werror -Wextra
.PHONY: all clean fclean re

all: $(NAME)

%.o : src/%.c $(INCLUDES)fillit.h
	@$(CC) -c $(CFLAGS) -I$(INCLUDES) $< -o $@
	@echo $(patsubst src/%.c, %, $<)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) $(CFLAGS) $(LIB_FLAG) $(OBJ)
	@echo "Done"

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean $(NAME)
