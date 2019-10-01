/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:37:58 by cspider           #+#    #+#             */
/*   Updated: 2019/10/01 19:39:01 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	spec(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	int			i;
	char const	s[] = "sSpdDioOuUxXcCbneEfFgGaAwWTyrqQm";
	void *const t[] = {
	&ev_s, &ev_ws, &ev_p, &ev_di, &ev_di, &ev_di,
	&ev_o, &ev_o, &ev_u, &ev_u, &ev_x, &ev_cx,
	&ev_c, &ev_wc, &ev_b, &ev_n, &ev_e, &ev_ce,
	&ev_f, &ev_cf, &ev_g, &ev_cg, &ev_a, &ev_ca,
	&ev_w, &ev_cw, &ev_ct, &ev_y, &ev_r, &ev_q,
	&ev_cq, &ev_m};

	if (char_index(sp->conv, "DOU") >= 0)
		sp->len_mod = 'l';
	i = 0;
	while (s[i] != '\0' && sp->conv != s[i])
		i++;
	if (s[i] != '\0')
		return (((int (*)())t[i])(sp, frmt, ap));
	ft_vector_append(frmt, &sp->conv, 1);
	sp->precision = -1;
	return (1);
}

char 	*next_spec(char const *s, t_vector *frmt)
{
	char 	*c;

	c = (char*)s;
	while (*c != '\0' && *c != '%')
		c++;
	if (p != s)
		ft_vector_append(frmt, (void *)c, p - s);
	return (p);
}

static	void	eval_prec(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	size_t w_before;
	size_t w_after;
	int    width;
	int	   len;

	w_before = frmt->size;
	width = spec(sp, frmt, ap);
	if (width == -1)
		return (-1);
	w_after = frmt->size;
	len = width;
	if (len < sp->precision && char_index(sp->conv, "diouDOUxXpb") >= 0)
	{
		while (len < sp->precision && ++len)
			ft_vector_append(frmt, "0", 1);
	}
}