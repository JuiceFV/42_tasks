/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:06:19 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/03 19:30:04 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned char const	*s;

	d = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		*d = *s;
		if (*s == (unsigned char)c)
		{
			d++;
			return (d);
		}
		d++;
		s++;
		i++;
	}
	return (NULL);
}
