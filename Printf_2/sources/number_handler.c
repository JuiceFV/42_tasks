#include "../includes/ft_printf.h"

void	putnbr(t_printf_format *frmt)
{
	intmax_t	n;

	if (frmt->flags & FLAGS_LONG || frmt->flags & FLAGS_LONG_LONG)
		n = (frmt->flags & FLAGS_LONG_LONG) ? ((intmax_t)va_arg(frmt->ap, long long)) :
			((intmax_t)va_arg(frmt->ap, long));
	else if (frmt->flags & FLAGS_SHORT || frmt->flags & FLAGS_CHAR)
		n = (frmt->flags & FLAGS_CHAR) ? (intmax_t)((char)va_arg(frmt->ap, int)) :
			(intmax_t)((short)va_arg(frmt->ap, int));
	else if (frmt->flags & FLAGS_INTMAX)
		n = (va_arg(frmt->ap, intmax_t));
	else if (frmt->flags & FLAGS_SIZE_T)
		n = ((intmax_t)va_arg(frmt->ap, size_t));
	else
		n = ((intmax_t)va_arg(frmt->ap, int));
	(frmt->flags & FLAGS_ZEROPAD) ? frmt->precision = frmt->min_length : 0;
	itoa_printf(n, frmt, 0);
}

void	putnbr_base(int base, t_printf_format *frmt)
{
	uintmax_t	n;

	if (frmt->flags & FLAGS_LONG || frmt->flags & FLAGS_LONG_LONG)
		n = (frmt->flags & FLAGS_LONG_LONG) ? ((intmax_t)va_arg(frmt->ap, unsigned long long)) :
			((intmax_t)va_arg(frmt->ap, unsigned long));
	else if (frmt->flags & FLAGS_SHORT || frmt->flags & FLAGS_CHAR)
		n = (frmt->flags & FLAGS_CHAR) ? (uintmax_t)((unsigned char)va_arg(frmt->ap, int))
			: (uintmax_t)((unsigned short)va_arg(frmt->ap, int));
	else if (frmt->flags & FLAGS_INTMAX)
		n = (va_arg(frmt->ap, uintmax_t));
	else if (frmt->flags & FLAGS_SIZE_T)
		n = ((uintmax_t)va_arg(frmt->ap, size_t));
	else
		n = (uintmax_t)va_arg(frmt->ap, unsigned int);
	itoa_base_printf(n, base, frmt);
}

void	itoa_printf(intmax_t n, t_printf_format *frmt, int len)
{
	char		s[21];
	uintmax_t	tmp;

	tmp = ABS(n);
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	if ((n < 0 || frmt->flags & FLAGS_PLUS || frmt->flags & FLAGS_SPACE) && frmt->flags & FLAGS_ZEROPAD)
		--frmt->precision;
	frmt->is_printed = MAX(len, frmt->precision);
	if (n < 0 || frmt->flags & FLAGS_PLUS || frmt->flags & FLAGS_SPACE)
		frmt->is_printed++;
	frmt->padding = (frmt->is_printed > frmt->min_length) ? 0 : frmt->min_length - frmt->is_printed;
	padding(frmt, 0);
	tmp = ABS(n);
	itoa_base_fill(tmp, 10, s, frmt);
	(frmt->flags & FLAGS_SPACE) ? s[0] = ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	(frmt->flags & FLAGS_PLUS && n >= 0) ? s[0] = '+' : 0;
	buffer(frmt, s, frmt->is_printed);
	padding(frmt, 1);
}

void	itoa_base_printf(uintmax_t n, int b, t_printf_format *frmt)
{
	uintmax_t	tmp;
	char		s[21];
	int			ext;

	frmt->is_printed = 0;
	tmp = n;
	while (tmp && ++frmt->is_printed)
		tmp /= b;
	(frmt->flags & FLAGS_ZEROPAD) ? frmt->precision = frmt->min_length : 0;
	ext = (frmt->is_printed >= frmt->precision) ? 0 : 1;
	frmt->is_printed = MAX(frmt->precision, frmt->is_printed);
	((frmt->flags & FLAGS_HASH) && b == 8 && !ext) ? --frmt->min_length : 0;
	((frmt->flags & FLAGS_HASH) && b == 8 && !n && (frmt->flags & FLAGS_PRECISION)) ?
	++frmt->is_printed : 0;
	((frmt->flags & FLAGS_HASH) && b == 16 && !(frmt->flags & FLAGS_ZEROPAD)) ? frmt->min_length -= 2 : 0;
	frmt->padding = MAX(0, (frmt->min_length - frmt->is_printed));
	padding(frmt, 0);
	if ((n || (frmt->flags & FLAGS_POINTER))
		&& (frmt->flags & FLAGS_HASH) && ((b == 8 && !ext) || (b == 16)))
		buffer(frmt, "0", 1);
	if ((n || (frmt->flags & FLAGS_POINTER)) && (frmt->flags & FLAGS_HASH) && b == 16)
		buffer(frmt, (frmt->flags & FLAGS_UPPERCASE) ? "X" : "x", 1);
	itoa_base_fill(n, b, s, frmt);
	buffer(frmt, s, frmt->is_printed);
	padding(frmt, 1);
}

void	itoa_base_fill(uintmax_t tmp, int b, char s[BUF_SIZE], t_printf_format *frmt)
{
	int		len;

	if (tmp && !(frmt->flags & FLAGS_POINTER) && (frmt->flags & FLAGS_ZEROPAD) && (frmt->flags & FLAGS_HASH) &&
	b == 16 && !(frmt->flags & FLAGS_LONG_LONG) && frmt->is_printed > 3)
		frmt->is_printed -= 2;
	len = frmt->is_printed;
	frmt->character = 'a' - 10 - ((frmt->flags & FLAGS_UPPERCASE) >> 1);
	while (len--)
	{
		s[len] = tmp % b + ((tmp % b < 10) ? '0' : frmt->character);
		tmp /= b;
	}
	(frmt->flags & FLAGS_PRECISION && frmt->flags & FLAGS_ZEROPAD) ? s[0] = ' ' : 0;
}