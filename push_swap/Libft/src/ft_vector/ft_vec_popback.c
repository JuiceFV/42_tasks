/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_popback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:12:12 by cspider           #+#    #+#             */
/*   Updated: 2019/10/01 16:12:15 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

void	ft_vector_pop_back(t_vector *this, size_t length)
{
	this->size -= MIN(length, this->size);
}

void	ft_vector_pop_backf(t_vector *this, size_t length, void (*del)(void*))
{
	while (this->size > 0 && length > 0)
	{
		this->size--;
		del(VECTOR_END(this));
		length--;
	}
}

void	ft_vector_pop_zero(t_vector *this, int *res)
{
	while (((VECTOR_LAST(this))[0] == '0' &&
		(ft_isdigit((VECTOR_LAST(this) - 1)[0]) ||
		(VECTOR_LAST(this) - 1)[0] == '.')) ||
		(VECTOR_LAST(this))[0] == '.')
	{
		ft_vector_pop_back(this, 1);
		res--;
	}
}

void	ft_vector_pop_zerohex(t_vector *this, int *res)
{
	while (((VECTOR_LAST(this))[0] == '0' &&
		(ft_hexisdigit((VECTOR_LAST(this) - 1)[0]) ||
		(VECTOR_LAST(this) - 1)[0] == '.')) ||
		(VECTOR_LAST(this))[0] == '.')
	{
		ft_vector_pop_back(this, 1);
		res--;
	}
}
