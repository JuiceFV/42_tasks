/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:58:31 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/25 15:38:34 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		validate_room(t_lem_in *lem_in, t_room *room)
{
	t_room	*i;

	i = lem_in->rooms;
	while (i)
	{
		if (room != i && !ft_strcmp(room->name, i->name))
			terminate("ERROR");
		if (room != i && room->x == i->x && room->y == i->y)
			terminate("ERROR");
		i = i->next;
	}
}

void		validate_link(t_lem_in *lem_in, t_link *link)
{
	t_link	*i;

	i = lem_in->links;
	while (i)
	{
		if (link != i &&
			((!ft_strcmp(link->start->name, i->start->name)
			&& !ft_strcmp(link->end->name, i->end->name)) ||
			(!ft_strcmp(link->start->name, i->end->name)
			&& !ft_strcmp(link->end->name, i->start->name))))
			terminate("ERROR");
		i = i->next;
	}
}
