#include "../includes/ft_printf.h"

void			color(t_printf_format *frmt)
{
	int len;

	frmt->is_printed = 5;
	if (!ft_strncmp(frmt->format, "{red}", (len = 5)))
		buffer(frmt, PF_RED, frmt->is_printed);
	else if (!ft_strncmp(frmt->format, "{green}", (len = 7)))
		buffer(frmt, PF_GREEN, frmt->is_printed);
	else if (!ft_strncmp(frmt->format, "{yellow}", (len = 8)))
		buffer(frmt, PF_YELLOW, frmt->is_printed);
	else if (!ft_strncmp(frmt->format, "{blue}", (len = 6)))
		buffer(frmt, PF_BLUE, frmt->is_printed);
	else if (!ft_strncmp(frmt->format, "{purple}", (len = 8)))
		buffer(frmt, PF_PURPLE, frmt->is_printed);
	else if (!ft_strncmp(frmt->format, "{cyan}", (len = 6)))
		buffer(frmt, PF_CYAN, frmt->is_printed);
	else if (!ft_strncmp(frmt->format, "{eoc}", (len = 5)))
		buffer(frmt, PF_EOC, --frmt->is_printed);
	else if (!(len = 0))
		frmt->is_printed = 0;
	frmt->format += len - 1;
	frmt->length += frmt->is_printed;
}

static void		ldtoa_fill(double n, t_printf_format *frmt, long value)
{
	int		len;
	int		accuracy;
	char	s[48];

	len = frmt->is_printed - 1 - frmt->precision;
	accuracy = frmt->is_printed - 1 - len;
	while (accuracy--)
	{
		s[len + accuracy + 1] = value % 10 + '0';
		value /= 10;
	}
	(frmt->precision > 0) ? s[len] = '.' : 0;
	value = (long)(ABS(n));
	while (++accuracy < len)
	{
		s[len - accuracy - 1] = value % 10 + '0';
		value /= 10;
	}
	(frmt->flags & FLAGS_PRECISION && frmt->flags & FLAGS_ZEROPAD) ? s[0] = ' ' : 0;
	(frmt->flags & FLAGS_SPACE) ? s[0] = ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	(frmt->flags & FLAGS_PLUS && n >= 0) ? s[0] = '+' : 0;
	buffer(frmt, s, len + 1 + 6);
}

void			pf_putdouble(t_printf_format *frmt)
{
	double		n;
	long		tmp;
	int			len;
	double		decimal;
	long		value;

	n = (double)va_arg(frmt->ap, double);
	(frmt->flags & FLAGS_ZEROPAD) ? frmt->precision = frmt->min_length : 0;
	if (!(frmt->flags & FLAGS_PRECISION))
		frmt->precision = 6;
	len = (frmt->precision > 0) ? 1 : 0;
	tmp = (long)(ABS(n));
	while (tmp && ++len)
		tmp /= 10;
	(frmt->flags & FLAGS_ZEROPAD) ? frmt->precision = frmt->min_length : 0;
	frmt->is_printed = frmt->precision + len + ((n < 0) ? 1 : 0);
	decimal = ((n < 0.0f) ? -n : n);
	decimal = (decimal - (long)(((n < 0.0f) ? -n : n))) *
	ft_pow(10, frmt->precision + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
	value = (int)decimal;
	ldtoa_fill(n, frmt, value);
}