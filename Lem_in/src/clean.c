/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 13:22:37 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/15 18:23:44 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lines_free(t_line **lines)
{
	t_line	*delete;
	t_line	*current;

	current = (*lines);
	while (current)
	{
		delete = current;
		current = current->next;
		free(delete->content);
		free(delete);
	}
	(*lines) = NULL;
}

void	lem_in_free(t_lem_in **lem_in)
{
	if (lem_in && *lem_in)
	{
		turns_free(&((*lem_in)->turns));
		locations_free(&((*lem_in)->locations));
		paths_free(&((*lem_in)->paths));
		links_free(&((*lem_in)->links));
		rooms_free(&((*lem_in)->rooms));
		free((*lem_in));
		(*lem_in) = NULL;
	}
}
