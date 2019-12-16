/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_polynomial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:50:02 by cspider           #+#    #+#             */
/*   Updated: 2019/09/06 18:03:15 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_polynomial(float indexes[], int degree, float x)
{
	float	temp;
	int		i;

	temp = indexes[degree];
	i = degree;
	while (i > 0)
	{
		temp = (indexes[i - 1] + x * temp);
		i--;
	}
	return (temp);
}
