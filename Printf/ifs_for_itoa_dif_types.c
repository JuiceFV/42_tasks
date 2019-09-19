/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifs_for_itoa_dif_types.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:12:31 by cspider           #+#    #+#             */
/*   Updated: 2019/09/19 20:18:31 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ifs_for_ntoa(unsigned int base, char **buf, size_t *len,
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

void	ifs_for_ntoa_2(size_t *len, int neg, unsigned int flags,
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
