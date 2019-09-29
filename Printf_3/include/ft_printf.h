#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>

# define MAX(a, b)		(a > b) ? a : b
# define MIN(a, b)		(a < b) ? a : b
# define ABS(a)			(a < 0) ? -a : a
# define DABS(a)		(a < 0.0f) ? -a : a
# define STRERR			strerror

# define PF_RED			"\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_PURPLE		"\033[35m"
# define PF_CYAN		"\033[36m"
# define PF_EOC			"\033[0m"

# define F_SHARP		(1 << 0)
# define F_SPACE		(1 << 1)
# define F_PLUS			(1 << 2)
# define F_MINUS		(1 << 3)
# define F_ZERO			(1 << 4)
# define F_WILDCARD		(1 << 5)
# define F_UPCASE		(1 << 6)
# define F_SHORT		(1 << 7)
# define F_CHAR			(1 << 8)
# define F_LONG			(1 << 9)
# define F_LONG_LONG	(1 << 10)
# define F_INTMAX		(1 << 11)
# define F_SIZE_T		(1 << 12)
# define F_MIN_LEN		(1 << 13)
# define F_APP_PRECI	(1 << 14)
# define F_POINTER		(1 << 15)
# define PF_BUF_SIZE	64

typedef struct			s_format
{
	int					len;
	short				f;
	short				n;
	int					min_length;
	int					precision;
	int					padding;
	int					printed;
	int					fd;
	int					buffer_index;
	char				buff[PF_BUF_SIZE];
	va_list				ap;
	char				*format;
	unsigned			c;
}						t_format;

int						ft_printf(const char *format, ...);
int						ft_dprintf(int fd, const char *format, ...);
int 					ft_vsnprintf(t_format p);


void					evaluate_optionals(t_format *p);
void					spec_not_found(t_format *p);

void					pf_putnb(t_format *p);
void					pf_putnb_base(int base, t_format *p);
void					itoa_printf(intmax_t d, t_format *p, int len);
void					itoa_base_printf(uintmax_t d, int b, t_format *p);
void					itoa_base_fill(uintmax_t tmp, int base, char *str,
						t_format *p);

void					pf_putstr(t_format *p);
void					pf_putwstr(t_format *p);
void					pf_character(t_format *p, unsigned c);
void					ft_printf_putstr(char *s, t_format *p);
void					pf_putwchar(t_format *p, unsigned int w, int wl, int n);

void					print_pointer_address(t_format *p);
void					color(t_format *p);
void					pf_putdouble(t_format *p);

void					buffer(t_format *p, void *new_elem, size_t size);
void					buffer_flush(t_format *p);

void					padding(t_format *p, int n);

#endif
