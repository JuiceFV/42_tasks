#include "ft_vector.h"
#include "libft.h"

int 	ft_vector_trim(t_vector *this)
{
	ft_vector_append(this, "\0", 1);
	if (this->size < this->max)
		return (ft_vector_resize(this, this->size));
	return (0);
}