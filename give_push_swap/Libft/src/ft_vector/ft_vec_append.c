/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:13:44 by cspider           #+#    #+#             */
/*   Updated: 2019/10/01 17:14:11 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

int	ft_vector_append(t_vector *this, void const *data, size_t datalen)
{
	if (ft_vector_reserve(this, datalen))
		return (1);
	ft_memcpy(VECTOR_END(this), data, VECTOR_OFFSET(this, datalen));
	this->size += datalen;
	return (0);
}

int	ft_vector_append_free(t_vector *this, void *data, size_t datalen)
{
	if (ft_vector_reserve(this, datalen))
		return (1);
	ft_memcpy(VECTOR_END(this), data, VECTOR_OFFSET(this, datalen));
	this->size += datalen;
	free(data);
	return (0);
}

int	ft_vector_insert(t_vector *this, void const *data,
						size_t datalen, size_t index)
{
	if (this->size < index || ft_vector_reserve(this, datalen))
		return (1);
	ft_memmove(VECTOR_GET(this, index + datalen),
				VECTOR_GET(this, index),
				VECTOR_OFFSET(this, this->size - index));
	ft_memcpy(VECTOR_GET(this, index),
				data,
				VECTOR_OFFSET(this, datalen));
	this->size += datalen;
	return (0);
}

int	ft_vector_append_char(t_vector *this, char data)
{
	if (ft_vector_reserve(this, 1))
		return (1);
	ft_memcpy(VECTOR_END(this), &data, VECTOR_OFFSET(this, 1));
	this->size += 1;
	return (0);
}
