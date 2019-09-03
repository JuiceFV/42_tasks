/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:22:21 by cspider           #+#    #+#             */
/*   Updated: 2019/09/03 18:16:03 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_length(int n, int negative)
{
	int len;

	len = 1;
	while ((n /= 10))
		len++;
	return (len + negative);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		negative;
	int		digit;

	negative = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	len = ft_length(n, negative);
	if ((str = ft_strnew(len)))
	{
		str[len--] = '\0';
		while (len >= negative)
		{
			digit = n % 10;
			str[len--] = digit + '0';
			n /= 10;
		}
		if (negative)
			str[0] = '-';
	}
	return (str);
}
