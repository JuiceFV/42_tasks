/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:29:06 by cspider           #+#    #+#             */
/*   Updated: 2019/09/04 12:29:08 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	sym;

	temp = (char *)s + ft_strlen(s);
	sym = (char)c;
	while (temp >= s)
	{
		if (*temp == sym)
			return (temp);
		temp--;
	}
	return (NULL);
}
