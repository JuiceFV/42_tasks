/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:20:21 by cspider           #+#    #+#             */
/*   Updated: 2019/10/01 20:00:58 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stddef.h>

/*
** Simple vector
*/

typedef struct	s_vector
{
	void		*data;
	size_t		size;
	size_t		max;
	size_t		type_size;
}				t_vector;

/*
** Constructor
*/

# define VECTOR(T) (t_vector){NULL, 0, 0, sizeof(T)};
# define VECTOR_POPFRONT(A,N) fta_popindex(A, 0, N)
# define VECTOR_INDEX_CHECK(A,I) (0 <= (I) && (I) < (A)->size)
# define VECTOR_GET(A,I) (VECTOR_START(A) + VECTOR_OFFSET(A,I))
# define VECTOR_GETS(A,I) (VECTOR_INDEX_CHECK(A,I) ? VECTOR_GET(A,I) : NULL)
# define VECTOR_GETT(T,A,I) ((T*)VECTOR_GET(A,I))
# define VECTOR_GETTS(T,A,I) ((T*)VECTOR_GETS(A,I))
# define VECTOR_GETL(T,A,I) (*VECTOR_GETT(T,A,I))
# define VECTOR_IFP(A,P) ((((void *)P) - (A)->data) / (A)->type_size)
# define VECTOR_ITERATOR(A) (VECTOR_START(A) - VECTOR_STEP(A))
# define VECTOR_START(A) ((A)->data)
# define VECTOR_END(A) ((A)->data + (A)->size * (A)->type_size)
# define VECTOR_LAST(A) ((char *)((A)->data + (A)->size * (A)->type_size - 1))
# define VECTOR_STEP(A) ((A)->type_size)
# define VECTOR_OFFSET(A,I) ((I) * VECTOR_STEP(A))
# define VECTOR_NEXT(A,IT) ((IT) += VECTOR_STEP(A))
# define VECTOR_HASNEXT(A,IT) (VECTOR_NEXT(A,IT) < VECTOR_END(A))
# define VEC_INITIAL_SIZE 16

/*
** When reaching its capacity, an array will re-allocate memory,
** using this factor to grow relatively to its previous size.
*/
# define VEC_FACTOR 2

t_vector		ft_vector_new(size_t type_size);
t_vector		*ft_vector_alloc(size_t type_size);
int				ft_vector_append(t_vector *this, void const *data,
													size_t datalen);
int				ft_vector_append_free(t_vector *this, void *data,
													size_t datalen);
int				ft_vector_append_char(t_vector *this, char data);
int				ft_vector_insert(t_vector *this, void const *data,
								size_t datalen, size_t index);
int				ft_vector_reserve(t_vector *this, size_t size);
int				ft_vector_trim(t_vector *this);
void			ft_vector_pop_back(t_vector *this, size_t length);
void			ft_vector_pop_zero(t_vector *this, int *res);
void			ft_vector_pop_zerohex(t_vector *this, int *res);
void			ft_vector_pop_backf(t_vector *this, size_t length,
									void (*del)(void*));
int				ft_vector_pop_index(t_vector *this, size_t index,
										size_t length);
int				ft_vector_pop_indexf(t_vector *this, size_t index,
					size_t length, void (*del)(void*));
int				ft_vector_replace(t_vector *this, size_t index, size_t length,
								t_vector *v_new);
char			*ft_vector_string(t_vector *this, char *(*f)(void *));
int				ft_vector_resize(t_vector *this, size_t new_size);
void			ft_vector_clear(t_vector *this);
#endif
