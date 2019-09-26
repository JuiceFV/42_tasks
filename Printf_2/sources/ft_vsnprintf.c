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

	}
}