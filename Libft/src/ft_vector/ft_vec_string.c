/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:15:34 by cspider           #+#    #+#             */
/*   Updated: 2019/10/01 17:19:57 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

/*
** f converts an element to a string.
*/

char	*ft_vector_string(t_vector *this, char *(*f)(void *))
{
	t_vector	res[1];
	void		*iterator;
	char		*tmp;

	*res = VECTOR(char);
	ft_vector_reserve(this, this->size * 3 + 10);
	ft_vector_append(res, "[|", 3);
	iterator = VECTOR_START(this);
	tmp = f(iterator);
	ft_vector_append(res, tmp, sizeof(tmp));
	while (VECTOR_HASNEXT(this, iterator))
	{
		ft_vector_append(res, ", ", 3);
		tmp = f(iterator);
		ft_vector_append(res, tmp, sizeof(tmp));
	}
	ft_vector_append(res, "|]", 3);
	return ((char *)res->data);
}
