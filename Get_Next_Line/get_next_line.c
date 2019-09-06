/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:12:55 by cspider           #+#    #+#             */
/*   Updated: 2019/09/06 16:37:05 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//append every (single) line into our "line"
static	int	line_append(char **str, char **line)
{
	int		length;
	char	*temp;

	length = 0;
	//count line's length
	while ((*str)[length] != '\n' && (*str)[length] != '\0')
		length++;
	//if last symbol in the line is a "newline"
	if ((*str)[length] == '\n')
	{
		//we save the string into line up to the length found
		*line = ft_strsub(*str, 0, length);
		//we readjust the stored data (**str)
		//by creating a temp string that has
		//the rest data after the "newline"
		temp = ft_strdup(&((*str)[length + 1]));
		//free the stored data to update it to
		//the current address cause we already append
		//a line from it
		free(*str);
		*str = temp;
		//When we find the end of the file
		//we free the memory cause it is not needed
		//anymore
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

//The function reads a file and returns the line
//ending with a newline character from a file descriptor
int			get_next_line(const int fd, char **line)
{
	int			result;
	//a static variable so that whenever the function is called
	//it (the variable) would store the result of the previous 
	//function call
	static char *str[FD_SIZE];
	char		buff[BUFF_SIZE + 1];
	char		*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((result = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[result] = '\0';
		//When function is called at first time
		//we check to see if our (*str) is empty.
		//If it is we allocate memory for it using our buff string
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			//combine each string with other. 
			//We using temp because we are only
			//reading so many bytes at a time
			//decided by our BUFF_SIZE. If we
			//read at each iteration without
			//memory freeing, then we would have
			//memory leaks. So that we can keep
			//track of how much is read and delete
			//the previous stored data.
			temp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = temp;
		}
		//When a "newline" is encountered
		//then loop breaks
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (get_result(str, line, result, fd));
}
