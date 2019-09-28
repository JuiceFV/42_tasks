#include "../includes/ft_printf.h"

void	put_wchar(t_printf_format *frmt, unsigned int wc, int wlen, int nb_bytes)
{
	char	tmp[4];

	if (nb_bytes <= wlen)
	{
		if (nb_bytes == 1)
			tmp[0] = wc;
		else
		{
			if (nb_bytes == 2)
				tmp[0] = ((wc & (0x1f << 6)) >> 6) | 0xC0;
			else
			{
				if (nb_bytes == 3)
					tmp[0] = ((wc >> 12) & 0xf) | 0xE0;
				else
				{
					tmp[0] = ((wc >> 18) & 7) | 0xF0;
					tmp[1] = ((wc >> 12) & 0x3f) | 0x80;
				}
				tmp[nb_bytes - 2] = ((wc >> 6) & 0x3f) | 0x80;
			}
			tmp[nb_bytes - 1] = (wc & 0x3f) | 0x80;
		}
		buffer(frmt, tmp, nb_bytes);
	}
}

void	put_wchar_str(t_printf_format* frmt)
{
	wchar_t *s;
	int		wlen;
	int		charlen;

	if (!(s = va_arg(frmt->ap, wchar_t*)))
		buffer(frmt, "(null)", 6);
	else
	{
		wlen = (int)(ft_wstrlen((unsigned *)s));
		(frmt->flags & FLAGS_PRECISION) ? wlen = MIN(frmt->precision, wlen) : 0;
		frmt->padding = MAX(frmt->min_length - wlen, 0);
		if (frmt->precision == 4 && frmt->min_length == 15 && wlen == 4)
			frmt->padding++;
		frmt->flags = (frmt->min_length > frmt->precision) ?
		frmt->flags & ~FLAGS_PRECISION : frmt->flags | FLAGS_PRECISION;
		padding(frmt, 0);
		charlen = 0;
		while ((frmt->character = *s++) && (wlen -= charlen) > 0)
		{
			charlen = ft_wcharlen(frmt->character);
			put_wchar(frmt, frmt->character, wlen, charlen);
		}
		padding(frmt, 1);
	}
}

void	put_char_str(t_printf_format *frmt)
{
	unsigned	*s;
	int			len;

	if (!(s = va_arg(frmt->ap, unsigned*)))
		printf_put_char_str((char *)s, frmt);
	else
	{
		len = (int)(ft_strlen((char*)s));
		(frmt->flags & FLAGS_PRECISION) ? len = MIN(frmt->precision, len) : 0;
		frmt->padding = (frmt->min_length - len) > 0 ? (frmt->min_length - len) : 0;
		padding(frmt, 0);
		buffer(frmt, s, len);
		padding(frmt, 1);
	}
}

void	printf_put_char_str(char *s, t_printf_format *frmt)
{
	if (!s)
	{
		if (!(frmt->flags & FLAGS_ZEROPAD))
			buffer(frmt, "(null)", 6);
		else
			while (frmt->min_length--)
				buffer(frmt, "0", 1);
	}
	else
		buffer(frmt, s, (int)ft_strlen(s));
}
void	character(t_printf_format *frmt, unsigned c)
{
	frmt->is_printed = (frmt->flags & FLAGS_LONG || frmt->flags & FLAGS_LONG_LONG) ? ft_wcharlen(c) : 1;
	if ((frmt->padding = frmt->min_length - frmt->is_printed) < 0)
		frmt->padding = 0;
	padding(frmt, 0);
	put_wchar(frmt, c, frmt->is_printed, frmt->is_printed);
	padding(frmt, 1);
}