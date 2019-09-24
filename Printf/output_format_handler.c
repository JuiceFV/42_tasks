/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:07:26 by cspider           #+#    #+#             */
/*   Updated: 2019/09/24 20:15:23 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ntoa_format(t_printf_format frmt, char *buf)
{
	if (!(frmt.flags & FLAGS_LEFT))
		if (frmt.width && (frmt.flags & FLAGS_ZEROPAD) && (frmt.neg ||
					(frmt.flags & (FLAGS_PLUS | FLAGS_SPACE))))
			frmt.width--;
	while ((frmt.len < frmt.prec) && (frmt.len < PRINTF_NTOA_BUFFER_SIZE))
		buf[frmt.len++] = '0';
	while ((frmt.flags & FLAGS_ZEROPAD) && (frmt.len < frmt.width) &&
			(frmt.len < PRINTF_NTOA_BUFFER_SIZE))
		buf[frmt.len++] = '0';
	if (frmt.flags & FLAGS_HASH)
	{
		if (!(frmt.flags & FLAGS_PRECISION) && frmt.len &&
				((frmt.len == frmt.prec) || (frmt.len == frmt.width)))
			if (--frmt.len && (frmt.base == 16U))
				frmt.len--;
		hash_handle_rules(frmt.base, &buf, &frmt.len, frmt.flags);
	}
	mps_handle_rules(&frmt.len, frmt.neg, frmt.flags, &buf);
	return (out_rev(frmt, buf));
}

size_t	ntoa_long(t_printf_format frmt, unsigned long value)
{
	char			buf[PRINTF_NTOA_BUFFER_SIZE];
	size_t			len;
	char			digit;

	len = 0U;
	if (!value)
		frmt.flags &= ~FLAGS_HASH;
	if (!(frmt.flags & FLAGS_PRECISION) || value)
	{
		while (value && (frmt.len < PRINTF_NTOA_BUFFER_SIZE))
		{
			digit = (char)(value % (unsigned long)frmt.base);
			if (digit < 10)
				buf[frmt.len++] = digit + '0';
			else if (frmt.flags & FLAGS_UPPERCASE)
				buf[frmt.len++] = 'A' + digit - 10;
			else
				buf[frmt.len++] = 'a' + digit - 10;
			value /= (unsigned long)frmt.base;
		}
	}
	frmt.len = len;
	return (ntoa_format(frmt, buf));
}

size_t	ntoa_long_long(t_printf_format frmt, unsigned long long value)
{
	char			buf[PRINTF_NTOA_BUFFER_SIZE];
	size_t			len;
	char			digit;

	len = 0U;
	if (!value)
		frmt.flags &= ~FLAGS_HASH;
	if (!(frmt.flags & FLAGS_PRECISION) || value)
	{
		while (value && (frmt.len < PRINTF_NTOA_BUFFER_SIZE))
		{
			digit = (char)(value % (unsigned long long)frmt.base);
			if (digit < 10)
				buf[frmt.len++] = digit + '0';
			else if (frmt.flags & FLAGS_UPPERCASE)
				buf[frmt.len++] = 'A' + digit - 10;
			else
				buf[frmt.len++] = 'a' + digit - 10;
			value /= (unsigned long long)frmt.base;
		}
	}
	frmt.len = len;
	return (ntoa_format(frmt, buf));
}

size_t	ftoa(t_printf_format frmt, double value)
{
	char					buf[PRINTF_FTOA_BUFFER_SIZE];
	t_ftoa_var				obj;
	size_t					ret;

	frmt.len = 0U;
	obj.diff = 0.0;
	set_pow10(obj.pow10);
	ret = ftoa_test_for_special_values(frmt, value, &obj.ftfsv_flag);
	if (obj.ftfsv_flag != 1)
		return (ret);
	obj.negative = (value < 0);
	value = obj.negative ? 0 - value : value;
	prec_ftoa(&frmt, &frmt.len, buf);
	obj.whole = (int)value;
	obj.tmp = (value - obj.whole) * obj.pow10[frmt.prec];
	obj.frac = (unsigned long)obj.tmp;
	obj.diff = obj.tmp - obj.frac;
	diff_checker_ftoa(&obj, frmt);
	repartition(&obj, buf, &frmt, value);
	repartition_2(&obj, &frmt, buf);
	return (out_rev(frmt, buf));
}

size_t	etoa(t_printf_format frmt, double value)
{
	t_etoa_var obj;

	if ((value != value) || (value > DBL_MAX) || (value < -DBL_MAX))
		return (ftoa(frmt, value));
	obj.neg = (value < 0);
	value = obj.neg ? -value : value;
	if (!(frmt.flags & FLAGS_PRECISION))
		frmt.prec = PRINTF_DEFAULT_FLOAT_PRECISION;
	exp_compute(&obj, value);
	exp_format_1(&obj, value, &frmt);
	exp_format_2(&obj, &value, &frmt);
	return (frmt.index);
}
