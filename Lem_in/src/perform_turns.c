/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_turns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:07:32 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/20 12:03:02 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		calculate_diff(t_lem_in *lem_in, t_path *path)
{
	int		diff;
	t_path	*tmp;

	diff = 0;
	tmp = lem_in->paths;
	while (tmp != path)
	{
		diff += path->length - tmp->length;
		tmp = tmp->next;
	}
	return (diff);
}

static void		move_ants_along_path(t_lem_in *lem_in, t_path *path)
{
	t_link	*link;

	link = path->head;
	while (link->next)
		link = link->next;
	while (link)
	{
		if (link->start->ant_number != -1 && link->end == lem_in->end)
		{
			turn_add_location(lem_in,
				turn_create_location(link->start->ant_number, link->end));
			link->start->ant_number = -1;
			lem_in->ants_end++;
		}
		else if (link->start->ant_number != -1)
		{
			turn_add_location(lem_in,
				turn_create_location(link->start->ant_number, link->end));
			link->end->ant_number = link->start->ant_number;
			link->start->ant_number = -1;
		}
		link = link->prev;
	}
}

static void		move_ant_from_start(t_lem_in *lem_in, t_path *path)
{
	if (path->head->end == lem_in->end)
	{
		lem_in->ants_start--;
		lem_in->ants_end++;
		turn_add_location(lem_in,
			turn_create_location(++(lem_in->ant_number), path->head->end));
	}
	else
	{
		lem_in->ants_start--;
		path->head->end->ant_number = ++(lem_in->ant_number);
		turn_add_location(lem_in,
			turn_create_location(path->head->end->ant_number, path->head->end));
	}
}

static void		move_ants_from_start(t_lem_in *lem_in)
{
	t_path	*path;

	path = lem_in->paths;
	while (path && lem_in->ants_start)
	{
		if (lem_in->ants_start > calculate_diff(lem_in, path))
			move_ant_from_start(lem_in, path);
		path = path->next;
	}
}

void			perform_turns(t_lem_in *lem_in)
{
	t_path	*path;

	while (lem_in->ants_start || lem_in->ant_number != lem_in->ants_end)
	{
		path = lem_in->paths;
		while (path)
		{
			move_ants_along_path(lem_in, path);
			path = path->next;
		}
		move_ants_from_start(lem_in);
		print_locations(lem_in);
		locations_free(&(lem_in->locations));
		lem_in->locations = NULL;
	}
}
