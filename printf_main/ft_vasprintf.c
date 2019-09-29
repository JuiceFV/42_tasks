#include "ft_printf.h"

static  const char *pf_evaluate_prec(const char *s,
                                    t_specifier *sp, va_list ap)
{
    if (*s == '*')
    {
        sp->precision = va_arg(ap, unsigned);
        return (s + 1);
    }
    sp->precision = ft_atoi(s);
    while (ft_isdigit(*s))
        s++;
    return (s);
}
