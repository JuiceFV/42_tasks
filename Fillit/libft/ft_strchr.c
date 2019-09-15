/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:04:38 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/04 00:32:09 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	while (*tmp != '\0' || (char)c == '\0')
	{
		if (*tmp == (char)c)
		{
			return (tmp);
		}
		tmp++;
	}
	return (NULL);
}
