#include "ft_printfh"

int		ft_printf(const char *format, ...)
{
	va_list arg_list;
	int result;
	va_start(arg_list, format);

	va_end(arg_list);
	return (result);
}