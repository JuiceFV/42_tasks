/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:12:55 by cspider           #+#    #+#             */
/*   Updated: 2019/09/06 15:45:08 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	line_append(char **str, char **line)
{
	int		length;
	char	*temp;

	length = 0;
	while ((*str)[length] != '\n' && (*str)[length] != '\0')
		length++;
	if ((*str)[length] == '\n')
	{
		*line = ft_strsub(*str, 0, length);
		temp = ft_strdup(&((*str)[length + 1]));
		free(*str);
		*str = temp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

static int	get_result(char **str, char **line, int result, int fd)
{
	if (result < 0)
		return (-1);
	else if (result == 0 && str[fd] == NULL)
		return (0);
	else
		return (line_append(&str[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	int			result;
	static char *str[FD_SIZE];
	char		buff[BUFF_SIZE + 1];
	char		*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((result = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[result] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (get_result(str, line, result, fd));
}
