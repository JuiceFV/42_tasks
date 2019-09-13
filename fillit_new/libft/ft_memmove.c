/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:32:31 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/03 23:05:23 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst_temp;
	unsigned char *src_temp;

	if (!dst && !src)
		return (NULL);
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
