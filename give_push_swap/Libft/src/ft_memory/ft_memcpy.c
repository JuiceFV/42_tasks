/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:14:42 by cspider           #+#    #+#             */
/*   Updated: 2019/09/04 16:14:46 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_temp;
	unsigned char	*src_temp;

	if (!dst && !src)
		return (NULL);
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	while (n--)
		*dst_temp++ = *src_temp++;
	return (dst);
}
