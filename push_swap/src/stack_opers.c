/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:37:04 by cspider           #+#    #+#             */
/*   Updated: 2019/10/24 14:02:12 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stck_append_end(char *str, t_ps_node **back)
{
	t_ps_node	*tmp;
	int			num;

	num = ft_atoi(str);
	if (num < FT_INT_MIN || num > FT_INT_MAX)
		return (0);
	if (*back == NULL)
		return (0);
	if (!(tmp = (t_ps_node *)malloc(sizeof(t_ps_node))))
		return (0);
	tmp->value = num;
	tmp->next = NULL;
	(*back)->next = tmp;
	tmp->prev = *back;
	*back = tmp;
	return (1);
}

int	create_stack(t_ps_stack *a, t_ps_stack *b, char **v, int c)
{
	int			i;
	t_ps_node	*tmp;
	int			is_single;

	i = 1;
	is_single = 0;
	if (c - i == 1)
	{
		c = ft_number_of_words(v[i], ' ');
		v = ft_strsplit(v[i], ' ');
		i = 0;
		is_single = 1;
	}
	if (!is_int(c, v) || !(a->begin = (t_ps_node *)malloc(sizeof(t_ps_node))))
	{
		is_single ? ft_free_words(v, c) : 0;
		return (0);
	}
	a->begin->value = ft_atoi(v[i++]);
	a->begin->prev = NULL;
	a->end = a->begin;
	while (i < c)
		if (!stck_append_end(v[i++], &a->end))
			return (0);
	if (!is_dupl(a, c))
	{
		while (a->begin)
		{
			tmp = a->begin;
			a->begin = a->begin->next;
			free(tmp);
		}
		return (0);
	}
	b->begin = NULL;
	b->end = NULL;
	is_single ? ft_free_words(v, c) : 0;
	return (1);
}
