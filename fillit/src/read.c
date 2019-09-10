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

static void print_tetras(char **tetras)
{
	int i;
	int j;
	int k;

	i = 0;
	while (tetras[i][0] != '\0')
	{
		k = 0;
		while (k < 4)
		{
			j = 0;
			while (j < 4)
			{
				ft_putchar(tetras[i][j + (k * 4)]);
				j++;
			}
			ft_putstr("\n");
			k++;
		}
		ft_putstr("\n");
		i++;
	}
}

static void fix_tetraminoes_horizontal(char ***t)
{
	int j;
	char *tmp;

	j = 0;
	while ((*t)[j][0] != '\0')
	{
		while ((*t)[j][0] == '.' && (*t)[j][1] == '.' &&
				(*t)[j][2] == '.' && (*t)[j][3] == '.')
		{
			tmp = (*t)[j];
			(*t)[j] = ft_strjoin(&((*t)[j][4]), "....");
			free(tmp);
		}
		j++;
	}
}

static void fix_tetraminoes_vertical(char ***t)
{
	int j;
	char *del;
	char *tmp;

	j = 0;
	while ((*t)[j][0] != '\0')
	{
		while ((*t)[j][0] == '.' && (*t)[j][4] == '.' &&
				(*t)[j][8] == '.' && (*t)[j][12] == '.')
		{
			del = (*t)[j];
			tmp = ft_strnew(16);
			ft_strncpy(&(tmp[0]), &((*t)[j][1]), 4);
			ft_strncpy(&(tmp[4]), &((*t)[j][5]), 4);
			ft_strncpy(&(tmp[8]), &((*t)[j][9]), 4);
			ft_strncpy(&(tmp[12]), &((*t)[j][13]), 4);
			tmp[15] = '.';
			(*t)[j] = tmp;
			free(del);
		}
		j++;
	}
}

static	int validate_input(char **tetras)
{
	int i;
	int j;

	i = 0;
	while (tetras[i][0] != '\0')
	{
		j = 0;
		while (tetras[i][j] != '\0')
		{
			if (tetras[i][j] != '.' && tetras[i][j] != '#')
				return (-1);
			j++;
		}
		if (j != 16)
			return (-1);
		i++;
	}
	if (i > 26) //TODO: check this;
		return (-1);
	return (1);
}

void	*ft_realloc(void *ptr, size_t size)
{
	char	*newptr;

	if (!size && ptr)
	{
		if (!(newptr = (char *)malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (newptr);
	}
	if (!(newptr = (char *)malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(newptr, ptr, size);
		ft_memdel(&ptr);
	}
	return (newptr);
}

static char	**read_file(int fd, char **tetras, char *line)
{
	int ret;
	int j;
	int i;
	char *tetr_tmp;

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
		tetras = (char **)ft_realloc(tetras, sizeof(char *) * (j + 2));
		tetras[j++] = ft_strdup(tetr_tmp);
		free(tetr_tmp);
		if (ret != 0 && *line != '\0')
			return (NULL);
//		free(line);
	}
	tetras[j] = ft_strnew(1);
	if (ret == -1)
		return (NULL);
	return (tetras);
}

char	**read_fillit(int fd)
{
	char *line;
	char **tetras;

	tetras = read_file(fd, tetras, line);
	if (!tetras)
		return (NULL);
	if (validate_input(tetras) != 1)
		return (NULL);
	fix_tetraminoes_horizontal(&tetras);
	fix_tetraminoes_vertical(&tetras);
	print_tetras(tetras);
	return (tetras);
}