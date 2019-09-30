#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stddef.h>

/*
** Simple vector
*/
typedef struct	s_vector
{
	void*		data;
	size_t		size;
	size_t		max;
	size_t		type_size;
}				t_vector;
/*
** Constructor
*/
# define FT_VECTOR(T) (t_vector){NULL, 0, 0, sizeof(T)}
# define FT_VECTOR_POPFRONT(A,N) vector_pop_index(A, 0, N)
# define FT_VECTOR_INDEX_CHECK(A,I) ((I) >= 0 && (I) < (A)->size)
# define FT_VECTOR_GET(A,I) (FT_VECTOR_START(A) + FT_VECTOR_OFFSET(A,I))
# define FT_VECTOR_GET_SAFE(A,I) (FT_VECTOR_INDEX_CHECK(A,I) ? FT_VECTOR_GET(A,I) : NULL)
# define FT_VECTOR_GET_TYPED(T,A,I) ((T*)FT_VECTOR_GET(A,I))
# define FT_VECTOR_GET_TYPED_SAFE(T,A,I) ((T*)FT_VECTOR_GET_SAFE(A,I))
# define FT_VECTOR_GET_ELEMENT(T,A,I) (*FT_VECTOR_GET_TYPED(T,A,I))
# define FT_VECTOR_IFP(A,P) ((((void *)P) - (A)->data) / (A)->type_size)
# define FT_VECTOR_ITERATOR(A) (FT_VECTOR_START(A) - FT_VECTOR_STEP(A))
# define FT_VECTOR_START(A) ((A)->data)
# define FT_VECTOR_END(A) ((A)->data + (A)->size * (A)->type_size)
# define FT_VECTOR_LAST(A) ((char *)((A)->data + (A)->size * (A)->type_size - 1))
# define FT_VECTOR_STEP(A) ((A)->type_size)
# define FT_VECTOR_OFFSET(A,I) ((I) * FT_VECTOR_STEP(A))
# define FT_VECTOR_NEXT(A,IT) ((IT) += FT_VECTOR_STEP(A))
# define FT_VECTOR_HASNEXT(A,IT) (FT_VECTOR_NEXT(A,IT) < FT_VECTOR_END(A))
# define FT_VECTOR_INITIAL_SIZE 16
/*
** When reaching its capacity, an array will re-allocate memory,
** using this factor to grow relatively to its previous size.
*/
# define FT_VECTOR_FACTOR 2

t_vector		ft_vector_new(size_t type_size);
t_vector		*ft_vector_alloc(size_t type_size);
int				ft_vector_append(t_vector *this, void const *data, size_t datalen);
int				ft_vector_append_free(t_vector *this, void *data, size_t datalen);
int				ft_vector_append_char(t_vector *this, char data);
int				ft_vector_insert(t_vector *this, void const *data,
								size_t datalen, size_t index);
int 			ft_vector_reserve(t_vector *this, size_t size);
int 			ft_vector_trim(t_vector *this);
void 			ft_vector_pop_back(t_vector *this, size_t length);
void 			ft_vector_pop_zero(t_vector *this, int *res);
void 			ft_vector_pop_zerohex(t_vector *this, int *res);
void 			ft_vector_pop_backf(t_vector *this, size_t length,
									void (*del)(void*));
int 			ft_vector_pop_index(t_vector *this, size_t index,
										size_t length);
int 			ft_vector_pop_indexf(t_vector *this, size_t index,
					size_t length, void (*del)(void*));
int 			ft_vector_replace(t_vector *this, size_t index, size_t length,
								t_vector *new);
char 			*ft_vector_string(t_vector *this, char *(*f)(void *));
int 			ft_vector_resize(t_vector *this, size_t new_size);
void 			ft_vector_clear(t_vector *this);
#endif