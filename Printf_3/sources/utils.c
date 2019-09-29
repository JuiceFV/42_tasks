/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 16:26:48 by cspider           #+#    #+#             */
/*   Updated: 2019/09/29 16:27:29 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	buffer(t_format *p, void *new, size_t size)
{
	int			diff;
	long long	new_i;

	new_i = 0;
	while (PF_BUF_SIZE - p->buffer_index < (int)size)
	{
		diff = PF_BUF_SIZE - p->buffer_index;
		ft_memcpy((char *)(p->buff + p->buffer_index), (char *)(new + new_i), diff);
		size -= diff;
		new_i += diff;
		p->buffer_index += diff;
		p->len += diff;
		write(p->fd, p->buff, p->buffer_index);
		p->buffer_index = 0;
	}
	ft_memcpy((char *)(p->buff + p->buffer_index), (char *)(new + new_i), size);
	p->buffer_index += size;
	p->len += size;
}

void	print_pointer_address(t_format *p)
{
	void	*pointer;

	pointer = va_arg(p->ap, void *);
	p->f &= ~F_SHARP;
	p->min_length -= (p->f & F_ZERO ? 2 : 0);
	p->padding = (p->printed > p->min_length - 3) ? 0 :
		p->min_length - 3 - p->printed;
	p->f |= F_SHARP;
	p->f |= F_POINTER;
	itoa_base_printf((uintmax_t)pointer, 16, p);
}

void		padding(t_format *p, int n)
{
	if (!p->padding)
		return ;
	p->c = 32 | (p->f & F_ZERO);
	if (!n && !(p->f & F_MINUS))
		while (p->padding--)
			buffer(p, &p->c, 1);
	else if (n && (p->f & F_MINUS))
		while (p->padding--)
			buffer(p, &p->c, 1);
}

