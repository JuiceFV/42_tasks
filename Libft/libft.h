/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:00:02 by cspider           #+#    #+#             */
/*   Updated: 2019/09/03 20:59:41 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>

# define FT_MIN(x, y)		x < y ? x : y
# define FT_MAX(x, y)		x > y ? x : y
# define FT_ABS(x)			x > 0 ? x : -x

# define FT_ULONG_MAX		((unsigned long)(~0L))
# define FT_LONG_MAX		((long)(FT_ULONG_MAX >> 1))
# define FT_LONG_MIN		((long)(~FT_LONG_MAX))

# define FT_UINT_MAX		((unsigned)(~0L))
# define FT_INT_MAX			((int)(FT_UINT_MAX >> 1))
# define FT_INT_MIN			((int)(~FT_INT_MAX))

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_isdigit(int c);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
size_t				ft_strlen(const char *s);
void				ft_putnbr_fd(int n, int fd);


#endif
