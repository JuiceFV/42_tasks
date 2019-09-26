#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUF_SIZE 64
# include "../Libft/libft.h"
# include <stdarg.h>

/*
**
**
**
*/
# define FLAGS_HASH			(1 << 0U)
# define FLAGS_SPACE		(1 << 1U)
# define FLAGS_PLUS			(1 << 2U)
# define FLAGS_LEFT			(1 << 3U)
# define FLAGS_ZEROPAD		(1 << 4U)
# define FLAGS_STAR			(1 << 5U)
# define FLAGS_UPPERCASE	(1 << 6U)
# define FLAGS_SHORT		(1 << 7U)
# define FLAGS_PRECISION	(1 << 14U)

typedef	struct		s_printf_format
{
	int				length;
	unsigned int	base;
	int				fd;
	char			*format;
	va_list			ap;
	char			buffer[BUF_SIZE];
	unsigned int	flags;
	size_t			min_length;
	unsigned int	precision;
	int				temp;
}					t_printf_format;

int		ft_vsnprintf(t_printf_format frmt);

void	evaluate_options(t_printf_format *frmt);

int		get_char_index(char* s, int c);
#endif