/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:59:59 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/04 18:50:02 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	i = 0;
	out = ft_strnew(len);
	if (!s || !out)
		return (NULL);
	while (len > i)
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
