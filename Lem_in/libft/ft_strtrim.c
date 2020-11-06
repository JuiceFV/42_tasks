/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:53:17 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/04 23:07:17 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	char		*out;

	i = 0;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (s[i] != '\0')
		i++;
	if (i != 0)
		i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i != 0)
		i--;
	out = ft_strnew(i + 1);
	if (!out)
		return (NULL);
	j = 0;
	while (i >= j)
	{
		out[j] = s[j];
		j++;
	}
	return (out);
}
