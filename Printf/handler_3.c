/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:02:30 by cspider           #+#    #+#             */
/*   Updated: 2019/09/24 20:25:26 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	reclaim(t_printf_format frmt, t_etoa_var obj)
{
	frmt.neg = (obj.expval < 0);
	frmt.base = 10;
	frmt.prec = 0;
	frmt.width = obj.minwidth - 1;
	frmt.flags = FLAGS_ZEROPAD | FLAGS_PLUS;
	frmt.index = ntoa_long(frmt, (obj.expval < 0) ? -obj.expval : obj.expval);
}

static	void	output_the_exponent_part(t_etoa_var *obj,
										t_printf_format *frmt)
{
	if (obj->minwidth)
	{
		frmt->out((frmt->flags & FLAGS_UPPERCASE) ? 'E' : 'e',
				frmt->buffer, frmt->index++, frmt->maxlen);
		reclaim(*frmt, *obj);
		if (frmt->flags & FLAGS_LEFT)
		{
			while (frmt->index - obj->start_index < frmt->width)
				frmt->out(' ', frmt->buffer, frmt->index++, frmt->maxlen);
		}
	}
}

void			exp_format_2(t_etoa_var *obj, double *value,
		t_printf_format *frmt)
{
	unsigned int flags_temp;
	unsigned int width_temp;

	obj->fwidth = frmt->width;
	if (frmt->width > (unsigned)obj->minwidth)
		obj->fwidth = -obj->minwidth;
	else
		obj->fwidth = 0U;
	if ((frmt->flags & FLAGS_LEFT) && obj->minwidth)
		obj->fwidth = 0U;
	if (obj->expval)
		(*value) /= obj->conv.F;
	obj->start_index = frmt->index;
	flags_temp = frmt->flags;
	width_temp = frmt->width;
	frmt->flags &= ~FLAGS_ADAPT_EXP;
	frmt->width = obj->fwidth;
	frmt->index = ftoa(*frmt, obj->neg ? -(*value) : (*value));
	frmt->flags = flags_temp;
	frmt->width = width_temp;
	output_the_exponent_part(obj, frmt);
}
