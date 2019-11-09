/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmnds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:44:25 by cspider           #+#    #+#             */
/*   Updated: 2019/11/09 13:44:27 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapper(char *line, t_ps_stack *a, t_ps_stack *b)
{
	if (!ft_strcmp(line, "sa"))
	{
		swap(&a->begin);
		return ;
	}
	if (!ft_strcmp(line, "sb"))
	{
		swap(&b->begin);
		return ;
	}
	swap(&a->begin);
	swap(&b->begin);
}

void	rotater(char *line, t_ps_stack *a, t_ps_stack *b)
{
	if (!ft_strcmp(line, "ra"))
	{
		rotate(&a->begin, &a->end);
		return ;
	}
	if (!ft_strcmp(line, "rb"))
	{
		rotate(&b->begin, &b->end);
		return ;
	}
	rotate(&a->begin, &a->end);
	rotate(&b->begin, &b->end);
}

void	rev_rotater(char *line, t_ps_stack *a, t_ps_stack *b)
{
	if (!ft_strcmp(line, "rra"))
	{
		rev_rotate(&a->begin, &a->end);
		return ;
	}
	if (!ft_strcmp(line, "rrb"))
	{
		rev_rotate(&b->begin, &b->end);
		return ;
	}
	rev_rotate(&a->begin, &a->end);
	rev_rotate(&b->begin, &b->end);
}
