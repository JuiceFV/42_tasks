/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:49:20 by cspider           #+#    #+#             */
/*   Updated: 2019/10/24 13:08:31 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_res(t_ps_stack *a, t_ps_stack *b, int ok)
{
	t_ps_node *tmp;

	while (a->begin)
	{
		tmp = a->begin;
		a->begin = a->begin->next;
		free(tmp);
	}
	while (b->begin)
	{
		tmp = b->begin;
		b->begin = tmp->next;
		free(tmp);
	}
	if (ok)
		ft_putstr("OK\n");
	if (!ok)
		ft_putstr("KO\n");
	exit(1);
}

int		check_a(t_ps_stack *a)
{
	t_ps_node	*tmp;

	tmp = a->begin;
	while (tmp->next != NULL)
	{
		if (tmp->next->value < tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	checker(t_ps_stack *a, t_ps_stack *b, char **l)
{
	if (!ft_strcmp(*l, "sa") || !ft_strcmp(*l, "sb") ||
		!ft_strcmp(*l, "ss"))
		swapper(*l, a, b);
	else if (!ft_strcmp(*l, "pa"))
		push(&b->begin, &a->begin, &a->end);
	else if (!ft_strcmp(*l, "pb"))
		push(&a->begin, &b->begin, &b->end);
	else if (!ft_strcmp(*l, "ra") || !ft_strcmp(*l, "rb") ||
			!ft_strcmp(*l, "rr"))
		rotater(*l, a, b);
	else if (!ft_strcmp(*l, "rra") || !ft_strcmp(*l, "rrb") ||
				!ft_strcmp(*l, "rrr"))
		rev_rotater(*l, a, b);
	else
		print_res(a, b, 0);
}

int		main(int argc, char **argv)
{
	t_ps_stack	a;
	t_ps_stack	b;
	char		*l;

	if (argc >= 2)
	{
		if (!create_stack(&a, &b, argv, argc))
			return (-1);
		while (get_next_line(0, &l) > 0)
		{
			checker(&a, &b, &l);
			free(l);
		}
		(!check_a(&a) || b.begin) ? print_res(&a, &b, 0) : 0;
		print_res(&a, &b, 1);
	}
	return (0);
}
