#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
    va_list ap;
    int     res;

    va_start(ap, format);
    res = ft_vprintf(format, ap);
    va_end(ap);
    return (res);
}

int		ft_printfln(char const *format, ...)
{
	va_list		ap;
	int			res;

	va_start(ap, format);
	res = ft_vprintf(format, ap);
	va_end(ap);
	ft_printf("\n");
	return (res + 1);
}


int		ft_dprintf(int fd, char const *format, ...)
{
	va_list		ap;
	int			res;

	va_start(ap, format);
	res = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (res);
}


int		ft_asprintf(char **ret, char const *format, ...)
{
	va_list		ap;
	int			res;

	va_start(ap, format);
	res = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (res);
}


char	*ft_rasprintf(int *res, char const *format, ...)
{
	va_list		ap;
	char		*ret;

	va_start(ap, format);
	*res = ft_vasprintf(&ret, format, ap);
	va_end(ap);
	return (ret);
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