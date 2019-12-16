/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:10:22 by cspider           #+#    #+#             */
/*   Updated: 2019/10/01 16:10:26 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	ft_vector_new(size_t type_size)
{
	t_vector res;

	res = (t_vector){NULL, 0, 0, type_size};
	ft_vector_reserve(&res, 1);
	return (res);
}
