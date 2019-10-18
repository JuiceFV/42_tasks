/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:32:54 by cspider           #+#    #+#             */
/*   Updated: 2019/10/17 14:46:19 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	stack_const(t_ps_stack *a, t_ps_stack *b, int argc)
{
	a->argc = argc;
	b->argc = argc;
	a->top = 0;
	b->top = 0;
	a->els[a->top] = NULL;
	b->els[a->top] = NULL;
}

void			free_all(t_ps_stack *a, t_list *cmnd)
{
	t_ps_node	*tmp;
	t_list		*tmp_a;

	while (a->begin)
	{
		tmp = a->begin;
		a->begin = a->begin->next;
		free(tmp);
	}
	while (cmnd)
	{
		tmp_a = cmnd;
		free(cmnd->content);
		cmnd = cmnd->next;
		free(tmp_a);
	}
	free(a->els);
}

int				main(int argc, char **argv)
{
	t_ps_stack	a;
	t_ps_stack	b;
	t_list		*cmnd;

	if (argc >= 2)
	{
		if (!create_stack(&a, &b, argv, argc))
		{
			ft_dprintf(2, "Error\n");
			return (-1);
		}
		if (!(a.els = (t_ps_node **)malloc(sizeof(t_ps_node*) * argc)) ||
		!(b.els = (t_ps_node **)malloc(sizeof(t_ps_node*) * argc)))
			return (-1);
		stack_const(&a, &b, argc);
		cmnd = solver(&a, &b);
		while (cmnd != NULL)
		{
			ft_putstr((char *)cmnd->content);
			cmnd = cmnd->next;
		}
		free(b.els);
		free_all(&a, cmnd);
	}
	return (0);
}
