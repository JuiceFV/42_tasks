#include "ft_vector.h"


/*
** Array::_swap
** -
** swaps an array segment with what follows.
** very specific function, not useful for standard cases.
** -
** "...-1415920000"
** -swap(4, 10)->
** "   -0000141592"
** -swap(0, 4)->
** "-0000141592   "
*/
static void		*save_calloc(size_t count, size_t size)
{
	void	*const res = malloc(count * size);

	if (res == NULL)
		exit(1);
	ft_bzero(res, count * size);
	return (res);
}

void			ft_vector_segswap(t_vector *this, size_t w_before, size_t w_after)
{
	char			tmp;
	const size_t	len = w_after - w_before;
	const size_t	m = this->type_size;

	tmp = save_calloc(len, m);
	ft_memcpy(tmp, this->data + w_before * m, m * len);
	ft_memmove(this->data + w_before * m, this->data + w_after * m,
				(this->size - w_after) * m);
	ft_memcpy(this->data + (this->size - len) * m, tmp, len * m);
	free(tmp);
}

