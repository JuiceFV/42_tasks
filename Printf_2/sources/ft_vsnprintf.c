#include "../includes/ft_printf.h"

int		ft_vsnprintf(t_printf_format frmt)
{
	size_t index;


	while (*frmt.format)
	{
		if (*frmt.format == '%')
		{
			frmt.format++;
			if (!(*frmt.format))
				break ;
			evaluate_option(&frmt);
		}
		else
			buffer(&frmt, frmt.format, 1);
		frmt.format++;
	}
	write(frmt.fd, frmt.buffer, frmt.buff_i);
	return (frmt.length);
}

void		cs_not_found(t_printf_format *frmt)
{
	if ((frmt->padding = frmt->min_length - 1) > 0)
	{
		padding(frmt, 0);
		buffer(frmt, frmt->format, 1);
		padding(frmt, 1);
		return ;
	}
	buffer(frmt, frmt->format, 1);
}