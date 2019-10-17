/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slover.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:03:13 by cspider           #+#    #+#             */
/*   Updated: 2019/10/17 17:30:41 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		split_a(t_ps_stack *a, t_ps_stack *b, t_list **cmnd)
{
	int		count;
	long	median;
	char	tmp[a->argc * 4];

	tmp[0] = '\0';
	count = get_count(a);
	median = 2147483648;
	if (count <= 11 && count > 2)
		median = special_median_a(a);
	else if (count > 11)
		median = get_true_median(a);
	if (median != 2147483648)
		split_round_median_a(a, b, (int)median, tmp);
	else
		sort_a(a, count, tmp);
	if (tmp[0])
		ft_lstadd_end(cmnd, ft_lstnew_str(tmp));
	if (median == 2147483648)
		a->els[++(a->top)] = a->begin;
	return ((median == 2147483648) ? 1 : 0);
}

int		sorted(t_ps_stack *a)
{
	t_ps_node	*tmp;

	tmp = a->begin;
	while (tmp)
	{
		if (tmp->next && tmp->next->value < tmp->value)
			return (0);
		tmp = tmp->next;
		if (tmp == a->els[a->top])
			break ;
	}
	return (1);
}

void	push_b(t_ps_stack *b, t_ps_stack *a, int count, char *tmp)
{
	int i;

	i = 0;
	count = (count == -1) ? 3 : count;
	while (i++ < count)
	{
		push(&b->begin, &a->begin, &a->end);
		ft_strcat(tmp, "pa\n");
	}
}

void	b_to_a(t_ps_stack *a, t_ps_stack *b, t_list **cmnd)
{
	int		count;
	long	median;
	char	tmp[a->argc * 4];

	tmp[0] = '\0';
	count = get_count(b);
	median = 2147483648;
	if (count <= 6 && count > 2)
		median = special_median_b(b);
	else if (count > 6)
		median = get_true_median(b);
	if (median != 2147483648)
		split_round_median_b(a, b, (int)median, tmp);
	else
		sort_b(b, count, tmp);
	if (median == 2147483648)
		push_b(b, a, count, tmp);
	if (tmp[0])
		ft_lstadd_end(cmnd, ft_lstnew_str(tmp));
}

t_list	*solver(t_ps_stack *a, t_ps_stack *b)
{
	t_list	*cmnd;
	int		ret;
	int		sort;

	cmnd = ft_lstnew((void *)"\0", 1);
	while (!(sort = sorted(a)) || b->begin != NULL)
	{
		if (!sort)
		{
			while ((ret = split_a(a, b, &cmnd)) == 0)
				;
			if (ret == -1)
				exit(1);
		}
		else
			a->els[++(a->top)] = a->begin;
		b_to_a(a, b, &cmnd);
	}
	return (cmnd);
}
