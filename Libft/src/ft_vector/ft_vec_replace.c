/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:02:39 by cspider           #+#    #+#             */
/*   Updated: 2019/10/01 18:37:34 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int	ft_vector_replace(t_vector *this, size_t index, size_t length,
								t_vector *v_new)
{
	return (ft_vector_pop_index(this, index, length)
		|| ft_vector_insert(this, v_new->data, v_new->size, index));
}
