/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:37:58 by cspider           #+#    #+#             */
/*   Updated: 2019/10/06 17:06:17 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		spec(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	int			i;
	char const	s[] = "sSpdDioOuUxXcCbneEfFgGaAwWkmQ";
	void *const t[] = {
	&ev_s, &ev_ws, &ev_p, &ev_di, &ev_di, &ev_di,
	&ev_o, &ev_o, &ev_u, &ev_u, &ev_x, &ev_cx,
	&ev_c, &ev_wc, &ev_b, &ev_n, &ev_e, &ev_ce,
	&ev_f, &ev_cf, &ev_g, &ev_cg, &ev_a, &ev_ca,
	&ev_w, &ev_cw, &ev_k, &ev_m, &ev_cq};

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

char			*next_spec(char const *s, t_vector *frmt)
{
	char	*c;

	c = (char*)s;
	while (*c != '\0' && *c != '%')
		c++;
	if (c != s)
		ft_vector_append(frmt, (void *)s, c - s);
	return (c);
}

static int		eval_prec(t_specifiers *sp, t_vector *frmt, va_list ap)
{
	size_t	w_before;
	size_t	w_after;
	int		width;
	int		len;

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
		ft_vector_segswap(frmt, w_after - width, w_after);
	}
	if (sp->size < 0 && sp->precision == -1)
	{
		sp->size = (sp->size < 0) ? -sp->size : sp->size;
		sp->flags.n.minus = 1;
	}
	return (len);
}

static void		handle_dollar(t_specifiers *sp, va_list ap, va_list frmt_ap)
{
	if (sp->dollar_size)
	{
		va_copy(frmt_ap, ap);
		while (--(sp->dollar_size) > 0)
			va_arg(frmt_ap, void *);
	}
}

int				evaluate_all(t_specifiers *sp, t_vector *frmt,
							va_list ap, va_list frmt_ap)
{
	size_t	w_before;
	size_t	w_after;
	int		width;
	int		len;

	handle_dollar(sp, ap, frmt_ap);
	w_before = frmt->size;
	width = eval_prec(sp, frmt, frmt_ap);
	w_after = frmt->size;
	len = w_after - w_before;
	if (len <= sp->size && width != -1)
	{
		if (sp->flags.n.zero && sp->precision <= -1 && !sp->flags.n.minus)
			while (len < sp->size && ++len)
				ft_vector_append(frmt, "0", 1);
		else
			while (len < sp->size && ++len)
				ft_vector_append(frmt, " ", 1);
		if (sp->flags.n.zero && sp->precision <= -1 && !sp->flags.n.minus)
			w_before = w_after - width;
		if (!sp->flags.n.minus)
			ft_vector_segswap(frmt, w_before, w_after);
	}
	return (width);
}

/*
** TODO
** Fixed date func. Recall wchar func's to %r.
** Doesn't evaluated: ev_y, ev_r, ev_cr
** (i will rewrite this func's to wc, ws), ev_q, ev_cq, ev_m
** Finished | -
** Norme 	| -
** Errors	| -
** Logic 	| -
** Checked	| -
** included	| -
*/
