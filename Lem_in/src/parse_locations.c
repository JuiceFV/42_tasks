/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_locations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:36:17 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/13 17:26:35 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

static t_location	*create_location(t_lem_in *lem_in, char *str)
{
	t_location	*location;
	char		*dash;
	char		*ant_number;
	char		*room_name;

	if (!(location = (t_location *)ft_memalloc(sizeof(t_location))))
		terminate("ERROR");
	dash = ft_strchr(str, '-');
	if (!(ant_number = ft_strsub(str, 1, dash - str - 1)))
		terminate("ERROR");
	if (!(room_name = ft_strsub(dash + 1, 0, ft_strlen(dash + 1))))
		terminate("ERROR");
	location->ant_number = ft_atoi(ant_number);
	location->room = find_room(lem_in, room_name);
	location->next = NULL;
	free(ant_number);
	free(room_name);
	return (location);
}

static void			add_location(t_location **locations, t_location *location)
{
	t_location	*current;

	current = (*locations);
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = location;
	}
	else
		(*locations) = location;
}

t_location			*parse_locations(t_lem_in *lem_in, char *str)
{
	t_location	*locations;
	size_t		i;
	char		**strsplit;

	i = 0;
	locations = NULL;
	if (!(strsplit = ft_strsplit(str, ' ')))
		terminate("ERROR");
	while (strsplit[i])
	{
		if (!is_location(lem_in, strsplit[i]))
			terminate("ERROR");
		add_location(&locations, create_location(lem_in, strsplit[i]));
		i++;
	}
	ft_strsplit_free(&strsplit);
	return (locations);
}
