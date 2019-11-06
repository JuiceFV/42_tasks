/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <olongbot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:37:04 by cspider           #+#    #+#             */
/*   Updated: 2019/11/06 20:30:41 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stck_append_end(char *str, t_ps_node **back)
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
	tmp->order_num = -1;
	(*back)->order_num = -1;
	(*back)->next = tmp;
	tmp->prev = *back;
	*back = tmp;
	return (1);
}

char	*ft_strjoinf(char const *s1, char const *s2)
{
	char	*result;
	char	*start;
	char	*tmp;

	tmp = (char *)s1;
	if (!s1 && !s2)
		return (NULL);
	result = ft_strnew((s1 ? ft_strlen(s1) : 0) + (s2 ? ft_strlen(s2) : 0));
	if ((start = result))
	{
		if (s1)
			while (*s1)
				*result++ = *s1++;
		if (s2)
			while (*s2)
				*result++ = *s2++;
		*result = '\0';
	}
	free(tmp);
	return (start);
}

void	lolkek(char ***v, int *c, int *is_single)
{
	if (*c - 1 == 1)
	{
		*c = ft_number_of_words((*v)[1], ' ') + 1;
		*v = ft_strsplit(ft_strjoinf(ft_strjoin((*v)[0], " "), (*v)[1]), ' ');
		*is_single = 1;
	}
}

int		free_slaves(t_ps_stack *a)
{
	t_ps_node	*tmp;

	while (a->begin)
	{
		tmp = a->begin;
		a->begin = a->begin->next;
		free(tmp);
	}
	return (1);
}

int		create_stack(t_ps_stack *a, t_ps_stack *b, char ***v, int *c)
{
	int			i;
	int			is_single;

	i = 1;
	is_single = 0;
	lolkek(v, c, &is_single);
	if (!is_int(*c, *v) || !(a->begin = (t_ps_node *)malloc(sizeof(t_ps_node))))
	{
		is_single ? ft_free_words(*v, *c) : 0;
		return (0);
	}
	a->begin->value = ft_atoi((*v)[i++]);
	a->begin->prev = NULL;
	a->end = a->begin;
	while (i < *c)
		if (!stck_append_end((*v)[i++], &a->end))
			return (0);
	if (!is_dupl(a, *c) && free_slaves(a))
		return (0);
	b->begin = NULL;
	b->end = NULL;
	is_single ? ft_free_words(*v, *c) : 0;
	return (1);
}
