/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_input_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 26:57:37 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/25 12:48:34 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		path_has_output_fork(t_lem_in *lem_in, t_link *link)
{
	if (link->start == lem_in->start)
		return (0);
	if (link->start->output_links > 1)
		return (1);
	return (path_has_output_fork(lem_in,
		find_link(lem_in, NULL, link->start)));
}

static void		delete_other_input_links(t_lem_in *lem_in, t_link *link)
{
	t_room	*end;
	t_link	*tmp;
	t_link	*delete;

	end = link->end;
	tmp = lem_in->links;
	while (tmp)
	{
		delete = tmp;
		tmp = tmp->next;
		if (delete->end == end && delete != link)
			delete_link(lem_in, delete);
	}
}

static void		delete_input_fork(t_lem_in *lem_in, t_room *room)
{
	t_link	*link;
	t_link	*delete;

	link = lem_in->links;
	while (link && room->input_links > 1)
	{
		delete = link;
		link = link->next;
		if (delete->end == room)
		{
			if (!path_has_output_fork(lem_in, delete))
				delete_other_input_links(lem_in, delete);
			else
				delete_link(lem_in, delete);
			delete_dead_ends(lem_in);
		}
	}
}

void			delete_input_forks(t_lem_in *lem_in)
{
	int		bfs_level;
	t_room	*room;

	bfs_level = 1;
	while (bfs_level <= lem_in->bfs_level)
	{
		room = lem_in->rooms;
		while (room)
		{
			if (room->bfs_level == bfs_level && room->input_links > 1)
				delete_input_fork(lem_in, room);
			room = room->next;
		}
		bfs_level++;
	}
}
