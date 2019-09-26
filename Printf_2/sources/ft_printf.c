#include "../includes/ft_printf.h"

int	ft_printf(const char* format, ...)
{
	t_printf_format res;

	res.format = (char*)format;
	va_start(res.ap, format);
	res.length = ft_vsnprintf(res);
	va_end(res.ap);
	return (res.length);
}