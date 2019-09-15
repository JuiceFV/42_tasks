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

#include "fillit.h"

static void	convert2tetra(char const *tetr_tmp, t_tetra *inp)
{
	int c[5];

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
					c[3] = c[0];
					c[4] = c[1];
					c[1]++;
					continue ;
				}
				(*inp).x[c[2] - 1] = c[1] - c[4];
				(*inp).y[c[2] - 1] = c[0] - c[3];
			}
			c[1]++;
		}
		c[0]++;
	}
}

char		*ft_strjoin_free(char *s1, char const *s2)
{
	char	*tmp;
	char	*out;
	char	*tmp_s1;

	tmp_s1 = s1;
	if (!s1 && !s2)
		return (NULL);
	tmp = ft_strnew((s1 ? ft_strlen(s1) : 0) + (s2 ? ft_strlen(s2) : 0));
	if ((out = tmp))
	{
		if (s1)
			while (*s1)
				*tmp++ = *s1++;
		if (s2)
			while (*s2)
				*tmp++ = *s2++;
		*tmp = '\0';
	}
	free(tmp_s1);
	return (out);
}

static char	*read_lines(int fd, char **line)
{
	char	*tetr_tmp;
	int		ret;
	int		i;
	char	buff[6];

	i = 0;
	tetr_tmp = ft_strnew(0);
	while (i < 4 && (ret = read(fd, buff, 5)) > 0)
	{
		if (ret == -1)
			return (NULL);
		buff[5] = '\0';
		if (!(*line = ft_strjoin_free(*line, buff)))
			return (NULL);
		buff[4] = '\0';
		if (!(tetr_tmp = ft_strjoin_free(tetr_tmp, buff)))
			return (NULL);
		i++;
	}
	ft_bzero(buff, 6);
	if ((ret = read(fd, buff, 1)) == -1 || (ret == 1 && buff[0] != '\n'))
		return (NULL);
	if (!(*line = ft_strjoin_free(*line, buff)))
		return (NULL);
	return (tetr_tmp);
}

static int	read_file(int fd, t_tetra tetras[27], char **line)
{
	int		j;
	char	*tetr_tmp;

	j = 0;
	while (1)
	{
		if (!(tetr_tmp = read_lines(fd, line)))
			return (-1);
		if (*tetr_tmp == '\0')
			break ;
		convert2tetra(tetr_tmp, &(tetras[j]));
		if (counts_hecker(tetr_tmp) != 0)
			return (-1);
		free(tetr_tmp);
		tetras[j].letter = 65 + j;
		tetras[j++].end = 0;
	}
	free(tetr_tmp);
	if (j == 0 || (j) * 5 - 1 != count_nl(*line))
		return (-1);
	tetras[j].end = 1;
	return (0);
}

int			read_fillit(int fd, t_tetra tetras[27])
{
	char *line;

	line = ft_strnew(0);
	if (read_file(fd, tetras, &line) == -1)
		return (-1);
	free(line);
	return (0);
}
