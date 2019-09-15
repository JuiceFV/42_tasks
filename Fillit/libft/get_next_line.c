/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <myxaosa@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:07:56 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/08 22:52:09 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		core(char **line, char **save)
{
	char	*tmp;
	char	*ptr;

	if (save == NULL)
		return (-1);
	if (!*save || **save == '\0')
		return (0);
	if (ft_strchr(*save, '\n'))
	{
		ptr = ft_strchr(*save, '\n');
		tmp = ft_strdup(ptr + 1);
		*ptr = '\0';
		*line = ft_strdup(*save);
		free(*save);
		*save = tmp;
	}
	else
	{
		*line = ft_strdup(*save);
		free(*save);
		*save = ft_strnew(1);
	}
	return (1);
}

static int		twenty_lines_not_enough(char **save, char **tmp)
{
	if (ft_strchr(*save, '\n'))
		return (1);
	*tmp = *save;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *save[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || fd > MAX_FD || !line)
		return (-1);
	tmp = "\0";
	if (save[fd])
		if (twenty_lines_not_enough(&save[fd], &tmp))
			return (core(line, &save[fd]));
	while (1)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[ret] = '\0';
		if (ret == 0)
			return (core(line, &save[fd]));
		tmp = ft_strjoin(tmp, buff);
		free(save[fd]);
		save[fd] = tmp;
		if (ft_strchr(save[fd], '\n'))
			return (core(line, &save[fd]));
	}
}
