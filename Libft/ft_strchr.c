/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 08:37:13 by cspider           #+#    #+#             */
/*   Updated: 2019/09/04 08:40:24 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp;
	char	sym;

	temp = (char *)s;
	sym = (char)c;
	while (*temp && !(*temp == sym))
		temp++;
	if (*temp == sym)
		return (temp);
	else
		return (NULL);
}
