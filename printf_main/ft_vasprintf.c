/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 12:51:42 by cspider           #+#    #+#             */
/*   Updated: 2019/09/30 13:40:38 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*pf_evaluate_prec(const char *s,
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

static const char	*pf_evaluate_size(char const *s,
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

static	void		pf_set_len_modifier(char c, char *lm)
{
	if (c == 'h' && *lem == 'h')
		*lm = ft_toupper(c);
	else if (c == 'l' && *lm == 'l')
		*lm = '7';
	else if (*lm == 0 || !(c == 'h' && *lm != 'H'))
		*lm = c;
}

static const char	pf_match(char const *s, t_specifier *sp, va_list ap)
{
	*sp = NEW_SPECIFIER;
	while (*(++s))
	{
		if (*s == '.')
			s = pf_evaluate_prec(s + 1, sp, va) - 1;
		else if (*s == '\'')
			sp->qoute = 1;
		else if (*s == '$')
		{
			sp->dollar_size = sp->size;
			sp->size = 0;
		}
		else if (ft_isdigit(*s) || *s == '*')
			s = pf_evaluate_size(s, sp, va) - 1;
		else if
	}
}

