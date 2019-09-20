/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:57:28 by cspider           #+#    #+#             */
/*   Updated: 2019/09/20 18:30:55 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../Libft/libft.h"

/*
** --------------------------------- Defines ------------------------------- **
** 1 |
** 2 |
** 3 |
** 4 |
** 5 |
** 6 |
** 7 |
** 8 |
** 9 |
** 10|
** 11|
** 12|
** =========================================================================
** 13| 'ntoa' conversion buffer size, this must be big enough to hold one
**   | converted numeric number including padded zeros 
**   | default: 32 byte
** 14| 'ftoa' conversion buffer size, this must be big enough to hold one
**	 | converted float number including padded zeros 
** 	 | default: 32 byte
**
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



# ifndef PRINTF_NTOA_BUFFER_SIZE
#  define PRINTF_NTOA_BUFFER_SIZE    32U
# endif
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

typedef	struct		s_printf_format
{
	t_out_func_type	out;
	char			*buffer;
	size_t			index;
	size_t			maxlen;
	unsigned	int	flags;
	size_t			len;
	unsigned	int	base;
	unsigned	int	prec;
	int				neg;
	unsigned	int	width;

}					t_printf_format;
/*
** --------------------- Internal Output Functions ------------------------- **
** 1| internal buffer output 							 					 **
** 2| internal null output	 							 					 **
** 3| internal putchar wraper 	 						 					 **
** 4| internal output function wrapper										 **
** 5| output the specified str in reverse, taking care of any zero-padding   **
** ------------------------------------------------------------------------- **
** Location| internal_output.c												 **
** --------------------- Internal Output Functions ------------------------- **
*/
inline	void		out_buffer(char c, void *buffer,
						size_t index, size_t maxlen);
inline	void		out_null(char c, void *buffer,
						size_t index, size_t maxlen);
inline	void		out_char(char c, void *buffer,
						size_t index, size_t maxlen);
inline	void		out_func(char c, void *buffer,
						size_t index, size_t maxlen);
size_t              out_rev(t_printf_format frmt,
						const char *buf);
/*
** --------------------- Out-Format handler -------------------------------- ** 
** 1| internal itoa format													 **
** 2| internal itoa for 'long' type											 **
** 3| internal itoa for 'long long' type									 **
** ------------------------------------------------------------------------- **
** Location| output_format_handler.c 										 **
** --------------------- Out-Format handler -------------------------------- **
*/
size_t				ntoa_format(t_printf_format frmt, char *buf);
size_t				ntoa_long(t_printf_format frmt, unsigned long value);
size_t				ntoa_long_long(t_printf_format frmt, unsigned long long value);

void                hash_handle_rules(unsigned int base, char **buf, size_t *len, unsigned int flags);
void                mps_handle_rules(size_t *len, int neg, unsigned int flags, char **buf);
void				set_pow10(double pow10[]);

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
