#include "ft_printf.h"

int	_rtoa(t_vector *frmt, long double x, int b, t_specifiers *sp)
{
	int		res;
	double 	frac;
	int		i;
	int		p;

	res = 1 + _itoa_base(frmt, (intmax_t)x, ABS(b), (b < 0));
	if (sp->quote)
		res += quote_div(frmt, ',');
	if (sp->precision == 0)
		return (res);
	ft_vector_append(frmt, ".", 1);
	i = -1;
	frac = fract_part(x);
	p = (sp->precision == -1 ? 13 : sp->precision);
	while (++i < p)
	{
		frac *= ABS(b);
		if (frac < 1)
			ft_vector_append(frmt, "0", 1);
		res++;
	}
	frac = round_base(frac, fract_part(frac), ABS(b));
	if (frac != 0)
		_itoa_base(frmt, (long long)frac, ABS(b), 2 | (b < 0));
	return (res);
}

int ev_f(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	long double arg;

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
	if (arg == 0 &&  sp->precision == 0)
		return (0);
	if (sp->precision == -1)
		sp->precision = 6;
	if (arg != arg || arg == 1.0 / 0.0)
	{
		if (arg == 1.0 / 0.0)
			ft_vector_append(frmt, "inf", 3);
		else
			ft_vector_append(frmt, "nan", 3);
		return (0);
	}
	return (_rtoa(frmt, ABS(arg), 10, sp));
}

int ev_cf(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	long double arg;

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
	if (arg == 0 &&  sp->precision == 0)
		return (0);
	if (sp->precision == -1)
		sp->precision = 6;
	if (arg != arg || arg == 1.0 / 0.0)
	{
		if (arg == 1.0 / 0.0)
			ft_vector_append(frmt, "INF", 3);
		else
			ft_vector_append(frmt, "NAN", 3);
		return (0);
	}
	return (_rtoa(frmt, ABS(arg), 10, sp));
}

int ev_e(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	long double arg;

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
	return (signed_double_e(sp, frmt, arg, "e"));
}

int ev_ce(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	long double arg;

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
	return (signed_double_e(sp, frmt, arg, "E"));
}
/*
** TODO
** Finished | +
** Norme 	| -
** Errors	| -
** Logic 	| -
** Checked	| -
** included	| -
*/