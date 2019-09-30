/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 12:51:42 by cspider           #+#    #+#             */
/*   Updated: 2019/09/30 15:05:57 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*evaluate_prec(const char *s,
                                    t_specifier *sp, va_list ap)
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
							t_specifier *sp, va_list ap)
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
	if (c == 'h' && *lem == 'h')
		*lm = ft_toupper(c);
	else if (c == 'l' && *lm == 'l')
		*lm = '7';
	else if (*lm == 0 || !(c == 'h' && *lm != 'H'))
		*lm = c;
}

static const char	match(char const *s, t_specifier *sp, va_list ap)
{
	*sp = NEW_SPECIFIER;
	while (*(++s))
	{
		if (*s == '.')
			s = evaluate_prec(s + 1, sp, va) - 1;
		else if (*s == '\'')
			sp->qoute = 1;
		else if (*s == '$')
		{
			sp->dollar_size = sp->size;
			sp->size = 0;
		}
		else if (ft_isdigit(*s) || *s == '*')
			s = evaluate_size(s, sp, va) - 1;
		else if ((char_index(*s, "0+- #_")) >= 0)
			sp->flags[char_index(*s, "0+- #_")] = 1;
		else if ((char_index(*s, "hljztL")) >= 0)
			set_len_modifier(*s, &(sp->len_mod));
		else if ((sp->conv = *s))
			return (s + 1);
	}
	return (s);
}

