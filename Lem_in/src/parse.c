/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:05:35 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/25 21:35:56 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_lem_in	*init_lem_in(void)
{
	t_lem_in *lem_in;

	if (!(lem_in = (t_lem_in *)ft_memalloc(sizeof(t_lem_in))))
		terminate("ERROR");
	lem_in->ants_start = 0;
	lem_in->ants_end = 0;
	lem_in->ant_number = 0;
	lem_in->rooms = NULL;
	lem_in->start = NULL;
	lem_in->end = NULL;
	lem_in->links = NULL;
	lem_in->bfs_level = 0;
	lem_in->paths = NULL;
	lem_in->locations = NULL;
	lem_in->turns = NULL;
	return (lem_in);
}

t_lem_in		*parse(t_line **lines)
{
	t_lem_in	*lem_in;
	t_line		*current;

	current = NULL;
	lem_in = init_lem_in();
	parse_ants(lem_in, &current, lines);
	parse_rooms(lem_in, &current, lines);
	if (!lem_in->start || !lem_in->end)
		terminate("ERROR");
	parse_links(lem_in, &current, lines);
	if (!lem_in->links)
		terminate("ERROR");
	return (lem_in);
}

void			parse_ants(t_lem_in *lem_in, t_line **current, t_line **lines)
{
	if (*current || ((*current) = read_next_line(lines)))
	{
		if (ft_isint((*current)->content, 1))
		{
			lem_in->ants_start = ft_atoi((*current)->content);
			(*current) = NULL;
			if (lem_in->ants_start <= 0)
				terminate("ERROR");
		}
		else
			terminate("ERROR");
	}
}
