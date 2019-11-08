/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <olongbot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:21:47 by olongbot          #+#    #+#             */
/*   Updated: 2019/11/07 18:50:25 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	special_median_a(t_ps_stack *a)
{
	t_ps_node	*tmp;
	int			arr[12];
	int			i;
	int			j[2];

	tmp = a->begin;
	i = 0;
	while (tmp != a->els[a->top])
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] < arr[j[1]])
			{
				arr[11] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[11];
			}
	}
	return ((!a->els[a->top]) ? arr[3] : arr[2]);
}

int		deal_higher_a(t_ps_stack *a, char *cmnds, int med, int *t_rewind)
{
	int			skips;
	t_ps_node	*tmp;

	skips = 0;
	tmp = a->begin;
	while (tmp != a->els[a->top] && tmp->value > med)
	{
		skips++;
		tmp = tmp->next;
	}
	if (tmp == a->els[a->top])
		return (0);
	*t_rewind = *t_rewind + skips;
	while (skips--)
	{
		rotate(&a->begin, &a->end);
		ft_strcat(cmnds, "ra\n");
	}
	return (1);
}

void	split_round_median_a(t_ps_stack *a, t_ps_stack *b, int med, char *cmnds)
{
	int		rewind;

	rewind = 0;
	if (b->begin)
		b->els[++(b->top)] = b->begin;
	while (a->begin != a->els[a->top])
	{
		if (a->begin->value <= med)
		{
			push(&a->begin, &b->begin, &b->end);
			ft_strcat(cmnds, "pb\n");
		}
		else if (!(deal_higher_a(a, cmnds, med, &rewind)))
			break ;
	}
	while (a->els[a->top] && --rewind >= 0)
	{
		rev_rotate(&a->begin, &a->end);
		ft_strcat(cmnds, "rra\n");
	}
}

void	three_case(t_ps_stack *a, char *tmp)
{
	while (!(a->begin->next->value < a->begin->next->next->value
	&& a->begin->value < a->begin->next->next->value))
	{
		if (a->begin->next->value > a->begin->next->next->value
		&& a->begin->next->value > a->begin->value)
		{
			rev_rotate(&a->begin, &a->end);
			ft_strcat(tmp, "rra\n");
		}
		else
		{
			rotate(&a->begin, &a->end);
			ft_strcat(tmp, "ra\n");
		}
	}
	if (!(a->begin->next->value < a->begin->value))
		return ;
	swap(&a->begin);
	ft_strcat(tmp, "sa\n");
}

void	sort_a(t_ps_stack *a, int count, char *tmp)
{
	if (count == 1)
		return ;
	if (count == 2)
	{
		if (a->begin->next->value < a->begin->value)
		{
			swap(&a->begin);
			ft_strcat(tmp, "sa\n");
		}
		return ;
	}
	three_case(a, tmp);
}
