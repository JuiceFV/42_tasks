/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <olongbot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:37:04 by olongbot          #+#    #+#             */
/*   Updated: 2019/11/08 19:21:39 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_append_end(char *str, t_ps_node **back)
{
	t_ps_node		*tmp;
	long			num;

	num = ft_strtol(str);
	if (num < FT_INT_MIN || num > FT_INT_MAX)
		return (0);
	if (*back == NULL)
		return (0);
	if (!(tmp = (t_ps_node *)malloc(sizeof(t_ps_node))))
		return (0);
	tmp->value = (int)num;
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
	char *tmp;

	if (*c - 1 == 1)
	{
		tmp = ft_strjoinf(ft_strjoin((*v)[0], " "), (*v)[1]);
		*c = ft_number_of_words(tmp, ' ');
		*v = ft_strsplit(tmp, ' ');
		*is_single = 1;
		free(tmp);
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

	is_single = 0;
	lolkek(v, c, &is_single);
	if (!is_int(*c, *v) || !(a->begin = (t_ps_node *)malloc(sizeof(t_ps_node))))
		return (!kill_slaves(is_single, v, c));
	i = 1;
	a->begin->prev = NULL;
	a->begin->next = NULL;
	a->begin->order_num = -1;
	a->end = a->begin;
	if ((ft_strtol((*v)[i]) < FT_INT_MIN ||
		ft_strtol((*v)[i]) > FT_INT_MAX) && free_slaves(a))
		return (!(kill_slaves(is_single, v, c)));
	a->begin->value = ft_atoi((*v)[i++]);
	while (i < *c)
		if (!stack_append_end((*v)[i++], &a->end))
			return (!(kill_slaves(is_single, v, c)));
	if (!is_dupl(a, *c) && free_slaves(a))
		return (!(kill_slaves(is_single, v, c)));
	b->begin = NULL;
	b->end = NULL;
	is_single ? ft_free_words(*v, *c) : 0;
	return (1);
}
