#include "ft_vector.h"
#include "libft.h"

int	ft_vector_append(t_vector *this, void const *data, size_t datalen)
{
	if (ft_vector_reserve(this, datalen))
		return (1);
	ft_memcpy(FT_VECTOR_END(this), data, FT_VECTOR_OFFSET(this, datalen));
	this->size += datalen;
	return (0);
}

int	ft_vector_append_free(t_vector *this, void const *data, size_t datalen)
{
	if (ft_vector_reserve(this, datalen))
		return (1);
	ft_memcpy(FT_VECTOR_END(this), data, FT_VECTOR_OFFSET(this, datalen));
	this->size += datalen;
	free(data);
	return (0);
}

int	ft_vector_insert(t_vector *this, void const *data,
						size_t datalen, size_t index)
{
	if (this->size < index || ft_vector_reserve(this, datalen))
		return (1);
	ft_memmove(FT_VECTOR_GET(this, index + datalen),
				FT_VECTOR_GET(this, index),
				FT_VECTOR_OFFSET(this, this->size - index));
	ft_memcpy(FT_VECTOR_GET(this, index),
				data,
				FT_VECTOR_OFFSET(this, datalen));
	this->size += datalen;
	return (0);
}

int	ft_vector_append_char(t_vector *this, char data)
{
	if (ft_vector_reserve(this, datalen))
		return (1);
	ft_memcpy(FT_VECTOR_END(this), &data, FT_VECTOR_OFFSET(this, 1));
	this->size += 1;
	return (0);
}
