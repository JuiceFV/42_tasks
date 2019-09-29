#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_format	p;

	ft_bzero(&p, sizeof(p));
	p.fd = 1;
	p.format = (char *)format;
	va_start(p.ap, format);
	p.len = ft_vsnprintf(p);
	va_end(p.ap);
	return (p.len);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	t_format	p;

	ft_bzero(&p, sizeof(p));
	p.fd = fd;
	p.format = (char *)format;
	va_start(p.ap, format);
	p.len = ft_vsnprintf(p);
	va_end(p.ap);
	return (p.len);
}

int ft_vsnprintf(t_format p)
{
	while (*p.format)
	{
		if (*p.format == '%')
		{
			++p.format;
			if (!*p.format)
				break ;
			evaluate_optionals(&p);
		}
		else
			buffer(&p, p.format, 1);
		++p.format;
	}
	write(p.fd, p.buff, p.buffer_index);
	return (p.len);
}
