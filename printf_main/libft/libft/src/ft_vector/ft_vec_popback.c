#include "ft_vector.h"
#include "libft.h"

void	ft_vector_pop_back(t_vector *this, size_t length)
{
	this->size -= MIN(length, this->size);
}

void	ft_vector_pop_backf(t_vector *this, size_t length, void (*del)(void*))
{
	while (this->size > 0 && length > 0)
	{
		this->size--;
		del(FT_VECTOR_END(this));
		length--
	}
}

void	ft_vector_pop_zero(t_vector *this, int *res)
{
	while (((FT_VECTOR_LAST(this))[0] == '0' &&
		(ft_isdigit((FT_VECTOR_LAST(this) - 1)[0]) ||
		(FT_VECTOR_LAST(this) - 1)[0] == '.')) ||
		(FT_VECTOR_LAST(this))[0] == '.')
	{
		ft_vector_pop_back(this, 1);
		res--;
	}
}

void	ft_vector_pop_zerohex(t_vector *this, int *res)
{
	while (((FT_VECTOR_LAST(this))[0] == '0' &&
		(ft_hexisdigit((FT_VECTOR_LAST(this) - 1)[0]) ||
		(FT_VECTOR_LAST(this) - 1)[0] == '.')) ||
		(FT_VECTOR_LAST(this))[0] == '.')
	{
		ft_vector_pop_back(this, 1);
		res--;
	}
}