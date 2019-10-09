/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_double_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:28:51 by cspider           #+#    #+#             */
/*   Updated: 2019/10/09 18:22:46 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	finde(long double *arg, int *res, t_vector *frmt, int e)
{
	if (*arg < 100000 && *arg >= 0.0001)
		return (e);
	if (*arg > 0 && *arg < 1)
	{
		if (((int)((*arg) * 10) % 10) != 0)
		{
			*res = ft_vector_append(frmt, "0.", 2);
			*arg = *arg * 10;
		}
		else
		{
			while (*arg > 0 && *arg < 1)
			{
				*arg = *arg * 10;
				e--;
			}
		}
	}
	while (*arg > 9)
	{
		*arg = *arg / 10;
		e++;
	}
	return (e);
}

static int	findp(long double *arg, int p)
{
	while (*arg > 0 && *arg < 1)
	{
		*arg = *arg * 2;
		p--;
	}
	while (*arg >= 2)
	{
		*arg = *arg / 2;
		p++;
	}
	return (p);
}

static int	findlp(long double *arg, int p)
{
	if (*arg > 0 && *arg < 1)
	{
		while (*arg < 16)
		{
			*arg = *arg * 2;
			p--;
		}
	}
	while (*arg >= 16)
	{
		*arg = *arg / 2;
		p++;
	}
	return (p);
}

int			signed_double_g(t_specifiers *sp,
		t_vector *frmt, long double arg, char *c)
{
	int res;
	int e;

	e = 0;
	e = finde(&arg, &res, frmt, e);
	res = rtoa(frmt, ABS(arg), 10, sp);
	ft_vector_pop_zero(frmt, &res);
	if (e == 0)
		res += ft_vector_append(frmt, c, 1);
	if (e >= 0)
		res += ft_vector_append(frmt, "+", 1);
	else
		res += ft_vector_append(frmt, "-", 1);
	if (ABS(e) < 10)
		res += ft_vector_append(frmt, "0", 1);
	itoa_base(frmt, e, 10, 0);
	return (res);
}

int			signed_double_a(t_specifiers *sp,
		t_vector *frmt, long double arg, char *c)
{
	int res;
	int p;

	p = 0;
	p = (sp->len_mod == 'L' ? findlp(&arg, p) : findp(&arg, p));
	if (*c == 'p')
		res = rtoa(frmt, ABS(arg), 16, sp);
	else
		res = rtoa(frmt, ABS(arg), -16, sp);
	if (sp->precision == -1)
		ft_vector_pop_zerohex(frmt, &res);
	res += ft_vector_append(frmt, c, 1);
	if (p >= 0)
		res += ft_vector_append(frmt, "+", 1);
	else
		res += ft_vector_append(frmt, "-", 1);
	itoa_base(frmt, p, 10, 0);
	return (res);
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
