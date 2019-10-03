/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_num_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:10:36 by cspider           #+#    #+#             */
/*   Updated: 2019/10/03 15:25:24 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t		get_arg_signed_integer(va_list ap, t_specifiers *sp)
{
	intmax_t	arg;

	if (sp->len_mod == 'H')
		arg = (signed char)va_arg(ap, int);
	else if (sp->len_mod == 'h')
		arg = (short)va_arg(ap, int);
	else if (sp->len_mod == 'l' || sp->len_mod == 'z')
		arg = va_arg(ap, long);
	else if (sp->len_mod == '7')
		arg = va_arg(ap, long long);
	else if (sp->len_mod == 'j')
		arg = va_arg(ap, intmax_t);
	else if (sp->len_mod == 't')
		arg = va_arg(ap, ptrdiff_t);
	else
		arg = va_arg(ap, int);
	return (arg);
}

static uintmax_t	get_arg_unsigned_integer(va_list ap, t_specifiers *sp)
{
	uintmax_t	arg;

	if (sp->len_mod == 'H')
		arg = (unsigned char)va_arg(ap, unsigned);
	else if (sp->len_mod == 'h')
		arg = (unsigned short)va_arg(ap, unsigned);
	else if (sp->len_mod == 'l')
		arg = va_arg(ap, unsigned long);
	else if (sp->len_mod == '7')
		arg = va_arg(ap, unsigned long long);
	else if (sp->len_mod == 'z')
		arg = va_arg(ap, size_t);
	else if (sp->len_mod == 'j')
		arg = va_arg(ap, uintmax_t);
	else if (sp->len_mod == 't')
		arg = va_arg(ap, size_t);
	else
		arg = va_arg(ap, unsigned);
	return (arg);
}

int 	signed_integer(t_specifiers *sp, t_vector *frmt, va_list ap, int b)
{
	intmax_t	arg;
	int			res;

	arg = get_arg_signed_integer(ap, sp);
	if (arg < 0)
		ft_vector_append(frmt, "-", 1);
	else if (sp->flags.n.plus)
		ft_vector_append(frmt, "+", 1);
	else if (sp->flags.n.space)
		ft_vector_append(frmt, " ", 1);
	if (arg == 0 && m->precision == 0)
		return (0);
	res = pf_itoa_base(frmt, arg, ABS(b), b < 0);
	if (sp->quote)
		res += thousand_div(frmt, ',');
	return (res);
}

int 	unsigned_integer(t_specifiers *sp, t_vector *frmt, va_list ap, int b)
{
	uintmax_t	arg;
	int			res;

	arg = get_arg_unsigned_integer(ap, sp);
	if (arg == 0 && sp->flags.n.sharp
		&& (sp->conv == 'x' || sp->conv == 'X'))
		frmt->size -= 2;
	if ((arg == 0 && sp->precision == 0) ||
	(arg == 0 && sp->conv == 'o' && sp->flags.n.sharp))
		return (0);
	res = pf_itoa_base(frmt, arg, ABS(b), 2 | (b < 0));
	if (sp->quote)
		res += thousand_div(frmt, ',');
	return (res);
}