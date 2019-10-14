/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_date.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:39:14 by olongbot          #+#    #+#             */
/*   Updated: 2019/10/06 16:39:26 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	date_format(t_vector *frmt, long *res_date)
{
	const char *mon[12] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November",
		"December"};

	ft_vector_append(frmt, ft_itoa(res_date[3]),
			ft_strlen(ft_itoa(res_date[3])));
	ft_vector_append(frmt, " ", 1);
	ft_vector_append(frmt, mon[res_date[4]],
			ft_strlen(mon[res_date[4]]));
	ft_vector_append(frmt, " ", 1);
	ft_vector_append(frmt, ft_itoa(res_date[5]),
			ft_strlen(ft_itoa(res_date[5])));
}

static void	time_format(t_vector *frmt, long *res_date)
{
	if (res_date[2] < 10)
		ft_vector_append(frmt, "0", 1);
	ft_vector_append(frmt, ft_itoa(res_date[2]),
			ft_strlen(ft_itoa(res_date[2])));
	ft_vector_append(frmt, ":", 1);
	if (res_date[1] < 10)
		ft_vector_append(frmt, "0", 1);
	ft_vector_append(frmt, ft_itoa(res_date[1]),
			ft_strlen(ft_itoa(res_date[1])));
	ft_vector_append(frmt, ":", 1);
	if (res_date[0] < 10)
		ft_vector_append(frmt, "0", 1);
	ft_vector_append(frmt, ft_itoa(res_date[0]),
			ft_strlen(ft_itoa(res_date[0])));
}

int			ev_k(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	long long arg;

	arg = va_arg(ap, long long);
	if (sp->size == 1)
		date_format(frmt, ft_epochtodate(arg));
	else if (sp->size == 2)
		time_format(frmt, ft_epochtodate(arg));
	else
	{
		date_format(frmt, ft_epochtodate(arg));
		ft_vector_append(frmt, ", ", 2);
		time_format(frmt, ft_epochtodate(arg));
	}
	return (1);
}
