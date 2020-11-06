/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:16:23 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/03 16:59:15 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	infill;
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	infill = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*ptr = infill;
		ptr++;
		i++;
	}
	return (s);
}
