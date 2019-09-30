#include "ft_vector.h"
#include "libft.h"

t_vector	ft_vector_new(size_t type_size)
{
	t_vector res;

	res = (t_vector){NULL, 0, 0, type_size};
	ft_vector_reserve(&res, 1);
	return (res);
}