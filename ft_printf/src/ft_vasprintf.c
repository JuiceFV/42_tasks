/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 12:51:42 by cspider           #+#    #+#             */
/*   Updated: 2019/10/06 17:02:51 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*evaluate_prec(const char *s,
		t_specifiers *sp, va_list ap)
{
	if (*s == '*')
	{
		sp->precision = va_arg(ap, unsigned);
		return (s + 1);
	}
	sp->precision = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	return (s);
}

static const char	*evaluate_size(char const *s,
							t_specifiers *sp, va_list ap)
{
	va_list	temp;
	int		nsize;
	int		i;

	va_copy(temp, ap);
	if (*s == '*')
	{
		sp->size = va_arg(ap, unsigned);
		s++;
		nsize = ft_atoi(s);
		while (ft_isdigit(*s))
			s++;
		i = -1;
		while (++i < nsize)
			sp->size = va_arg(temp, unsigned);
		if (*s != '$' && nsize != 0)
			sp->size = nsize;
	}
	else
	{
		sp->size = 0;
		while (ft_isdigit(*s))
			sp->size = 10 * (sp->size) + *s++ - '0';
	}
	return (s);
}

static	void		set_len_modifier(char c, char *lm)
{
	if (c == 'h' && *lm == 'h')
		*lm = ft_toupper(c);
	else if (c == 'l' && *lm == 'l')
		*lm = '7';
	else if (*lm == 0 || !(c == 'h' && *lm != 'H'))
		*lm = c;
}

static const char	*match(char const *s, t_specifiers *sp, va_list ap)
{
	*sp = NEW_SPECIFIER;
	while (*(++s) != '\0')
	{
		if (*s == '.')
			s = evaluate_prec(s + 1, sp, ap) - 1;
		else if (*s == '\'')
			sp->quote = 1;
		else if (*s == '$')
		{
			sp->dollar_size = sp->size;
			sp->size = 0;
		}
		else if ((*s >= '1' && *s <= '9') || *s == '*')
			s = evaluate_size(s, sp, ap) - 1;
		else if ((char_index(*s, "0+- #_")) >= 0)
			sp->flags.f[char_index(*s, "0+- #_")] = 1;
		else if ((char_index(*s, "hljztL")) >= 0)
			set_len_modifier(*s, &(sp->len_mod));
		else if ((sp->conv = *s))
			return (s + 1);
	}
	return (s);
}

int					ft_vasprintf(char **ret, char const *s, va_list ap)
{
	t_vector		frmt;
	t_specifiers	sp;
	va_list			frmt_ap;

	va_copy(frmt_ap, ap);
	frmt = VECTOR(char);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s = match(s, &sp, frmt_ap);
			if (sp.conv && evaluate_all(&sp, &frmt, ap, frmt_ap) == -1)
			{
				ft_vector_resize(&frmt, sp.sp_index);
				ft_vector_trim(&frmt);
				*ret = frmt.data;
				return (-1);
			}
			sp.sp_index = frmt.size;
		}
		s = next_spec(s, &frmt);
	}
	ft_vector_trim(&frmt);
	*ret = frmt.data;
	return (frmt.size - 1);
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
