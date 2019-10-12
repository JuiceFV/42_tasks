# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olongbot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 21:54:00 by olongbot          #+#    #+#              #
#    Updated: 2019/10/12 15:16:36 by cspider          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf
INCLUDES := includes/ 
CC := gcc

SRC_PATH := src/
FILES := main.c draw_line.c tools.c init.c hooks.c transform.c read_file.c map_adjust.c
SRC := $(patsubst %, $(SRC_PATH)%, $(FILES))
OBJ := $(patsubst %.c, %.o, $(FILES))

LIB_FLAG := -Llibft -lft
MLX_FLAGS := -lmlx -framework OpenGL -framework AppKit
CFLAGS := -Wall -Werror -Wextra
.PHONY: all clean fclean re

all: $(NAME)

%.o : $(SRC_PATH)%.c includes/fdf.h
	@$(CC) -c $(CFLAGS) -I$(INCLUDES) $< -o $@
	@echo $(patsubst src/%.c, %, $<)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(LIB_FLAG) $(CFLAGS) $(MLX_FLAGS) $(OBJ)
	@echo "Done"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
