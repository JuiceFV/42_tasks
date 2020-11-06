/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_output_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:46:19 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/23 23:35:18 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		path_len(t_lem_in *lem_in, t_link *link, int len)
{
	if (link->end == lem_in->end)
		return (len + 1);
	if (link->end->input_links > 1)
		return (len + 1);
	return (path_len(lem_in, find_link(lem_in, link->end, NULL), len + 1));
}

static void		delete_other_output_links(t_lem_in *lem_in, t_link *link)
{
	t_room	*start;
	t_link	*current;
	t_link	*delete;

	start = link->start;
	current = lem_in->links;
	while (current)
	{
		delete = current;
		current = current->next;
		if (delete->start == start && delete != link)
			delete_link(lem_in, delete);
	}
}

static void		delete_output_fork(t_lem_in *lem_in, t_room *room)
{
	t_link	*link;
	t_link	*link_to_min_path;
	int		min_path_len;
	int		cur_path_len;

	min_path_len = FT_INT_MAX;
	link_to_min_path = NULL;
	link = lem_in->links;
	while (link && room->output_links > 1)
	{
		if (link->start == room)
		{
			if (min_path_len > (cur_path_len = path_len(lem_in, link, 0)))
			{
				min_path_len = cur_path_len;
				link_to_min_path = link;
			}
		}
		link = link->next;
	}
	delete_other_output_links(lem_in, link_to_min_path);
	delete_dead_ends(lem_in);
}

void			delete_output_forks(t_lem_in *lem_in)
{
	int		bfs_level;
	t_room	*room;

	bfs_level = lem_in->bfs_level;
	while (bfs_level > 0)
	{
		room = lem_in->rooms;
		while (room)
		{
			if (room->bfs_level == bfs_level
				&& room->output_links > 1)
				delete_output_fork(lem_in, room);
			room = room->next;
		}
		bfs_level--;
	}
}
