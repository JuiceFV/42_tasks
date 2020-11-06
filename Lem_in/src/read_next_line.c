/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:07:46 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/21 16:17:27 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_line	*create_line(char *content)
{
	t_line *line;

	while (!(line = (t_line *)ft_memalloc(sizeof(t_line))))
		terminate("ERROR");
	line->content = content;
	line->next = NULL;
	return (line);
}

static void		add_line(t_line **lines, t_line *line)
{
	t_line *current;

	if (lines && *lines)
	{
		current = *lines;
		while (current->next)
			current = current->next;
		current->next = line;
	}
	else if (lines)
		*lines = line;
}

t_line			*read_next_line(t_line **lines)
{
	t_line	*line;
	char	*content;
	ssize_t	size;

	line = NULL;
	if ((size = get_next_line(0, &content)) > 0)
		add_line(lines, (line = create_line(content)));
	if (size == -1)
		terminate("ERROR");
	return (line);
}
