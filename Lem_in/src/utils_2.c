/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:27:49 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/25 18:44:53 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*find_link(t_lem_in *lem_in, t_room *start, t_room *end)
{
	t_link	*current;

	current = lem_in->links;
	while (current)
	{
		if (start && current->start == start)
			return (current);
		if (end && current->end == end)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_room	*find_room(t_lem_in *lem_in, char *name)
{
	t_room	*current;

	current = lem_in->rooms;
	while (current)
	{
		if (!ft_strcmp(current->name, name))
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	count_io_links(t_lem_in *lem_in)
{
	t_link *link;

	link = lem_in->links;
	while (link)
	{
		link->start->output_links++;
		link->end->input_links++;
		link = link->next;
	}
}
