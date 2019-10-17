/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:29:05 by cspider           #+#    #+#             */
/*   Updated: 2019/10/17 16:29:07 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	special_median_b(t_ps_stack *b)
{
	t_ps_node *tmp;
	int		arr[7];
	int		i;
	int		j[2];

	tmp = b->begin;
	i = 0;
	while (tmp != b->els[b->top])
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] > arr[j[1]])
			{
				arr[6] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[6];
			}
	}
	return ((!b->els[b->top]) ? arr[2] : arr[1]);
}

int		deal_lower_b(t_ps_stack *b, char *cmnds, int med, int count[2])
{
	int		skips;
	t_ps_node *tmp;

	skips = 0;
	tmp = b->begin;
	while (tmp != b->els[b->top] && tmp->value <= med)
	{
		skips++;
		tmp = tmp->next;
	}
	if (tmp == b->els[b->top])
		return (0);
	count[0] += skips;
	while (skips--)
	{
		rotate(&b->begin, &b->end);
		ft_strcat(cmnds, "rb\n");
	}
	return (1);
}

void	split_round_median_b(t_ps_stack *a, t_ps_stack *b, int med, char *cmnds)
{
	int		count[2];

	count[0] = 0;
	count[1] = 0;
	while (b->begin != b->els[b->top])
	{
		if (b->begin->value > med)
		{
			push(&b->begin, &a->begin, &a->end);
			ft_strcat(cmnds, "pa\n");
		}
		else if (!(deal_lower_b(b, cmnds, med, count)))
			break ;
	}
	while (b->els[b->top] && --count[0] >= 0)
	{
		rev_rotate(&b->begin, &b->end);
		ft_strcat(cmnds, "rrb\n");
	}
}

void	three_caseb(t_ps_stack *a, char *tmp)
{
	while (!(a->begin->next->value > a->begin->next->next->value
	&& a->begin->value > a->begin->next->next->value))
	{
		if (a->begin->next->value < a->begin->next->next->value
		&& a->begin->next->value < a->begin->value)
		{
			rev_rotate(&a->begin, &a->end);
			ft_strcat(tmp, "rrb\n");
		}
		else
		{
			rotate(&a->begin, &a->end);
			ft_strcat(tmp, "rb\n");
		}
	}
	if (!(a->begin->next->value > a->begin->value))
		return ;
	swap(&a->begin);
	ft_strcat(tmp, "sb\n");
}

void	sort_b(t_ps_stack *b, int count, char *tmp)
{
	if (b->top)
		b->top--;
	if (count == 1 || !count)
		return ;
	if (count == 2)
	{
		if (b->begin->next && b->begin->next->value > b->begin->value)
		{
			swap(&b->begin);
			ft_strcat(tmp, "sb\n");
		}
		return ;
	}
	three_caseb(b, tmp);
}
