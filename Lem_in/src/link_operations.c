/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:59:32 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/23 23:57:43 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_link(t_lem_in *lem_in, t_link *link)
{
	t_link	*previous;
	t_link	*current;

	previous = NULL;
	current = lem_in->links;
	while (current && current != link)
	{
		previous = current;
		current = current->next;
	}
	if (!previous && current)
		lem_in->links = current->next;
	else if (current)
		previous->next = current->next;
	if (link->start->output_links > 0)
		link->start->output_links--;
	if (link->end->input_links > 0)
		link->end->input_links--;
	free(link);
}

t_link	*remove_link(t_lem_in *lem_in, t_link *link)
{
	t_link	*previous;
	t_link	*current;

	previous = NULL;
	current = lem_in->links;
	while (current && current != link)
	{
		previous = current;
		current = current->next;
	}
	if (!previous && current)
		lem_in->links = current->next;
	else if (current)
		previous->next = current->next;
	link->next = NULL;
	return (link);
}

void	delete_useless_links(t_lem_in *lem_in)
{
	t_link	*link;
	t_link	*delete;

	link = lem_in->links;
	while (link)
	{
		delete = link;
		link = link->next;
		if (delete->start->bfs_level == -1
			|| delete->end->bfs_level == -1
			|| delete->start->bfs_level == delete->end->bfs_level)
			delete_link(lem_in, delete);
	}
}

void	delete_dead_ends(t_lem_in *lem_in)
{
	int		has_dead_end;
	t_link	*link;
	t_link	*delete;

	has_dead_end = 1;
	while (has_dead_end)
	{
		has_dead_end = 0;
		link = lem_in->links;
		while (link)
		{
			delete = link;
			link = link->next;
			if ((delete->start != lem_in->start
				&& delete->start->input_links == 0
				&& delete->start->output_links > 0)
				|| (delete->end != lem_in->end
				&& delete->end->input_links > 0
				&& delete->end->output_links == 0))
			{
				delete_link(lem_in, delete);
				has_dead_end = 1;
			}
		}
	}
}

void	align_links(t_lem_in *lem_in)
{
	t_link	*link;

	link = lem_in->links;
	while (link)
	{
		if (link->start->bfs_level > link->end->bfs_level)
			swap_rooms(&link->start, &link->end);
		link = link->next;
	}
}
