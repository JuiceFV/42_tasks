#include "ft_vector.h"
#include "libft.h"

void	ft_vector_clear(t_vector *this)
{
	if (this->max > 0)
	{
		free(this->data);
		this->size = 0;
		this->max = 0;
	}
}