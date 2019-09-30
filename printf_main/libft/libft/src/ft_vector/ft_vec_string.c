#include "ft_vector.h"
#include "libft.h"
/*
** f converts an element to a string.
*/
char	*ft_vector_string(t_vector *this, char *(*f)(void *))
{
	t_vector	res[1];
	void		*iterator;
	char		*tmp;

	*res = FT_VECTOR(char);
	ft_vector_reserve(this, this->size * 3 + 10);
	ft_vector_append(res, "[|", 3);
	iterator = FT_VECTOR_START(this);
	tmp = f(iterator);
	STRING_APPEND(res, tmp);
	while (FT_VECTOR_HASNEXT(this, iterator))
	{
		STRING_APPEND(res, ", ");
		tmp = f(iterator);
		STRING_APPEND(res, tmp);
	}
	ft_vector_append(res, "|]", 3);
	return ((char *)res->data);
}	