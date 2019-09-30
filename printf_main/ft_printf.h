/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 12:50:39 by cspider           #+#    #+#             */
/*   Updated: 2019/09/30 13:40:51 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/libft.h"
# include <stdarg.h>

#define NEW_SPECIFIER (t_specifier){{{0, 0, 0, 0, 0, 0}}, 0, 0, 0, 0, 0, 0, -1}

typedef struct  s_specifiers
{
	int			dollar_size;
	int			quote;
	int			size;
    int         precision;
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

#endif
