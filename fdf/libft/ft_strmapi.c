/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:50:41 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/04 18:04:51 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	cpy = ft_strnew(ft_strlen(s));
	if (!cpy)
		return (NULL);
	while (s && s[i] != '\0')
	{
		cpy[i] = f(i, s[i]);
		i++;
	}
	return (cpy);
}
