/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:27:26 by cspider           #+#    #+#             */
/*   Updated: 2019/09/24 20:46:02 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	eval_flags_width_(t_printf_format *frmt, const char **format)
{
	unsigned int n;

	if (**fomat == '0')
	{
		fmrt->flags |= FLAGS_ZEROPAD;
		format++;
		n = 1U;
	}
	else if (**format == '-')
	{

	}
	else if (**format == '+')
	{

	}
	else if (**format == ' ')
	{

	}
	else if (**format == '#')
	{

	}
}

int				vsnprintf(t_printf_format frmt, const char *format, va_list va)
{
	frmt.index = 0U;
	if (!frmt.buffer)
		frmt.out = out_null;
	while(*format)
	{
		if (*format != '%')
		{
			frmt.out(*format, frmt.buffer, frmt.index, frmt.maxlen);
			format++;
			continue ;
		}
		else
			format++;
	}
}
