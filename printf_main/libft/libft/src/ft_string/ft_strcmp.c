/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 08:52:02 by cspider           #+#    #+#             */
/*   Updated: 2019/09/04 08:56:58 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	i = 0;
	while (temp1[i] || temp2[i])
	{
		if (temp1[i] != temp2[i])
			return (temp1[i] - temp2[i]);
		i++;
	}
	return (0);
}
