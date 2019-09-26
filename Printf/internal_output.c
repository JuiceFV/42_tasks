/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_oper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:54:27 by cspider           #+#    #+#             */
/*   Updated: 2019/09/20 17:35:21 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline	void	out_buffer(char c, void *buffer, size_t index, size_t maxlen)
{
	if (index < maxlen)
		((char *)buffer)[index] = c;
}

inline	void	out_null(char c, void *buffer, size_t index, size_t maxlen)
{
	(void)c;
	(void)buffer;
	(void)index;
	(void)maxlen;
}

inline	void	out_char(char c, void *buffer, size_t index, size_t maxlen)
{
	(void)index;
	(void)maxlen;
	(void)buffer;
	if (c)
		ft_putchar(c);
}

inline	void	out_func(char c, void *buffer, size_t index, size_t maxlen)
{
	if (buffer)
	{
		(void)index;
		(void)maxlen;
		if (c)
			((t_out_func_wrap_type*)buffer)->
				func(c, ((t_out_func_wrap_type*)buffer)->arg);
	}
}

size_t			out_rev(t_printf_format frmt, const char *buf)
{
	size_t			start_index;
	unsigned int	i;

	start_index = frmt.index;
	i = frmt.len;
	if (!(frmt.flags & FLAGS_LEFT) && !(frmt.flags & FLAGS_ZEROPAD))
		while (i++ < frmt.width)
			frmt.out(' ', frmt.buffer, frmt.index++, frmt.maxlen);
	while (frmt.len)
		frmt.out(buf[--frmt.len], frmt.buffer, frmt.index++, frmt.maxlen);
	if (frmt.flags & FLAGS_LEFT)
		while (frmt.index - start_index < frmt.width)
			frmt.out(' ', frmt.buffer, frmt.index++, frmt.maxlen);
	return (frmt.index);
}