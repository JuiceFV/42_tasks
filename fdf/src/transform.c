/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:43:09 by olongbot          #+#    #+#             */
/*   Updated: 2019/10/05 17:05:51 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_rotation(t_vector *vec, double t)
{
	double y;
	double z;

	y = (double)(vec->y);
	z = (double)(vec->z);
	vec->y = y * cos(t) - z * sin(t);
	vec->z = y * sin(t) + z * cos(t);
}

void	y_rotation(t_vector *vec, double t)
{
	double x;
	double z;

	x = (double)(vec->x);
	z = (double)(vec->z);
	vec->x = x * cos(t) + z * sin(t);
	vec->z = -x * sin(t) + z * cos(t);
}

void	z_rotation(t_vector *vec, double t)
{
	double x;
	double y;

	x = (double)(vec->x);
	y = (double)(vec->y);
	vec->x = x * cos(t) - y * sin(t);
	vec->y = x * sin(t) + y * cos(t);
}

void	apply_rot(t_list *p, char a, double d)
{
	if (a == 'x')
	{
		while (p != NULL)
		{
			x_rotation(((t_vector *)(p->content)), d);
			p = p->next;
		}
	}
	if (a == 'y')
	{
		while (p != NULL)
		{
			y_rotation(((t_vector *)(p->content)), d);
			p = p->next;
		}
	}
	if (a == 'z')
	{
		while (p != NULL)
		{
			z_rotation(((t_vector *)(p->content)), d);
			p = p->next;
		}
	}
}
