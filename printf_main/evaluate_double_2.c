#include "ft_printf.h"

int	ev_g(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	double arg;

	if (sp->len_mod == 'L')
		arg = va_arg(ap, long double);
	else
		arg = va_arg(ap, double);
	if (arg < 0)
		ft_vector_append(frmt, "-", 1);
	else if (sp->flags.n.plus)
		ft_vector_append(frmt, "+", 1);
	else if (sp->flags.n.space)
		ft_vector_append(frmt, " ", 1);
	if (sp->precision == -1)
		sp->precision = 6;
	arg = ABS(arg);
	if (sp->precision != 0)
		sp->precision = sp->precision - 1;
	return (signed_double_g(sp, frmt, arg, "e"));
}

int	ev_cg(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	double arg;

	if (sp->len_mod == 'L')
		arg = va_arg(ap, long double);
	else
		arg = va_arg(ap, double);
	if (arg < 0)
		ft_vector_append(frmt, "-", 1);
	else if (sp->flags.n.plus)
		ft_vector_append(frmt, "+", 1);
	else if (sp->flags.n.space)
		ft_vector_append(frmt, " ", 1);
	if (sp->precision == -1)
		sp->precision = 6;
	arg = ABS(arg);
	if (sp->precision != 0)
		sp->precision = sp->precision - 1;
	return (signed_double_g(sp, frmt, arg, "E"));
}

int	ev_a(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	double arg;

	if (sp->len_mod == 'L')
		arg = va_arg(ap, long double);
	else
		arg = va_arg(ap, double);
	if (arg < 0)
		ft_vector_append(frmt, "-", 1);
	else if (sp->flags.n.plus)
		ft_vector_append(frmt, "+", 1);
	else if (sp->flags.n.space)
		ft_vector_append(frmt, " ", 1);
	ft_vector_append(frmt, "0x", 2);
	arg = ABS(arg);
	return (signed_double_a(sp, frmt, arg, "p"));
}

int	ev_ca(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	double arg;

	if (sp->len_mod == 'L')
		arg = va_arg(ap, long double);
	else
		arg = va_arg(ap, double);
	if (arg < 0)
		ft_vector_append(frmt, "-", 1);
	else if (sp->flags.n.plus)
		ft_vector_append(frmt, "+", 1);
	else if (sp->flags.n.space)
		ft_vector_append(frmt, " ", 1);
	ft_vector_append(frmt, "0X", 2);
	arg = ABS(arg);
	if (sp->precision != 0)
		sp->precision = sp->precision - 1;
	return (signed_double_a(sp, frmt, arg, "P"));
}

int	signed_double_e(t_specifiers *sp, t_vector *frmt,
						long double arg, char *c)
{
	int res;
	int e;

	e = 0;
	while (arg > 0 && arg < 1)
	{
		arg *= 10;
		e--;
	}
	while (arg > 9)
	{
		arg /= 10;
		e++;
	}
	res = _rtoa(frmt, ABS(arg), 10, sp);
	res += ft_vector_append(frmt, c, 1);
	if (e >= 0)
		res += ft_vector_append(frmt, "+", 1);
	else
		res += ft_vector_append(frmt, "-", 1);
	if (ABS(e) < 10)
		res += ft_vector_append(frmt, "0", 1);
	_itoa_base(frmt, e, 10, 0);
	return (res);
}
/*
** TODO
** signed_double_g and signed_double_a doesn't created
** Finished | -
** Norme 	| -
** Errors	| -
** Logic 	| -
** Checked	| -
** included	| -
*/