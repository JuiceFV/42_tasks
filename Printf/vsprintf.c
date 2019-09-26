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
static		void evaluate_flags(t_printf_format *frmt, const char **format,
															int while_flag)
{
	unsigned int n;

	fmrt->flags = 0U;
	while (n || while_flag)
	{
		if (while_flag)
				while_flag = 0;
		if (**format == '0' || **format == '-' || **format == '+' || **format == ' '
				|| **format == '#')
		{
			if (**format == '0')
					frmt->flags = FLAGS_ZEROPAD;
			if (**format == '-')
					frmt->flags = FLAGS_LEFT;
			if (**format == '+')
					frmt->flags = FLAGS_PLUS;
			if (**format == ' ')
					frmt->flags = FLAGS_SPACE;
			if (**format == '#')
					frmt->flags = FLAGS_HASH;
			(*format)++;
			n = 1U;
		}
		n = 0U;
	}
}

static void evaluate_width_field(t_printf_format *frmt, const char **format)
{
	const int w;

	frmt->width = 0U;
	if (ft_isdigit(**format))
			frmt->width = ft_atoi(*format);
	else if (**format == '*')
	{
		w = va_arg(va, int);
		if (w < 0)
		{
			frmt->flags |= FLAGS_LEFT;
			width = (unsigned int)-w;
		}
		else
			frmt->width = (unsigned int)w;
		(*format)++;
	}
}

static void evaluate_precision_field(t_printf_format *frmt, const char **format)
{
	const int precision;

	frmt->prec = 0U;
	if (**format == '.')
	{
		frmt->flags |= FLAGS_PRECISION;
		(*format)++;
		if (ft_isdigit(**format))
				frmt->prec = ft_atoi(*format);
		else if (**format == '*')
		{
			precision = (int)va_arg(va, int);
			frmt->prec = precision > 0 ? (unsigned int)precision : 0U;
			(*format)++;
		}
	}
}

static void evaluate_length_field(t_printf_format *frmt, const char **format)
{
	if (**format == 'l' || **format = 'h')
	{
			frmt->flags |= **format == 'l' ? FLAGS_LONG : FLAGS_SHORT;
			(*format)++;
			if (**format == 'l' || **format == 'h')
			{
					frmt->flags |= **format == 'l' ? FLAGS_LONG_LONG : FLAGS_CHAR;
					(*format)++;
			}
	}
	else if (**format == 't' || **format == 'j' || **format == 'z')
	{
		if (**format == 't')
				frmt->flags |= (sizeof(ptrdiff_t) == sizeof(long) ? FLAGS_LONG :
																														FLAGS_LONG_LONG);
		else if (**format == 'j')
				frmt->flags |= (sizeof(intmax_t) == sizeof(long) ? FLAGS_LONG :
																													 FLAGS_LONG_LONG);
		else if (**format == 'z')
				frmt->flags |= (sizeof(size_t) == sizeof(long) ? FLAGS_LONG :
																											 		 FLAGS_LONG_LONG);
		(*format)++;
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
		evaluate_flags(&frmt, &format, 1);
		evaluate_width_field(&frmt, &format);
		evaluate_precision_field(&frmt, &format);
		evaluate_length_field(&frmt, &format);
	}
}
