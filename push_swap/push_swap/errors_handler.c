/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:34:48 by cspider           #+#    #+#             */
/*   Updated: 2019/10/17 17:34:04 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		if (!ft_isdigit(argv[i][j]))
			return (0);
		while (ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j])
			return (0);
		i++;
	}
	return (1);
}

int	is_dupl(t_ps_stack *a, int argc)
{
	t_ps_node	*tmp;
	int			i;
	int			j;
	int			k;
	int			arr[argc + 1];

	tmp = a->begin;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	j = -1;
	while (j++ < i)
	{
		k = j;
		while (++k < i)
			if (arr[j] == arr[k])
				return (0);
	}
	return (1);
}
