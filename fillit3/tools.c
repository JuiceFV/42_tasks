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

#include "includes/fillit.h"

t_tetra		*fill_tetras(void)
{
	t_tetra *a;

	a = (t_tetra *)malloc(sizeof(t_tetra));
	return (a);
}

void		fill_field(int field[104][104])
{
	int i;
	int j;

	i = 0;
	while (i < 104)
	{
		j = 0;
		while (j < 104)
		{
			field[i][j] = 0;
			j++;
		}
		i++;
	}
}

void		print_field(int field[104][104], int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(field[i][j] ? (char)field[i][j] : '.');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}