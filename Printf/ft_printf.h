/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:57:28 by cspider           #+#    #+#             */
/*   Updated: 2019/09/19 21:23:21 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../Libft/libft.h"

/*
** internal flag definitions
*/
# define FLAGS_ZEROPAD   (1U <<  0U)
# define FLAGS_LEFT      (1U <<  1U)
# define FLAGS_PLUS      (1U <<  2U)
# define FLAGS_SPACE     (1U <<  3U)
# define FLAGS_HASH      (1U <<  4U)
# define FLAGS_UPPERCASE (1U <<  5U)
# define FLAGS_CHAR      (1U <<  6U)
# define FLAGS_SHORT     (1U <<  7U)
# define FLAGS_LONG      (1U <<  8U)
# define FLAGS_LONG_LONG (1U <<  9U)
# define FLAGS_PRECISION (1U << 10U)
# define FLAGS_ADAPT_EXP (1U << 11U)

/*
** 'ntoa' conversion buffer size, this must be big enough to hold one converted
** numeric number including padded zeros (dynamically created on stack)
** default: 32 byte
*/
# ifndef PRINTF_NTOA_BUFFER_SIZE
#  define PRINTF_NTOA_BUFFER_SIZE    32U
# endif

/*
**	'ftoa' conversion buffer size, this must be big enough to hold one converted
**	float number including padded zeros (dynamically created on stack)
**	default: 32 byte
*/
# ifndef PRINTF_FTOA_BUFFER_SIZE
#  define PRINTF_FTOA_BUFFER_SIZE    32U
# endif

/*
** output function type
*/
typedef	void		(*t_out_func_type)(char c, void *buffer,
						size_t index, size_t maxlen);

/*
** wrapper (used as buffer) for output function type
*/
typedef	struct		s_out_func_wrap_type
{
	void			(*func)(char c, void* arg);
	void			*arg;
}					t_out_func_wrap_type;

typedef	struct		s_struct_for_itoa
{
	t_out_func_type	out;
	char			*buffer;
	size_t			index;
	size_t			maxlen;
	unsigned	int	flags;
	size_t			len;

}					t_struct_for_itoa;

typedef	struct		s_struct_for_itoa_2
{
	unsigned int	base;
	unsigned int	prec;
	int				neg;
}					t_struct_for_itoa_2;
/*
** internal buffer output
*/
inline	void		out_buffer(char c,
								void *buffer, size_t index, size_t maxlen);
/*
** internal null output
*/
inline	void		out_null(char c, void *buffer, size_t index, size_t maxlen);
/*
** internal putchar wrapper
*/
inline	void		out_char(char c, void *buffer, size_t index, size_t maxlen);
/*
** internal output function wrapper
*/
inline	void		out_func(char c, void *buffer, size_t index, size_t maxlen);

/*
** output the specified string in reverse, taking care of any zero-padding
*/
size_t				out_rev(t_struct_for_itoa prtf,
							const char *buf, unsigned int width);

void				ifs_for_ntoa(unsigned int base, char **buf,
								size_t *len, unsigned int flags);

size_t				ntoa_format(t_struct_for_itoa s, char *buf,
							t_struct_for_itoa_2 s2, unsigned int width);

void				ifs_for_ntoa_2(size_t *len, int neg,
									unsigned int flags, char **buf);

size_t				ntoa_long(t_struct_for_itoa s, t_struct_for_itoa_2 s2,
								unsigned long value, unsigned int width);

size_t				ntoa_long_long(t_struct_for_itoa s, t_struct_for_itoa_2 s2,
						unsigned long long value, int width);

/*
** colors for bonus
*/
# define PF_RED			"\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_PURPLE		"\033[35m"
# define PF_CYAN		"\033[36m"
# define PF_EOC			"\033[36m"

#endif

/*
** May be rewrite strlen
*/

/*
** May be rewrite ifs for itoa (operetions order)
*/

/*
** May be rewrite ntoa (types)
*/
