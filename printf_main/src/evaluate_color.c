/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:34:39 by olongbot          #+#    #+#             */
/*   Updated: 2019/10/06 16:34:58 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ev_w(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	int index;

	(void)ap;
	(void)sp;
	index = sp->size;
	sp->size = 0;
	if (index > 6)
		index = 0;
	if (index != 0)
		index += 30;
	ft_vector_append(frmt, "\e[", 2);
	ft_vector_append(frmt, "0;", 2);
	ft_vector_append(frmt, ft_itoa(index), ft_strlen(ft_itoa(index)));
	ft_vector_append(frmt, "m", 1);
	return (1);
}

int	ev_cw(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	int index;

	(void)ap;
	(void)sp;
	index = sp->size;
	sp->size = 0;
	if (index > 6)
		index = 0;
	if (index != 0)
		index += 30;
	ft_vector_append(frmt, "\e[", 2);
	ft_vector_append(frmt, "1;", 2);
	ft_vector_append(frmt, ft_itoa(index), ft_strlen(ft_itoa(index)));
	ft_vector_append(frmt, "m", 1);
	return (1);
}
/*
** TODO
** Finished | +
** Norme 	| -
** Errors	| -
** Logic 	| -
** Checked	| -
** included	| -
*/
