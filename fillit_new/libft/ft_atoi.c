/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 20:39:19 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/04 15:51:15 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_atoi(const char *str)
{
	unsigned long	result;
	int				sign;

	sign = 1;
	result = 0;
	while ((*str == ' ' || *str == '\n' || *str == '\v' || *str == '\t'
			|| *str == '\r' || *str == '\f') && *str != '\0')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str > 47 && *str < 58)
	{
		if ((result > FT_LONG_MAX / 10 || (result == FT_LONG_MAX / 10
						&& (*str - '0') > 7)) && sign == 1)
			return (-1);
		if ((result > FT_LONG_MAX / 10 || (result == FT_LONG_MAX / 10
						&& (*str - '0') > 8)) && sign == -1)
			return (0);
		result = result * 10 + (*str - 48);
		str++;
	}
	return ((int)(result * sign));
}
