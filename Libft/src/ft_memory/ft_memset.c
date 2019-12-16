/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:11:54 by cspider           #+#    #+#             */
/*   Updated: 2019/09/03 20:14:48 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *temp;
	unsigned char sym;

	temp = (unsigned char *)b;
	sym = (unsigned char)c;
	while (len--)
		*temp++ = sym;
	return (b);
}
