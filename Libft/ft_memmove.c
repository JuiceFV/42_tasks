/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:57:19 by cspider           #+#    #+#             */
/*   Updated: 2019/09/03 20:08:54 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst_temp;
	unsigned char *src_temp;

	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	if (dst_temp < src_temp)
		while (len--)
			*dst_temp++ = *src_temp++;
	else
	{
		dst_temp += len;
		src_temp += len;
		while (len--)
			*--dst_temp = *--src_temp;
	}
	return (dst);
}
