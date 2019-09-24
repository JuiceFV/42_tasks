/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:27:07 by cspider           #+#    #+#             */
/*   Updated: 2019/09/24 18:02:20 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	diff_checker_ftoa(t_ftoa_var *obj, t_printf_format frmt)
{
	if (obj->diff > 0.5)
	{
		obj->frac++;
		if (obj->frac >= obj->pow10[frmt.prec])
		{
			obj->frac = 0;
			obj->whole++;
		}
	}
	else if (obj->diff < 0.5)
	{
	}
	else if ((obj->frac == 0U) || (obj->frac & 1U))
		obj->frac++;
}

void	repartition(t_ftoa_var *obj, char buf[], t_printf_format *frmt,
			double value)
{
	if (frmt->prec == 0U)
	{
		obj->diff = value - (double)obj->whole;
		if ((!(obj->diff < 0.5) || (obj->diff > 0.5)) && (obj->whole & 1))
			obj->whole++;
	}
	else
	{
		obj->count = frmt->prec;
		while (frmt->len < PRINTF_FTOA_BUFFER_SIZE)
		{
			obj->count--;
			buf[frmt->len++] = (char)(48U + (obj->frac % 10U));
			if (!(obj->frac /= 10))
				break ;
		}
		while ((frmt->len < PRINTF_FTOA_BUFFER_SIZE) &&
				(obj->count-- > 0U))
			buf[frmt->len++] = '0';
		if (frmt->len < PRINTF_FTOA_BUFFER_SIZE)
			buf[frmt->len++] = '.';
	}
}

void	repartition_2(t_ftoa_var *obj, t_printf_format *frmt, char buf[])
{
	while (frmt->len < PRINTF_FTOA_BUFFER_SIZE)
	{
		buf[frmt->len++] = (char)(48 + (obj->whole % 10));
		if (!(obj->whole /= 10))
			break ;
	}
	if (!(frmt->flags & FLAGS_LEFT) && (frmt->flags & FLAGS_ZEROPAD))
	{
		if (frmt->width && (obj->negative || (frmt->flags &
						(FLAGS_PLUS | FLAGS_SPACE))))
			frmt->width--;
		while ((frmt->len < frmt->width) && (frmt->len <
					PRINTF_FTOA_BUFFER_SIZE))
			buf[frmt->len++] = '0';
	}
	if (frmt->len < PRINTF_FTOA_BUFFER_SIZE)
	{
		if (obj->negative)
			buf[frmt->len++] = '-';
		else if (frmt->flags & FLAGS_PLUS)
			buf[frmt->len++] = '+';
		else if (frmt->flags & FLAGS_SPACE)
			buf[frmt->len++] = ' ';
	}
}

void	exp_compute(t_etoa_var *obj, double value)
{
	obj->conv.F = value;
	obj->exp2 = (int)((obj->conv.U >> 52U) & 0x07FFU) - 1023;
	obj->conv.U = (obj->conv.U & ((1ULL << 52U) - 1U)) | (1023UL << 50U);
	obj->expval = (int)(0.1760912590558 + obj->exp2 * 0.301029995663981 +
						(obj->conv.F - 1.5) * 0.289529654602168);
	obj->exp2 = (int)(obj->expval * 3.321928094887362 + 0.5);
	obj->z = obj->expval * 2.302585092994046 - obj->exp2 * 0.6931471805599453;
	obj->z2 = obj->z * obj->z;
	obj->conv.U = (uint64_t)(obj->exp2 + 1023) << 52U;
	obj->conv.F *= 1 + 2 * obj->z / (2 - obj->z + (obj->z2 / (6 +
					(obj->z2 / (10 + obj->z2 / 14)))));
	if (value < obj->conv.F)
	{
		obj->expval--;
		obj->conv.F /= 10;
	}
}

void	exp_format_1(t_etoa_var *obj, double value, t_printf_format *frmt)
{
	obj->minwidth = ((obj->expval < 100) && (obj->expval > -100)) ? 4U : 5U;
	if (frmt->flags & FLAGS_ADAPT_EXP)
	{
		if ((value >= 1e-4) && (value < 1e6))
		{
			if ((int)frmt->prec > obj->expval)
				frmt->prec = (unsigned)((int)frmt->prec - obj->expval - 1);
			else
				frmt->prec = 0;
			obj->minwidth = 0U;
			obj->expval = 0;
		}
		else
		{
			if ((frmt->prec > 0) && (frmt->flags & FLAGS_PRECISION))
				frmt->prec--;
		}
	}
}
