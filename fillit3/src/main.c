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

#include "includes/fillit.h"

static int	print_error(void)
{
	ft_putstr("error\n");
	return (1);
}

static int		check_place(int x, int y,
							t_tetra tetra, int field[104][104], int size)
{
	if (field[y][x] != 0)
		return (0);
	if (field[y + tetra.y[0]][x + tetra.x[0]] != 0 ||
		x + tetra.x[0] >= size || y + tetra.y[0] >= size)
		return (0);
	if (field[y + tetra.y[1]][x + tetra.x[1]] != 0 ||
		x + tetra.x[1] >= size || y + tetra.y[1] >= size)
		return (0);
	if (field[y + tetra.y[2]][x + tetra.x[2]] != 0 ||
		x + tetra.x[2] >= size || y + tetra.y[2] >= size)
		return (0);
	return (1);
}

static void		tetra_set(int x, int y, t_tetra tetra, int field[104][104])
{
	field[y][x] = tetra.letter;
	field[y + tetra.y[0]][x + tetra.x[0]] = tetra.letter;
	field[y + tetra.y[1]][x + tetra.x[1]] = tetra.letter;
	field[y + tetra.y[2]][x + tetra.x[2]] = tetra.letter;
}

static void		tetra_unset(int x, int y, t_tetra tetra, int field[104][104])
{
	field[y][x] = 0;
	field[y + tetra.y[0]][x + tetra.x[0]] = 0;
	field[y + tetra.y[1]][x + tetra.x[1]] = 0;
	field[y + tetra.y[2]][x + tetra.x[2]] = 0;
}

static int		solved(int const *tetras_used)
{
	int i;

	i = 0;
	while (tetras_used[i] != -1)
	{
		if (tetras_used[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

static int		solve(int *tetras_used, int field[104][104],
						t_tetra **tetras, int size)
{
	int i;
	int x;
	int y;

	i = 0;
	if (solved(tetras_used))
		return (1);
	while ((*tetras)[i].end != 1)
	{
		y = 0;
		while (y < size)
		{
			x = 0;
			while (x < size)
			{
				if (check_place(x, y, (*tetras)[i], field, size)
					&& tetras_used[i] == 0)
				{
					tetra_set(x, y, (*tetras)[i], field);
					tetras_used[i] = 1;
					if (solve(tetras_used, field, tetras, size))
						return (1);
					tetras_used[i] = 0;
					tetra_unset(x, y, (*tetras)[i], field);
				}
				x++;
			}
			y++;
		}
		i++;
	}
	return (0);
}

static int		solve_for_all(int field[104][104], t_tetra **tetras)
{
	int i;
	int tetras_used[27];

	i = 0;
	while ((*tetras)[i].end != 1)
		tetras_used[i++] = 0;
	tetras_used[i] = -1;
	i = 2;
	while (solve(tetras_used, field, tetras, i) == 0 && i < 104)
		i++;
	return (i);
}

int				main(int argc, char **argv)
{
	int		fd;
	int		field[104][104];
	int		i;
	t_tetra	**tetras;

	fill_field(field);
	i = -1;
	tetras = (t_tetra **)malloc(sizeof(t_tetra*) * 26);
	while (i++ < 27)
		tetras[i] = fill_tetras();
	if (argc != 2)
	{
		ft_putstr("usage: fillit file.fillit\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (print_error());
	read_fillit(fd, &tetras);
	i = solve_for_all(field, tetras);
	print_field(field, i);
	close(fd);
	return (0);
}
