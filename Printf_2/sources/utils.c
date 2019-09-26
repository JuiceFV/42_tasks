#include "../includes/ft_printf.h"

int		get_char_index(char* s, int c)
{
	int i = -1;
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}