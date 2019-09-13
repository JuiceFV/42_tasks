/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:53:17 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/04 19:18:17 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	char	*out;

	if (!s1 && !s2)
		return (NULL);
	tmp = ft_strnew((s1 ? ft_strlen(s1) : 0) + (s2 ? ft_strlen(s2) : 0));
	if ((out = tmp))
	{
		if (s1)
			while (*s1)
				*tmp++ = *s1++;
		if (s2)
			while (*s2)
				*tmp++ = *s2++;
		*tmp = '\0';
	}
	return (out);
}
