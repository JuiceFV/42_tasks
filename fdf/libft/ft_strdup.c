/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:54:24 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/04 01:01:42 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;
	int		j;

	j = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	cpy = (char*)malloc(sizeof(*cpy) * (i + 1));
	if (cpy == NULL)
		return (NULL);
	while (j <= i)
	{
		cpy[j] = s1[j];
		j++;
	}
	return (cpy);
}
