/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:40:53 by olongbot          #+#    #+#             */
/*   Updated: 2019/10/06 16:41:05 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		putnbr_hex(int number, int rem, t_vector *frmt, int col)
{
	const char *base = "0123456789abcdef";

	if (rem > 1)
		putnbr_hex(number / 16, rem - 1, frmt, col);
	ft_vector_append(frmt, &(base[number % 16]), 1);
	if ((col % 2 == 1) && (rem == 2))
		ft_vector_append(frmt, " ", 1);
}

static void		putchar_hex(unsigned char const c, t_vector *frmt)
{
	if (c >= ' ' && c <= '~')
		ft_vector_append(frmt, &c, 1);
	else
		ft_vector_append(frmt, ".", 1);
}

static void		print_mem(const void *addr, size_t size, t_vector *frmt)
{
	const unsigned char *ptr = addr;
	size_t				i;
	size_t				col;

	i = 0;
	while (i < size)
	{
		col = -1;
		while (++col < 16 && col + i < size)
			putnbr_hex(*(ptr + i + col), 2, frmt, col);
		while (col < 16)
		{
			ft_vector_append(frmt, "  ", 2);
			if (col % 2 == 1)
				ft_vector_append(frmt, " ", 1);
			col++;
		}
		col = -1;
		while (++col < 16 && col + i < size)
			putchar_hex(*(ptr + i + col), frmt);
		ft_vector_append(frmt, "\n", 1);
		i += 16;
	}
}

int				ev_m(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	int *arg;

	arg = va_arg(ap, int *);
	print_mem(arg, sp->size, frmt);
	return (1);
}
/*
** TODO
** Finished | -
** Norme 	| -
** Errors	| -
** Logic 	| -
** Checked	| -
** included	| -
*/
