/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_trim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:05:11 by cspider           #+#    #+#             */
/*   Updated: 2019/10/01 16:05:38 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int	ft_vector_trim(t_vector *this)
{
	ft_vector_append(this, "\0", 1);
	if (this->size < this->max)
		return (ft_vector_resize(this, this->size));
	return (0);
}
