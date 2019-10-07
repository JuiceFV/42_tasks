/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:29:46 by cspider           #+#    #+#             */
/*   Updated: 2019/10/06 17:07:21 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			char_index(char i, char const *str)
{
	char const	*p = str;

	while (*p != '\0' && *p != i)
		p++;
	return (*p == '\0' ? -1 : p - str);
}

double		fract_part(double num, int prec)
{
	static const double pow10[] = {
		1, 10, 100, 1000, 10000, 100000,
		1000000, 10000000, 100000000,
		1000000000, 10000000000, 100000000000,
		1000000000000, 10000000000000};
	int whole = (int)x;
	double tmp = (x - whole) * pow10[prec];
	unsigned long frac = (unsigned long)tmp;
	x = frac / pow10[prec];
	return (x);
}

long int	round_base(double x, double f, int b)
{
	double		half;
	long int	r;

	r = (long int)(f * 10 + 0.5);
	half = ((double)b) / 2;
	if (r < half)
		return (x);
	else
	{
		x = x + 1;
		while (((long int)x) % (b / 10) != 0)
			x = x + 1;
		return (x);
	}
}
/*
** TODO
** Finished | -
** Norme 	| -
** Errors	| -
** Logic 	| -
** Checked	| -
** included	| -
*/
