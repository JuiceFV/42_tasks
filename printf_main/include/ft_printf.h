/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 12:50:39 by cspider           #+#    #+#             */
/*   Updated: 2019/10/09 18:23:32 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define NEW_SPEC (t_specifiers){{{0, 0, 0, 0, 0, 0}}, 0, 0, 0, 0, 0, 0, -1}
# define NEW_SPECIFIER NEW_SPEC

typedef struct		s_specifiers
{
	union
	{
		char		f[6];
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
	int				precision;
}					t_specifiers;
/*
** main printf functions
*/

int					ft_printf(const char *format, ...);
int					ft_printfln(char const *format, ...);
int					ft_dprintf(int fd, char const *format, ...);
int					ft_asprintf(char **ret, char const *format, ...);
char				*ft_rasprintf(int *res, char const *format, ...);
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
int					ft_vprintf(char const *format, va_list ap);
int					ft_vdprintf(int fd, char const *format, va_list ap);
int					ft_vasprintf(char **ret, char const *s, va_list ap);
/*
** Helpful Utilits
*/
int					char_index(char i, char const *str);
double				fract_part(double num);
long int			round_base(double x, double f, int b);
/*
** main eval func's
*/
char				*next_spec(char const *s, t_vector *frmt);
int					evaluate_all(t_specifiers *sp, t_vector *frmt,
							va_list ap, va_list frmt_ap);
/*
** String/char eval
*/
int					ev_c(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_s(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_wc(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_ws(t_specifiers *sp, t_vector *frmt, va_list ap);
/*
** num eval
*/
int					signed_double_g(t_specifiers *sp, t_vector *frmt,
											long double arg, char *c);
int					signed_double_a(t_specifiers *sp, t_vector *frmt,
											long double arg, char *c);
int					signed_double_e(t_specifiers *sp, t_vector *frmt,
											long double arg, char *c);
int					rtoa(t_vector *frmt, long double x, int b,
											t_specifiers *sp);
int					signed_integer(t_specifiers *sp, t_vector *frmt,
											va_list ap, int b);
int					unsigned_integer(t_specifiers *sp, t_vector *frmt,
											va_list ap, int b);
int					quote_div(t_vector *frmt, char c);
int					itoa_base(t_vector *frmt, intmax_t n, int b,
														char info);
int					ev_o(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_b(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_n(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_di(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_u(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_x(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_cx(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_p(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_f(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_cf(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_e(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_ce(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_g(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_cg(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_a(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_ca(t_specifiers *sp, t_vector *frmt, va_list ap);

/*
** color eval
*/

int					ev_w(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_cw(t_specifiers *sp, t_vector *frmt, va_list ap);

/*
** date eval
*/

int					ev_k(t_specifiers *sp, t_vector *frmt, va_list ap);
int					ev_m(t_specifiers *sp, t_vector *frmt, va_list ap);
/*
** TODO
** Finished | +
** Norme 	| -
** Errors	| -
** Logic 	| -
** Checked	| -
** included	| -
*/
#endif
