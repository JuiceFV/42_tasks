/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:07:35 by cspider           #+#    #+#             */
/*   Updated: 2019/10/06 16:37:56 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ev_s(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	char	*arg;
	int		res;

	if (sp->len_mod == 'l')
		return (ev_ws(sp, frmt, ap));
	else
		arg = va_arg(ap, char *);
	if (arg == NULL)
		arg = "(null)";
	res = (sp->precision >= 0 ? MIN(ft_strlen(arg), (size_t)sp->precision)
			: ft_strlen(arg));
	sp->precision = -1;
	ft_vector_append(frmt, (void *)arg, res);
	return (res);
}

static int	wchar_exception(wchar_t *c)
{
	if ((*c >= 0xD800 && *c <= 0xDBFF) ||
		(*c >= 0xDC00 && *c <= 0xDFFF) ||
		(*c < 0) ||
		(MB_CUR_MAX == 1 && *c >= 0x100))
		return (-1);
	if (MB_CUR_MAX == 1 && (*c >= 0x80 && *c < 0x100))
		*c -= 256;
	return (1);
}

int			ev_wc(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	wint_t	arg;
	size_t	res;

	(void)sp;
	arg = va_arg(ap, wint_t);
	sp->precision = -1;
	ft_vector_reserve(frmt, 4);
	if ((arg >= 0xD800 && arg <= 0xDBFF) ||
		(arg >= 0xDC00 && arg <= 0xDFFF) ||
		(arg < 0) ||
		(MB_CUR_MAX == 1 && arg >= 0x100))
		return (-1);
	if (MB_CUR_MAX == 1 && (arg >= 0x80 && arg < 0x100))
		arg -= 256;
	res = ft_widetoa((char *)VECTOR_END(frmt), arg);
	if (res == 0)
		return (-1);
	frmt->size += res;
	return ((int)res);
}

int			ev_ws(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	wchar_t *arg;
	size_t	len;
	wchar_t *ptr;

	arg = va_arg(ap, wchar_t *);
	if (arg == NULL)
		arg = L"(null)";
	ptr = arg;
	while (*ptr)
	{
		if (wchar_exception(ptr) == -1)
			return (-1);
		ptr++;
	}
	ft_vector_reserve(frmt, 4 * (ptr - arg));
	if (sp->precision >= 0)
		len = ft_wstrnconv((char *)VECTOR_END(frmt), arg, sp->precision);
	else
		len = ft_wstrconv((char *)VECTOR_END(frmt), arg);
	sp->precision = -1;
	frmt->size += len;
	return (len);
}

int			ev_c(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	unsigned char	arg;

	(void)sp;
	if (sp->len_mod == 'l')
		return (ev_wc(sp, frmt, ap));
	else
		arg = (char)va_arg(ap, int);
	sp->precision = -1;
	ft_vector_append(frmt, (void *)&arg, 1);
	return (1);
}
