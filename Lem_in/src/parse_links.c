/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:25:44 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/15 17:55:42 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_link(t_lem_in *lem_in, t_link *link)
{
	t_link	*current;

	current = lem_in->links;
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = link;
	}
	else
		lem_in->links = link;
}

static t_link	*init_link(t_room *start, t_room *end)
{
	t_link	*link;

	if (!(link = (t_link *)ft_memalloc(sizeof(t_link))))
		terminate("ERROR");
	link->start = start;
	link->end = end;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

static t_link	*create_link(t_lem_in *lem_in, char *str)
{
	char	*dash;
	char	*start_name;
	char	*end_name;
	t_room	*start_room;
	t_room	*end_room;

	dash = str;
	while ((dash = ft_strchr(dash + 1, '-')))
	{
		if (!(start_name = ft_strsub(str, 0, dash - str)))
			terminate("ERROR");
		if (!(end_name = ft_strsub(dash + 1, 0, ft_strlen(dash + 1))))
			terminate("ERROR");
		start_room = find_room(lem_in, start_name);
		end_room = find_room(lem_in, end_name);
		free(start_name);
		free(end_name);
		if (start_room && end_room)
			return (init_link(start_room, end_room));
	}
	return (NULL);
}

void			parse_links(t_lem_in *lem_in, t_line **current, t_line **lines)
{
	t_link	*link;

	while ((*current) || ((*current) = read_next_line(lines)))
	{
		if (!is_comment((*current)->content)
			&& !is_command((*current)->content))
		{
			if (!(link = create_link(lem_in, (*current)->content)))
				terminate("ERROR");
			add_link(lem_in, link);
			validate_link(lem_in, link);
		}
		(*current) = NULL;
	}
}
