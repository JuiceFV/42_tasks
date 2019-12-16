/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <olongbot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:23:09 by olongbot          #+#    #+#             */
/*   Updated: 2019/11/08 19:01:12 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_lenght(t_ps_stack *s)
{
	t_ps_node	*tmp;
	int			count;

	tmp = s->begin;
	count = 0;
	while (tmp && ++count)
		tmp = tmp->next;
	return (count);
}

void	fill_num_pos(t_ps_stack *a)
{
	int			count;
	int			i;
	t_ps_node	*min;
	t_ps_node	*tmp;

	i = 0;
	count = stack_lenght(a);
	while (i < count)
	{
		min = a->begin;
		while (min->order_num != -1)
			min = min->next;
		tmp = min;
		while (tmp != NULL)
		{
			if (tmp->value < min->value && tmp->order_num == -1)
				min = tmp;
			tmp = tmp->next;
		}
		min->order_num = i + 1;
		i++;
	}
}

int		print_num(int i, char a)
{
	while (i)
	{
		ft_putchar(a);
		i--;
	}
	return (1);
}

void	print_stacks(t_ps_stack *a, t_ps_stack *b)
{
	int				i;
	t_ps_node		*tmp1;
	t_ps_node		*tmp2;
	int				max;
	int				tmp;

	max = stack_lenght(a) + stack_lenght(b) + 2;
	tmp1 = a->begin;
	tmp2 = b->begin;
	i = 0;
	while (tmp1 != NULL || tmp2 != NULL)
	{
		tmp = ((max * 2) - ((i >= max - stack_lenght(a) && tmp1 != NULL) ?
	tmp1->order_num : 0) - ((i >= max - stack_lenght(b) && tmp2 != NULL) ?
	tmp2->order_num : 0));
		if (i >= max - stack_lenght(a) && tmp1 != NULL)
			if (print_num(tmp1->order_num, '-'))
				tmp1 = tmp1->next;
		print_num(tmp, ' ');
		if (i >= max - stack_lenght(b) && tmp2 != NULL)
			if (print_num(tmp2->order_num, '+'))
				tmp2 = tmp2->next;
		ft_putchar('\n');
		i++;
	}
}
