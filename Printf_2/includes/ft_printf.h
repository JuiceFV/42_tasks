#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUF_SIZE 64

# include "../Libft/libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdint.h>
/*
**
**
**
*/

# define PF_RED			"\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_PURPLE		"\033[35m"
# define PF_CYAN		"\033[36m"
# define PF_EOC			"\033[36m"

# define FLAGS_HASH			(1 << 0U)
# define FLAGS_SPACE		(1 << 1U)
# define FLAGS_PLUS			(1 << 2U)
# define FLAGS_LEFT			(1 << 3U)
# define FLAGS_ZEROPAD		(1 << 4U)
# define FLAGS_STAR			(1 << 5U)
# define FLAGS_UPPERCASE	(1 << 6U)
# define FLAGS_SHORT		(1 << 7U)
# define FLAGS_CHAR			(1 << 8U)
# define FLAGS_LONG			(1 << 9U)
# define FLAGS_LONG_LONG	(1 << 10U)
# define FLAGS_INTMAX		(1 << 11U)
# define FLAGS_SIZE_T		(1 << 12U)
# define FLAGS_MIN_LEN		(1 << 13U)
# define FLAGS_PRECISION	(1 << 14U)
# define FLAGS_POINTER		(1 << 15U)

# define MAX(a, b)		b & ((a - b) >> 31) | a & (~(a - b) >> 31)
# define MIN(a, b)		a & ((a - b) >> 31) | b & (~(a - b) >> 31)
# define ABS(a)			(a < 0) ? -a : a
# define DABS(a)		(a < 0.0f) ? -a : a
# define STRERR			strerror

typedef	struct		s_printf_format
{
	int				length;
	unsigned int	base;
	int				fd;
	char			*format;
	va_list			ap;
	char			buffer[BUF_SIZE];
	short			flags;
	size_t			min_length;
	unsigned int	precision;
	char			character;
	short			temp;
	char			buff_i;
	int				padding;
	int				is_printed;
}					t_printf_format;

int		ft_vsnprintf(t_printf_format frmt);

void	evaluate_format(t_printf_format *frmt);

int		get_char_index(char* s, int c);

void	buffer(t_printf_format *frmt, void *new, size_t size);

void	padding(t_printf_format *frmt, int n);

size_t	ft_wcharlen(unsigned wc);

size_t	ft_wstrlen(unsigned *s);

void	put_wchar(t_printf_format *frmt, unsigned int wc, int wlen, int nb_bytes);

void	printf_put_char_str(char *s, t_printf_format *frmt);

void	putnbr(t_printf_format *frmt);

void	putnbr_base(int base, t_printf_format *frmt);

void	itoa_printf(intmax_t n, t_printf_format *frmt, int len);

void	itoa_base_printf(uintmax_t n, int b, t_printf_format *frmt);

void	itoa_base_fill(uintmax_t tmp, int b, char s[BUF_SIZE], t_printf_format *frmt);

void	character(t_printf_format *frmt, unsigned c);

void	put_char_str(t_printf_format *frmt);

void	put_wchar_str(t_printf_format* frmt);

void	color(t_printf_format *frmt);

static void		ldtoa_fill(double n, t_printf_format *frmt, long value);

void			pf_putdouble(t_printf_format *frmt);

void		cs_not_found(t_printf_format *frmt);

int		ft_dprintf(int fd, const char *format, ...);

#endif