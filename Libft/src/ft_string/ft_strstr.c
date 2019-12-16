/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 10:36:13 by cspider           #+#    #+#             */
/*   Updated: 2019/09/04 10:43:22 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*haystack_temp;
	size_t	needle_len;
	size_t	i;
	size_t	j;

	haystack_temp = (char *)haystack;
	if (!(needle_len = ft_strlen(needle)))
		return (haystack_temp);
	i = 0;
	while (haystack_temp[i])
	{
		j = 0;
		while (needle[j] && needle[j] == haystack_temp[i + j])
			j++;
		if (j == needle_len)
			return (&haystack_temp[i]);
		i++;
	}
	return (NULL);
}
