#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/libft.h"
# include <stdarg.h>

typedef struct  s_specifiers
{
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
