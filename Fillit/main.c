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

#include "fillit.h"

static int		ft_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

static int		solve(int field[104][104], t_tetra tetras[27], int len, int i)
{
	int xy[2];
	int size;

	size = tetras[26].letter;
	if (len == 0)
		return (1);
	xy[1] = -1;
	while (++xy[1] < size && (xy[0] = -1))
	{
		while (++xy[0] < size)
		{
			if (field[xy[1]][xy[0]] == 0 && check_place(xy,
					tetras[i], field, size))
			{
				tetra_set(xy[0], xy[1], tetras[i], field);
				if (solve(field, tetras, len - 1, i + 1))
					return (1);
				tetra_unset(xy[0], xy[1], tetras[i], field);
			}
		}
	}
	return (0);
}

static int		solve_for_all(int field[104][104], t_tetra tetras[27])
{
	int i;
	int solved;
	int len;

	i = 0;
	while (tetras[i].end != 1)
		i++;
	len = i;
	i = ft_sqrt(i * 4);
	while (i < 104)
	{
		tetras[26].letter = i;
		solved = solve(field, tetras, len, 0);
		if (solved == 1)
			break ;
		i++;
	}
	return (i);
}

int				main(int argc, char **argv)
{
	int		fd;
	int		field[104][104];
	int		i;
	t_tetra	tetras[27];

	fill_field(field);
	if (argc != 2)
	{
		ft_putstr("usage: fillit file.fillit\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (print_error());
	if ((read_fillit(fd, tetras)) == -1)
	{
		ft_putstr("error\n");
		return (1);
	}
	i = solve_for_all(field, tetras);
	print_field(field, i);
	close(fd);
	return (0);
}
