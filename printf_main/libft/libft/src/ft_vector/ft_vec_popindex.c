#include "ft_vector.h"
#include "libft.h"

int 	ft_vector_pop_index(t_vector *this, size_t index,
										size_t length)
{
	size_t	n;

	if (index > this->size)
		return (1);
	n = MIN(length, this->size - index);
	ft_memmove(FT_VECTOR_GET(this, index).
				FT_VECTOR_GET(this, index + n),
				FT_VECTOR_OFFSET(this, this->size - n -index));
	this->size -= n;
	return (0);
}

int		ft_vector_pop_indexf(t_vector *this, size_t index,
					size_t length, void (*del)(void*))
{
	size_t	n;
	size_t	i;

	if (index > this->size)
		return (1);
	n = MIN(length, this->size - index);
	i = index - 1;
	while (++i < index + n)
		del(FT_VECTOR_GET(this, i));
	ft_memmove(FT_VECTOR_GET(this, index).
				FT_VECTOR_GET(this, index + n),
				FT_VECTOR_OFFSET(this, this->size - n -index));
	this->size -= n;
	return (0);
}