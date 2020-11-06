/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:51:23 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/27 14:05:53 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	locations_free(t_location **location)
{
	t_location	*del;

	if (location)
		while ((*location))
		{
			del = (*location);
			(*location) = (*location)->next;
			free(del);
		}
}

void	turns_free(t_turn **turn)
{
	t_turn	*del;

	if (turn)
		while ((*turn))
		{
			del = (*turn);
			(*turn) = (*turn)->next;
			locations_free(&(del->locations));
			free(del);
		}
}

void	links_free(t_link **link)
{
	t_link	*del;

	if (link)
		while ((*link))
		{
			del = (*link);
			(*link) = (*link)->next;
			free(del);
		}
}

void	rooms_free(t_room **room)
{
	t_room	*del;

	if (room)
		while ((*room))
		{
			del = (*room);
			(*room) = (*room)->next;
			free(del->name);
			free(del);
		}
}

void	paths_free(t_path **path)
{
	t_path	*del;

	if (path)
		while ((*path))
		{
			del = (*path);
			(*path) = (*path)->next;
			links_free(&(del->head));
			free(del);
		}
}
