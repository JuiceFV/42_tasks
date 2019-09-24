/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifs_for_itoa_dif_types.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:12:31 by cspider           #+#    #+#             */
/*   Updated: 2019/09/22 16:26:55 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hash_handle_rules(unsigned int base, char **buf, size_t *len,
						unsigned int flags)
{
	if ((base == 16U) && !(flags & FLAGS_UPPERCASE) &&
			(*len < PRINTF_NTOA_BUFFER_SIZE))
	{
		*buf[(*len)++] = 'x';
	}
	else if ((base == 16U) &&
			(flags & FLAGS_UPPERCASE) && (*len < PRINTF_NTOA_BUFFER_SIZE))
	{
		*buf[(*len)++] = 'X';
	}
	else if ((base == 2U) &&
			(*len < PRINTF_NTOA_BUFFER_SIZE))
	{
		*buf[(*len)++] = 'b';
	}
	if (*len < PRINTF_NTOA_BUFFER_SIZE)
	{
		*buf[(*len)++] = '0';
	}
}

void	mps_handle_rules(size_t *len, int neg, unsigned int flags,
					char **buf)
{
	if (*len < PRINTF_NTOA_BUFFER_SIZE)
	{
		if (neg)
			*buf[(*len)++] = '-';
		else if (flags & FLAGS_PLUS)
			*buf[(*len)++] = '+';
		else if (flags & FLAGS_SPACE)
			*buf[(*len)++] = ' ';
	}
}

void	set_pow10(double pow10[])
{
	pow10[0] = 1;
	pow10[1] = 10;
	pow10[2] = 100;
	pow10[3] = 1000;
	pow10[4] = 10000;
	pow10[5] = 100000;
	pow10[6] = 1000000;
	pow10[7] = 10000000;
	pow10[8] = 100000000;
	pow10[9] = 1000000000;
}

size_t	ftoa_test_for_special_values(t_printf_format frmt, double value,
										int *flag)
{
	if (value != value)
	{
		frmt.len = 3;
		return (out_rev(frmt, "nan"));
	}
	if (value < -DBL_MAX)
	{
		frmt.len = 4;
		return (out_rev(frmt, "fni-"));
	}
	if (value > DBL_MAX)
	{
		frmt.len = (frmt.flags & FLAGS_PLUS) ? 4U : 3U;
		return (out_rev(frmt, (frmt.flags & FLAGS_PLUS) ? "fni+" : "fni"));
	}
	if ((value > PRINTF_MAX_FLOAT) || (value < -PRINTF_MAX_FLOAT))
		return (etoa(frmt, value));
	*flag = 1;
	return (0U);
}

void	prec_ftoa(t_printf_format *frmt, size_t *len, char buf[])
{
	if (!(frmt->flags & FLAGS_PRECISION))
		frmt->prec = PRINTF_DEFAULT_FLOAT_PRECISION;
	while ((*len < PRINTF_FTOA_BUFFER_SIZE) && (frmt->prec > 9U))
	{
		buf[(*len)++] = '0';
		frmt->prec--;
	}
}
