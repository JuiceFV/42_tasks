#include "ft_printf.h"

int	ev_cq(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	unsigned char	arg;
	int				i;

	(void)sp;
	i = 0;
	if (sp->len_mod == 'l')
		return (ev_wc(sp, frmt, ap));
	else
		arg = (char)va_arg(ap, int);
	sp->precision = -1;
	while (i < sp->size)
	{
		ft_vector_append(frmt, (void *)&arg, 1);
		i++;
	}
	return (1);
}