/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifs_for_itoa_dif_types.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:12:31 by cspider           #+#    #+#             */
/*   Updated: 2019/09/20 18:28:35 by cspider          ###   ########.fr       */
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
