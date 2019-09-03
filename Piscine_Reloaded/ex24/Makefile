# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cspider <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 23:06:48 by cspider           #+#    #+#              #
#    Updated: 2019/09/02 23:06:51 by cspider          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY = libft.a

SOURCE = srcs/

INCLUDES = includes/

FUNCTIONS = ft_putchar ft_putstr ft_strcmp ft_strlen ft_swap

BINARIES = $(patsubst  %, %.o, $(FUNCTIONS))

.PHONY: clean fclean re all

all:
	gcc -Wall -Wextra -Werror -c $(patsubst %.o, $(SOURCE)%.c, $(BINARIES)) -I $(INCLUDES)
	ar rc $(LIBRARY) $(BINARIES)
	ranlib $(LIBRARY)

clean:
	rm -f $(BINARIES)
 
fclean:	clean
	rm -f $(LIBRARY)

re: fclean all
