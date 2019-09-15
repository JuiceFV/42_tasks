/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:13:43 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/04 23:46:34 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	if (size > size + 1)
		return (NULL);
	ptr = (char *)ft_memalloc(size + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}
