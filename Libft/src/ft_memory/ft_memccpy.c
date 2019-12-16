/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:07:13 by cspider           #+#    #+#             */
/*   Updated: 2019/09/03 19:23:35 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	sym;
	unsigned char	*dst_temp;
	unsigned char	*src_temp;

	sym = (unsigned char)c;
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	while (n--)
	{
		*dst_temp++ = *src_temp++;
		if (*(dst_temp - 1) == sym)
			return (dst_temp);
	}
	return (NULL);
}
