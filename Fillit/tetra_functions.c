/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <myxaosa@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:07:56 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/04 23:45:33 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		print_error(void)
{
	ft_putstr("error\n");
	return (1);
}

int		check_place(int *xy, t_tetra tetra, int field[104][104], int size)
{
	int x;
	int y;

	x = xy[0];
	y = xy[1];
	if (y + tetra.y[2] >= size || x + tetra.x[2] >= size ||
		y + tetra.y[2] < 0 || x + tetra.x[2] < 0 ||
		y + tetra.y[1] >= size || x + tetra.x[1] >= size ||
		y + tetra.y[1] < 0 || x + tetra.x[1] < 0 ||
		y + tetra.y[0] >= size || x + tetra.x[0] >= size ||
		y + tetra.y[0] < 0 || x + tetra.x[0] < 0)
		return (0);
	if (field[y + tetra.y[1]][x + tetra.x[1]] != 0 ||
		field[y + tetra.y[2]][x + tetra.x[2]] != 0 ||
		field[y + tetra.y[0]][x + tetra.x[0]] != 0)
		return (0);
	return (1);
}

void	tetra_set(int x, int y, t_tetra tetra, int field[104][104])
{
	field[y][x] = tetra.letter;
	field[y + tetra.y[0]][x + tetra.x[0]] = tetra.letter;
	field[y + tetra.y[1]][x + tetra.x[1]] = tetra.letter;
	field[y + tetra.y[2]][x + tetra.x[2]] = tetra.letter;
}

void	tetra_unset(int x, int y, t_tetra tetra, int field[104][104])
{
	field[y][x] = 0;
	field[y + tetra.y[0]][x + tetra.x[0]] = 0;
	field[y + tetra.y[1]][x + tetra.x[1]] = 0;
	field[y + tetra.y[2]][x + tetra.x[2]] = 0;
}
