/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_derivative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:05:36 by cspider           #+#    #+#             */
/*   Updated: 2019/09/06 18:51:52 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_derivative(float indexes[], int degree, float x)
{
	float	d[10];
	float	pd;
	float	ps;
	int		i;

	pd = 0;
	i = 0;
	while (i <= degree)
	{
		ps = ft_power(x, degree - (i + 1));
		d[i] = (degree - i) * indexes[degree - i] * ps;
		pd += d[i];
	}
	return (pd);
}
