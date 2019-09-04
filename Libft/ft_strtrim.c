/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 10:47:37 by cspider           #+#    #+#             */
/*   Updated: 2019/09/04 16:08:20 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	is_whitespace(const char c)
{
	return ((c == ' ' || c == '\t' || c == '\n'));
}

char		*ft_strtrim(char const *s)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (is_whitespace(s[len - 1]) && len)
		len--;
	while (is_whitespace(s[i]) && s[i])
		i++;
	if ((result = ft_strnew((len > i) ? (len - i) : 0)))
	{
		j = 0;
		while (i < len)
			result[j++] = s[i++];
		result[j] = '\0';
	}
	return (result);
}
