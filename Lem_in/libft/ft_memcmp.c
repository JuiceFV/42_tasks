/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:41:37 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/03 23:13:05 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*d1;
	unsigned char		*d2;
	int					result;

	if (n == 0)
		return (0);
	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	i = 0;
	result = *d1 - *d2;
	while (i + 1 < n && result == 0)
	{
		d1++;
		d2++;
		i++;
		result = *d1 - *d2;
	}
	return (result);
}
