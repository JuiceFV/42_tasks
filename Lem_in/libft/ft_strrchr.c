/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:04:38 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/04 00:43:47 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		len;

	tmp = (char *)s;
	len = 0;
	while (*tmp != '\0')
	{
		len++;
		tmp++;
	}
	while (len != -1)
	{
		if (*tmp == (char)c)
		{
			return (tmp);
		}
		tmp--;
		len--;
	}
	return (NULL);
}
