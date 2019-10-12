/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:10:41 by cspider           #+#    #+#             */
/*   Updated: 2019/10/01 17:17:56 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int	ft_vector_reserve(t_vector *this, size_t size)
{
	size_t	total_size;
	size_t	new_size;

	total_size = size + this->size;
	if (total_size > this->max)
	{
		new_size = (this->max > 0 ? this->max : VEC_INITIAL_SIZE);
		while (new_size < total_size)
			new_size *= VEC_FACTOR;
		return (ft_vector_resize(this, new_size));
	}
	return (0);
}
