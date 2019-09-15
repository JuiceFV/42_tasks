# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olongbot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 18:06:08 by olongbot          #+#    #+#              #
#    Updated: 2019/09/06 14:54:34 by olongbot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES = libft.h

SRC = ft_memset.c 		\
		ft_bzero.c 		\
		ft_memcpy.c 	\
		ft_memccpy.c 	\
		ft_memmove.c 	\
		ft_memchr.c 	\
		ft_memcmp.c 	\
		ft_strlen.c 	\
		ft_strdup.c 	\
		ft_strcpy.c 	\
		ft_strncpy.c 	\
		ft_strcat.c 	\
		ft_strncat.c 	\
		ft_strlcat.c 	\
		ft_strchr.c 	\
		ft_strrchr.c 	\
		ft_strstr.c 	\
		ft_strnstr.c 	\
		ft_strcmp.c 	\
		ft_strncmp.c 	\
		ft_atoi.c 		\
		ft_isalpha.c 	\
		ft_isdigit.c 	\
		ft_isalnum.c 	\
		ft_isascii.c 	\
		ft_isprint.c 	\
		ft_toupper.c 	\
		ft_tolower.c 	\
		ft_memalloc.c 	\
		ft_memdel.c 	\
		ft_strnew.c 	\
		ft_strdel.c 	\
		ft_strclr.c 	\
		ft_striter.c 	\
		ft_striteri.c 	\
		ft_strmap.c 	\
		ft_strmapi.c 	\
		ft_strequ.c 	\
		ft_strnequ.c 	\
		ft_strsub.c 	\
		ft_strjoin.c 	\
		ft_strtrim.c 	\
		ft_strsplit.c 	\
		ft_itoa.c 		\
		ft_putchar.c 	\
		ft_putstr.c 	\
		ft_putendl.c 	\
		ft_putnbr.c 	\
		ft_putchar_fd.c \
		ft_putstr_fd.c 	\
		ft_putendl_fd.c \
		ft_putnbr_fd.c 	\
		ft_lstnew.c 	\
		ft_lstdelone.c 	\
		ft_lstdel.c 	\
		ft_lstadd.c 	\
		ft_lstiter.c 	\
		ft_lstmap.c 	\
		ft_itoa_base.c 	\
		ft_abs.c 		\
		ft_power.c 		\
		ft_factorial.c 	\
		ft_swap.c 		\
		get_next_line.c \

OBJ = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(SRC)
	@gcc $(FLAGS) -c $(SRC)

clean:
	@rm -f $(OBJ) 

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
