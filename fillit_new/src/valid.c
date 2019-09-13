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

int		connections(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 16)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 16 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 4) < 16 && str[i + 4] == '#')
				block++;
			if ((i - 4) >= 0 && str[i - 4] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

int		counts_hecker(char *str)
{
	int i;
	int blocks;

	i = 0;
	blocks = 0;
	while (i < 16)
	{
		if (!(str[i] == '#' || str[i] == '.'))
			return (1);
		if (str[i] == '#' && ++blocks > 4)
			return (2);
		i++;
	}
	if (!connections(str))
		return (4);
	return (0);
}

int		count_nl(char *s)
{
	int out;

	out = 0;
	while (*s != '\0')
	{
		if (*s == '\n')
			out++;
		s++;
	}
	return (out);
}
