#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     res;

    va_start(ap, format);
    res = ft_vprintf(format, ap);
    va_end(ap);
    return (res);
}

