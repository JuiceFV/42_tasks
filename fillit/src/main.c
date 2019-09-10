/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <myxaosa@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:07:56 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/04 23:45:33 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//todo check if square in the center
//todo chech for validity of a figure

#include "includes/fillit.h"

static void		usage()
{
	ft_putstr("usage: fillit file.fillit\n");
}

static int	print_error()
{
	ft_putstr("error\n");
	return(1);
}

int main(int argc, char **argv)
{
	int fd;
	char **tetras;
	int i;

	i = 0;

	if (argc != 2)
	{
		usage();
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (print_error());
	tetras = read_fillit(fd);
	if (!tetras)
		return (print_error());
	while (tetras[i][0] != '\0')
	{
		free(tetras[i]);
		i++;
	}
	free(tetras[i]);
	close(fd);
	return (0);
}