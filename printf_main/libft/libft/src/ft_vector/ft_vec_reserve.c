#include "ft_vector.h"
#include "libft.h"

int 	ft_vector_reserve(t_vector *this, size_t size)
{
	size_t	total_size;
	size_t	new_size;

	total_size = size + this->size;
	if (total_size > this->max)
	{
		new_size = (this->max > 0 ? this->max : FT_VECTOR_INITIAL_SIZE);
		while (new_size < total_size)
			new_size *= FT_VECTOR_FACTOR;
		return (ft_vector_resize(this, new_size));
	}
	return (0);
}