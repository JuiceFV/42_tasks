/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 14:24:34 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/17 15:45:23 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_lines(t_line *lines)
{
	t_line		*current;

	current = lines;
	while (current)
	{
		ft_putendl(current->content);
		current = current->next;
	}
}

void		print_locations(t_lem_in *lem_in)
{
	t_location	*locat;

	locat = lem_in->locations;
	while (locat)
	{
		if (locat != lem_in->locations)
			ft_putchar(' ');
		ft_putchar('L');
		ft_putnbr(locat->ant_number);
		ft_putchar('-');
		ft_putstr(locat->room->name);
		locat = locat->next;
	}
	ft_putendl(NULL);
}

int			main(void)
{
	t_line		*input;
	t_lem_in	*lem_in;

	input = NULL;
	lem_in = parse(&input);
	bfs(lem_in);
	if (lem_in->end->bfs_level == -1)
		terminate("ERROR");
	delete_useless_links(lem_in);
	align_links(lem_in);
	count_io_links(lem_in);
	delete_dead_ends(lem_in);
	delete_input_forks(lem_in);
	delete_output_forks(lem_in);
	print_lines(input);
	ft_putendl(NULL);
	form_paths(lem_in);
	perform_turns(lem_in);
	lines_free(&input);
	lem_in_free(&lem_in);
	return (0);
}
