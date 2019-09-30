#include "ft_vector.h"
#include "libft.h"

int 	ft_vector_replace(t_vector *this, size_t index, size_t length,
								t_vector *_new)
{
	return (ft_vector_pop_index(this, index, length)
		|| ft_vector_insert(this, _new->size, index));
}