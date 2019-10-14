/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:45:53 by cspider           #+#    #+#             */
/*   Updated: 2019/10/06 17:01:01 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ev_di(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	return (signed_integer(sp, frmt, ap, 10));
}

int	ev_u(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	return (unsigned_integer(sp, frmt, ap, 10));
}

int	ev_x(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	if (sp->flags.n.sharp)
		ft_vector_append(frmt, "0x", 2);
	return (unsigned_integer(sp, frmt, ap, 16));
}

int	ev_cx(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	if (sp->flags.n.sharp)
		ft_vector_append(frmt, "0X", 2);
	return (unsigned_integer(sp, frmt, ap, -16));
}

int	ev_p(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	(void)sp;
	ft_vector_append(frmt, "0x", 2);
	sp->len_mod = '7';
	return (unsigned_integer(sp, frmt, ap, 16));
}
