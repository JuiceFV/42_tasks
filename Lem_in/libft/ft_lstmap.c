/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:03:13 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/05 21:48:26 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del_lst(void *content, size_t content_size)
{
	if (content_size)
		free(content);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *out;
	t_list *prev;

	if (!lst || !f || !(tmp = f(lst)))
		return (NULL);
	out = tmp;
	lst = lst->next;
	prev = out;
	while (lst)
	{
		if (!(tmp = f(lst)))
		{
			if (out)
				ft_lstdel(&out, del_lst);
			return (NULL);
		}
		if (prev)
		{
			prev->next = tmp;
			prev = prev->next;
		}
		lst = lst->next;
	}
	return (out);
}
