/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 12:50:39 by cspider           #+#    #+#             */
/*   Updated: 2019/10/01 20:09:03 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define NEW_SPECIFIER (t_specifiers){{{0, 0, 0, 0, 0, 0}}, 0, 0, 0, 0, 0, 0, -1}

typedef struct  s_specifiers
{
	union
	{
		char	f[6];
		struct
		{
			char	zero;
			char	plus;
			char	minus;
			char	space;
			char	sharp;
			char	underscore;	
		}			n;
	}				flags;
	char			conv;
	char			len_mod;
	int				dollar_size;
	int				quote;
	int				size;
	int				sp_index;
    int         	precision;
}               t_specifiers;
/*
** main printf functions
*/

int             ft_printf(const char *format, ...);
/*
** Help functions:
** 1) vprintf() function is equivalent to the
** function printf() respectively, except that
** this one is called width a va_list instead
** of a variable number of arguments.
**
** 2) vdprintf() are exact analogs of fprintf()
** and vfprintf(), except that its output to a file
** descriptor fd instead of to a stdio stream.
*/
int             ft_vprintf(char const *format, va_list ap);
int             ft_vdprintf(int fd, char const *format, va_list ap);
/*
** Helpful Utilits
*/
int				char_index(char i, char const *str);

char 			*next_spec(char const *s, t_vector *frmt)
int				evaluate_all(t_specifiers *sp, t_vector *frmt,
							va_list ap, va_list frmt_ap);

#endif
