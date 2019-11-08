/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <olongbot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:34:48 by olongbot          #+#    #+#             */
/*   Updated: 2019/11/08 19:23:01 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_int(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	if (argc == 1)
		return (0);
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

int			kill_slaves(int a, char ***v, int *c)
{
	a ? ft_free_words(*v, *c) : 0;
	return (1);
}

int			is_dupl(t_ps_stack *a, int argc)
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

static int	is_separator(char c)
{
	return ((c == ' ' || (c >= 9 && c <= 13)));
}

long		ft_strtol(const char *str)
{
	unsigned long	result;
	int				sign;
	size_t			i;
	unsigned long	border;

	border = FT_INT_MAX / 10;
	i = 0;
	sign = 1;
	result = 0;
	while (is_separator(str[i]))
		i++;
	sign = str[i] == '-' ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		if ((result > border || (result == border && (str[i] - '0') > 7))
												&& sign == 1)
			return (2147483649);
		if ((result > border || (result == border && (str[i] - '0') > 8))
												&& sign == -1)
			return (2147483649);
		result = result * 10 + (str[i++] - '0');
	}
	return ((long)(result * sign));
}
