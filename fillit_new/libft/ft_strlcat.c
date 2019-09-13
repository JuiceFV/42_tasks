/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 01:19:20 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/03 19:30:58 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		src_len;

	j = 0;
	i = 0;
	src_len = 0;
	while (dst[i] != '\0' && size > i)
		i++;
	while (src[src_len] != '\0')
		src_len++;
	while (src[j] != '\0' && size > i + j + 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (size > i)
		dst[i + j] = '\0';
	return (i + src_len);
}
