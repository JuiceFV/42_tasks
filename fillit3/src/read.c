/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <myxaosa@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:07:56 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/04 23:45:33 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

static void		convert2tetra(char const *tetr_tmp, t_tetra *inp)
{
	int c[3];
	int tmp[2];

	c[0] = 0;
	c[2] = -1;
	while (c[0] < 4)
	{
		c[1] = 0;
		while (c[1] < 4)
		{
			if (tetr_tmp[c[1] + (c[0] * 4)] == '#')
			{
				if (++c[2] == 0)
				{
					tmp[0] = c[0];
					tmp[1] = c[1];
					c[1]++;
					continue ;
				}
				(*inp).x[c[2] - 1] = c[1] - tmp[1];
				(*inp).y[c[2] - 1] = c[0] - tmp[0];
			}
			c[1]++;
		}
		c[0]++;
	}
}

static void		read_file(int fd, t_tetra ***tetras, char *line)
{
	int		ret;
	int		j;
	int		i;
	char	*tetr_tmp;

	j = 0;
	ret = 1;
	while (ret > 0)
	{
		i = 0;
		tetr_tmp = ft_strnew(1);
		while ((ret = get_next_line(fd, &line)) > 0 && i <= 4)
		{
			if (i == 4)
				break ;
			tetr_tmp = ft_strjoin(tetr_tmp, line);
			free(line);
			i++;
		}
		convert2tetra(tetr_tmp, &((**tetras)[j]));
		(**tetras)[j].letter = 65 + j;
		(**tetras)[j++].end = 0;
		free(tetr_tmp);
	}
	(**tetras)[j].end = 1;
}

void			read_fillit(int fd, t_tetra ***tetras)
{
	char *line;

	read_file(fd, tetras, line);
}
