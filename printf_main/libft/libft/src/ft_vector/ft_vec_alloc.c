#include "ft_vector.h"
#include "libf.h"

t_vector	*ft_vector_alloc(size_t type_size)
{
	t_vector *res;

	if (!(res = (t_vector)malloc(sizof(t_vector))))
		return (NULL);
	ft_bzero(res, sizof(t_vector));
	res->type_size = type_size;
	return (ft_vector_reserve(res, 1) ? NULL : res);
}