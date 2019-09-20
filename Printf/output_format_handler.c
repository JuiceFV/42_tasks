/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:07:26 by cspider           #+#    #+#             */
/*   Updated: 2019/09/20 18:30:49 by cspider          ###   ########.fr       */
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
	char 					buf[PRINTF_FTOA_BUFFER_SIZE];
	size_t					len;
	double					diff;
	static	double			pow10[10];
	int						whole;
	double					tmp;
	unsigned	long		frac;
	unsigned	int			count;

	len = 0U;
	diff = 0.0;
	set_pow10(pow10);
}
