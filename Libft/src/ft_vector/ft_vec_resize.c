/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:05:51 by cspider           #+#    #+#             */
/*   Updated: 2019/10/01 17:10:10 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

int	ft_vector_resize(t_vector *this, size_t new_size)
{
	void *tmp;

	tmp = malloc(new_size * this->type_size);
	if (tmp == NULL)
		return (1);
	if (this->size > new_size)
		this->size = new_size;
	ft_memcpy(tmp, this->data, this->size * this->type_size);
	free(this->data);
	this->data = tmp;
	this->max = new_size;
	return (0);
}
