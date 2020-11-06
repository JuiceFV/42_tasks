/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_location.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:06:13 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/19 19:18:14 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_location	*turn_create_location(int ant_number, t_room *room)
{
	t_location	*location;

	if (!(location = (t_location *)ft_memalloc(sizeof(t_location))))
		terminate("ERROR");
	location->ant_number = ant_number;
	location->room = room;
	location->next = NULL;
	return (location);
}

void		turn_add_location(t_lem_in *lem_in, t_location *location)
{
	t_location	*previous;
	t_location	*current;

	previous = NULL;
	current = lem_in->locations;
	if (current)
	{
		while (current && location->ant_number > current->ant_number)
		{
			previous = current;
			current = current->next;
		}
		if (!previous)
			lem_in->locations = location;
		else
			previous->next = location;
		location->next = current;
	}
	else
		lem_in->locations = location;
}
