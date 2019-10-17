/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:59:40 by cspider           #+#    #+#             */
/*   Updated: 2019/10/17 17:25:12 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_count(t_ps_stack *s)
{
	int			count;
	t_ps_node	*tmp;

	tmp = s->begin;
	count = 0;
	while (tmp != s->els[s->top] && count < 12)
	{
		count++;
		tmp = tmp->next;
	}
	if (!s->els[s->top] && count == 3)
		return (-1);
	return (count);
}

int	get_true_median(t_ps_stack *a)
{
	t_ps_node	*tmp;
	int			arr[a->argc + 1];
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
				arr[a->argc] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[a->argc];
			}
	}
	return (arr[i / 2]);
}
