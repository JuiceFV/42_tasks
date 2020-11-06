/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:26:32 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/20 20:46:57 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path	*create_path(void)
{
	t_path	*path;

	if (!(path = (t_path *)ft_memalloc(sizeof(t_path))))
		terminate("ERROR");
	path->head = NULL;
	path->length = 0;
	path->next = NULL;
	return (path);
}

static void		path_add_link(t_path *path, t_link *link)
{
	t_link	*prev;
	t_link	*current;

	prev = NULL;
	current = path->head;
	if (current)
	{
		while (current)
		{
			prev = current;
			current = current->next;
		}
		link->prev = prev;
		prev->next = link;
	}
	else
		path->head = link;
	path->length++;
}

static void		add_path(t_lem_in *lem_in, t_path *path)
{
	t_path	*prev;
	t_path	*curr;

	prev = NULL;
	curr = lem_in->paths;
	if (curr)
	{
		while (curr && path->length > curr->length)
		{
			prev = curr;
			curr = curr->next;
		}
		if (!prev)
			lem_in->paths = path;
		else
			prev->next = path;
		path->next = curr;
	}
	else
		lem_in->paths = path;
}

void			form_paths(t_lem_in *lem_in)
{
	t_path	*path;
	t_link	*link;

	while (lem_in->links)
	{
		path = create_path();
		link = find_link(lem_in, lem_in->start, NULL);
		path_add_link(path, remove_link(lem_in, link));
		while (link->end != lem_in->end)
		{
			link = find_link(lem_in, link->end, NULL);
			path_add_link(path, remove_link(lem_in, link));
		}
		add_path(lem_in, path);
	}
}
