#include "../includes/ft_printf.h"

int	ft_printf(const char* format, ...)
{
	t_printf_format res;

	ft_bzero(&res, sizeof(res));
	res.fd = 1;
	res.format = (char*)format;
	va_start(res.ap, format);
	res.length = ft_vsnprintf(res);
	va_end(res.ap);
	return (res.length);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	t_printf_format	res;

	ft_bzero(&res, sizeof(res));
	res.fd = fd;
	res.format = (char *)format;
	va_start(res.ap, format);
	res.length = ft_vsnprintf(res);
	va_end(res.ap);
	return (res.length);
}

void	print_pointer_address(t_printf_format *frmt)
{
	void	*pointer;

	pointer = va_arg(frmt->ap, void *);
	frmt->flags &= ~FLAGS_HASH;
	frmt->min_length -= (frmt->flags & FLAGS_ZEROPAD ? 2 : 0);
	frmt->padding = (frmt->is_printed > frmt->min_length - 3) ? 0 :
		frmt->min_length - 3 - frmt->is_printed;
	frmt->flags |= FLAGS_HASH;
	frmt->flags |= FLAGS_POINTER;
	itoa_base_printf((uintmax_t)pointer, 16, frmt);
}