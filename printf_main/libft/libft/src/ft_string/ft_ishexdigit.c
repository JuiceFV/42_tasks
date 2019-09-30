#include "libft.h"

int	ft_ishexdigit(char c)
{
	if (ft_isdigit(c) || (c >= 'a' && c <= 'f') ||
		(c >= 'A' && c <= 'F'))
		return (1);
	else
		return (0);
}