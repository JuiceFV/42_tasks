/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:26:08 by cspider           #+#    #+#             */
/*   Updated: 2019/09/03 15:43:06 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_separator(char c)
{
	return ((c == ' ' || (c >= 9 && c <= 13)));
}

int			ft_atoi(const char *str)
{
	unsigned long	result;
	int				sign;
	unsigned long	border;
	size_t			i;

	border = FT_LONG_MAX / 10;
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
			return (-1);
		if ((result > border || (result == border && (str[i] - '0') > 8))
												&& sign == -1)
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	return ((int)(result * sign));
}
