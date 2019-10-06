#include "ft_printf.h"

int	quote_div(t_vector *frmt, char c)
{
	t_vector	temp;
	int			i;

	i = 1;
	temp = VECTOR(char);
	while (ft_isdigit((VECTOR_LAST(frmt))[0]))
	{
		ft_vector_append(&temp, VECTOR_LAST(frmt), 1);
		ft_vector_pop_back(frmt, 1);
		if (i % 3 == 0)
			ft_vector_append(&temp, &c, 1);
		i++;
	}
	while (temp.size > 0)
	{
		ft_vector_append(frmt, VECTOR_LAST(&temp), 1);
		ft_vector_pop_back(&temp, 1);
	}
	return (i / 3);
}
/*
** if first bit of info is on we using caps if second bit is on we using unsigned
*/
int	_itoa_base(t_vector *frmt, intmax_t n, int b, char info)
{
	int 				res;
	const uintmax_t		ui_n = (uintmax_t)n;
	const char *const	base = 

	(info & 1 ? "0123456789ABCDEF" : "0123456789abcdef");
	res = 1;
	if (info & 2 ? (uintmax_t)b <= ui_n : n <= -b || b <= n)
		res += _itoa_base(frmt, (info & 2 ?
			(intmax_t)(ui_n / b) : n / b), b, info);
	ft_vector_append(frmt, (void *)(base +
		(info & 2 ? (size_t)(ui_n % b) : ABS(n % b))), 1);
	return (res);
}

int ev_o(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	int sharp;

	sharp = 0;
	if (sp->flags.n.sharp)
	{
		ft_vector_append(frmt, "0", 1);
		sharp = 1;
	}
	sp->conv = 'o';
	return (unsigned_integer(sp, frmt, ap, 8) + sharp);
}

/*
** unsigned integer into binary representation bbbb.
*/

int ev_b(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	if (sp->flags.n.sharp)
		ft_vector_append(frmt, "b", 1);
	return (unsigned_integer(sp, frmt, ap, 2));
}

/*
** returns the number of characters written so far by this call to the function.
*/

int ev_n(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	int *arg;

	arg = va_arg(ap, void *);
	if (!arg)
		return (0);
	sp->size = 0;
	sp->precision = -1;
	if (sp->len_mod == 'H')
		*(char *)arg = (char)frmt->size;
	else if (sp->len_mod == 'h')
		*(short *)arg = (short)frmt->size;
	else if (sp->len_mod == 'l' || sp->len_mod == 'z')
		*(long *)arg = (long)frmt->size;
	else if (sp->len_mod == '7')
		*(long long *)arg = (long long)frmt->size;
	else if (sp->len_mod == 'j')
		*(intmax_t *)arg = (intmax_t)frmt->size;
	else
		*(int *)arg = (int)frmt->size;
	return (0);
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