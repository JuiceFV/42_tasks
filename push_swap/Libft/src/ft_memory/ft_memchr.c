/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:18:29 by cspider           #+#    #+#             */
/*   Updated: 2019/09/03 19:33:05 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *temp;
	unsigned char sym;

	temp = (unsigned char *)s;
	sym = (unsigned char)c;
	while (n--)
	{
		if (*temp == sym)
			return (temp);
		temp++;
	}
	return (NULL);
}
