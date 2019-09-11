/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:07:56 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/04 23:45:33 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_num(size_t num)
{
	int	len;

	len = 1;
	while ((num /= 10) > 0)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	size_t		tmp;
	int			sign;
	int			len;
	char		*out;

	len = 0;
	sign = 0;
	sign = n < 0 ? 1 : 0;
	if (n < 0)
		tmp = (size_t)-(n + 1) + 1;
	else
		tmp = n;
	len = digit_num(tmp) + sign;
	if (!(out = ft_strnew(len)))
		return (NULL);
	if (sign)
		out[0] = '-';
	while (len > sign)
	{
		len--;
		out[len] = (tmp % 10 + '0');
		tmp /= 10;
	}
	return (out);
}
