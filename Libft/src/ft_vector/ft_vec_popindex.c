/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_popindex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:12:33 by cspider           #+#    #+#             */
/*   Updated: 2019/10/01 17:16:38 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

int	ft_vector_pop_index(t_vector *this, size_t index,
										size_t length)
{
	size_t	n;

	if (index > this->size)
		return (1);
	n = MIN(length, this->size - index);
	ft_memmove(VECTOR_GET(this, index),
				VECTOR_GET(this, index + n),
				VECTOR_OFFSET(this, this->size - n - index));
	this->size -= n;
	return (0);
}

int	ft_vector_pop_indexf(t_vector *this, size_t index,
					size_t length, void (*del)(void*))
{
	size_t	n;
	size_t	i;

	if (index > this->size)
		return (1);
	n = MIN(length, this->size - index);
	i = index - 1;
	while (++i < index + n)
		del(VECTOR_GET(this, i));
	ft_memmove(VECTOR_GET(this, index),
				VECTOR_GET(this, index + n),
				VECTOR_OFFSET(this, this->size - n - index));
	this->size -= n;
	return (0);
}
