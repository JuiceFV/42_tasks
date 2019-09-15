# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olongbot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 21:54:00 by olongbot          #+#    #+#              #
#    Updated: 2019/09/15 18:06:39 by cspider          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit
CC := gcc

SRC := main.c read.c tetra_functions.c tools.c valid.c
OBJ := $(patsubst %.c, %.o, $(SRC))

LIB_FLAG := -Llibft/ -lft
CFLAGS := -Wall -Werror -Wextra
.PHONY: all clean fclean re

all: $(NAME)

%.o : %.c fillit.h
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo $(patsubst %.c, %, $<)

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
