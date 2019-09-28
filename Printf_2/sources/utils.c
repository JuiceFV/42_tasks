#include "../includes/ft_printf.h"

void	padding(t_printf_format *frmt, int n)
{
	if (!frmt->padding)
		return ;
	frmt->character = 32 | (frmt->flags & FLAGS_ZEROPAD);
	if (!n && !(frmt->flags & FLAGS_LEFT))
		while (frmt->padding--)
			buffer(frmt, &frmt->character, 1);
	else if (n && (frmt->flags & FLAGS_LEFT))
		while (frmt->padding--)
			buffer(frmt, &frmt->character, 1);
}

size_t	ft_wcharlen(unsigned wc)
{
	if (wc < 0x80)
		return (1);
	else if (wc < 0x800)
		return (2);
	else if (wc < 0x10000)
		return (3);
	return (4);
}

size_t		ft_wstrlen(unsigned *s)
{
	size_t	len;

	len = 0;
	while (*s != L'\0')
	{
		len += ft_wcharlen(*s);
		++s;
	}
	return (len);
}

int		get_char_index(char* s, int c)
{
	int i = -1;
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}

void	buffer(t_printf_format *frmt, void *new, size_t size)
{
	int			diff;
	long long	new_i;

	new_i = 0;
	while (BUF_SIZE - frmt->buff_i < (int)size)
	{
		diff = BUF_SIZE - frmt->buff_i;
		ft_memcpy(&(frmt->buffer[frmt->buff_i]), &(new[new_i]), diff);
		size -= diff;
		new_i += diff;
		frmt->buff_i += diff;
		frmt->length += diff;
		write(frmt->fd, frmt->buffer, frmt->buff_i);
		frmt->buff_i = 0;
	}
	ft_memcpy(&(frmt->buffer[frmt->buff_i]), &(new[new_i]), size);
	frmt->buff_i += size;
	frmt->length += size;
}