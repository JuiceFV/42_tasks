/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:04:52 by cspider           #+#    #+#             */
/*   Updated: 2019/10/01 17:02:13 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"
#include "libft.h"

t_vector	*ft_vector_alloc(size_t type_size)
{
	t_vector *res;

	if (!(res = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	ft_bzero(res, sizeof(t_vector));
	res->type_size = type_size;
	return (ft_vector_reserve(res, 1) ? NULL : res);
}
