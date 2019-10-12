/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:04:26 by cspider           #+#    #+#             */
/*   Updated: 2019/10/01 16:04:33 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

void	ft_vector_clear(t_vector *this)
{
	if (this->max > 0)
	{
		free(this->data);
		this->size = 0;
		this->max = 0;
	}
}
