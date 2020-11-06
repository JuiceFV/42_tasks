#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olongbot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 16:42:09 by olongbot          #+#    #+#              #
#    Updated: 2020/10/25 19:30:09 by olongbot         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

CC := gcc
FLAGS := -Wall -Werror -Wextra
LIBFT_DIRECTORY := libft/
LIBRARIES := -L$(LIBFT_DIRECTORY) -lft

LIBFT := $(LIBFT_DIRECTORY)libft.a

HEADERS_DIRECTORY := includes/
HEADERS := $(HEADERS_DIRECTORY)lem_in.h

INCLUDES := -I$(HEADERS_DIRECTORY) -I$(LIBFT_DIRECTORY)

SOURCES_DIRECTORY := src/
SOURCES_LIST := main.c \
	parse.c\
	parse_rooms.c\
	parse_links.c\
	parse_locations.c\
	is.c\
	validate.c\
	bfs.c\
	link_operations.c\
	delete_input_forks.c\
	delete_output_forks.c\
	paths.c\
	perform_turns.c\
	turn_location.c\
	clean.c\
	free_lists.c\
	utils.c\
	utils_2.c\
	read_next_line.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@$(CC) -o $(NAME) $(FLAGS) $(INCLUDES) $(OBJECTS) $(LIBRARIES)
	@echo "done"

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo $(patsubst src/%.c, %, $<)

$(LIBFT):
	@make -sC $(LIBFT_DIRECTORY)
	@echo "lib compiled"

clean:
	@make -sC $(LIBFT_DIRECTORY) clean
	@rm  $(OBJECTS)
	@echo "cleaned"

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFT_DIRECTORY) fclean
	@echo "fcleaned"

re: fclean all