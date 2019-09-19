/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:07:26 by cspider           #+#    #+#             */
/*   Updated: 2019/09/19 20:44:18 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	out_rev(t_struct_for_itoa prtf, const char *buf, unsigned int width)
{
	size_t			start_index;
	unsigned int	i;

	start_index = prtf.index;
	i = prtf.len;
	if (!(prtf.flags & FLAGS_LEFT) && !(prtf.flags & FLAGS_ZEROPAD))
		while (i++ < width)
			prtf.out(' ', prtf.buffer, prtf.index++, prtf.maxlen);
	while (prtf.len)
		prtf.out(buf[--prtf.len], prtf.buffer, prtf.index++, prtf.maxlen);
	if (prtf.flags & FLAGS_LEFT)
		while (prtf.index - start_index < width)
			prtf.out(' ', prtf.buffer, prtf.index++, prtf.maxlen);
	return (prtf.index);
}

size_t	ntoa_format(t_struct_for_itoa s, char *buf,
							t_struct_for_itoa_2 s2, unsigned int width)
{
	if (!(s.flags & FLAGS_LEFT))
		if (width && (s.flags & FLAGS_ZEROPAD) && (s2.neg || (s.flags &
						(FLAGS_PLUS | FLAGS_SPACE))))
			width--;
	while ((s.len < s2.prec) && (s.len < PRINTF_NTOA_BUFFER_SIZE))
		buf[s.len++] = '0';
	while ((s.flags & FLAGS_ZEROPAD) && (s.len < width) && (s.len <
				PRINTF_NTOA_BUFFER_SIZE))
		buf[s.len++] = '0';
	if (s.flags & FLAGS_HASH)
	{
		if (!(s.flags & FLAGS_PRECISION) && s.len && ((s.len == s2.prec)
					|| (s.len == width)))
			if (--s.len && (s2.base == 16U))
				s.len--;
		ifs_for_ntoa(s2.base, &buf, &s.len, s.flags);
	}
	ifs_for_ntoa_2(&s.len, s2.neg, s.flags, &buf);
	return (out_rev(s, buf, width));
}

size_t	ntoa_long(t_struct_for_itoa s, t_struct_for_itoa_2 s2,
					unsigned long value, unsigned int width)
{
	char			buf[PRINTF_NTOA_BUFFER_SIZE];
	size_t			len;
	char			digit;

	len = 0U;
	if (!value)
		s.flags &= ~FLAGS_HASH;
	if (!(s.flags & FLAGS_PRECISION) || value)
	{
		while (value && (len < PRINTF_NTOA_BUFFER_SIZE))
		{
			digit = (char)(value % (unsigned long)s2.base);
			if (digit < 10)
				buf[len++] = digit + '0';
			else if (s.flags & FLAGS_UPPERCASE)
				buf[len++] = 'A' + digit - 10;
			else
				buf[len++] = 'a' + digit - 10;
			value /= (unsigned long)s2.base;
		}
	}
	s.len = len;
	return (ntoa_format(s, buf, s2, width));
}

size_t	ntoa_long_long(t_struct_for_itoa s, t_struct_for_itoa_2 s2,
						unsigned long long value, int width)
{
	char			buf[PRINTF_NTOA_BUFFER_SIZE];
	size_t			len;
	char			digit;

	len = 0U;
	if (!value)
		s.flags &= ~FLAGS_HASH;
	if (!(s.flags & FLAGS_PRECISION) || value)
	{
		while (value && (len < PRINTF_NTOA_BUFFER_SIZE))
		{
			digit = (char)(value % (unsigned long long)s2.base);
			if (digit < 10)
				buf[len++] = digit + '0';
			else if (s.flags & FLAGS_UPPERCASE)
				buf[len++] = 'A' + digit - 10;
			else
				buf[len++] = 'a' + digit - 10;
			value /= (unsigned long long)s2.base;
		}
	}
	s.len = len;
	return (ntoa_format(s, buf, s2, width));
}
