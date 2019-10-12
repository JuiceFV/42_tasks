/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:47:42 by olongbot          #+#    #+#             */
/*   Updated: 2019/10/05 17:45:39 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		line_len(char **a, t_session *s)
{
	int		i;
	char	*tmp;

	i = 0;
	while (*a != NULL)
	{
		tmp = *a;
		while (*tmp != '\0')
		{
			if (*tmp != '+' && *tmp != '-' && (*tmp < '0' || *tmp > '9'))
				death("Wrong map (wrong char)", __FILE__, __LINE__, s);
			tmp++;
		}
		i++;
		a++;
	}
	return (i);
}

t_list	*nums2list(char **nums, t_session *s, int y)
{
	t_list		*tmplis;
	t_vector	p;
	t_list		*head;
	int			x;

	if ((x = 0) == 0 && s->map->width == 0)
		s->map->width = line_len(nums, s);
	else if (s->map->width != line_len(nums, s))
		death("Wrong map (width exeption)", __FILE__, __LINE__, s);
	p = cr_vec(x, y, ft_atoi(*nums), rgb2one(255, 0, 0));
	s->map->max_z = s->map->max_z < ft_atoi(*nums) ?
		ft_atoi(*nums) : s->map->max_z;
	if (!(tmplis = ft_lstnew(&p, sizeof(t_vector))))
		death(" error", __FILE__, __LINE__, s);
	head = tmplis;
	while (nums++ && *nums != NULL && ++x)
	{
		p = cr_vec(x, y, ft_atoi(*nums), rgb2one(255, 0, 0));
		s->map->max_z = s->map->max_z < ft_atoi(*nums) ?
			ft_atoi(*nums) : s->map->max_z;
		if (!(tmplis->next = ft_lstnew(&p, sizeof(t_vector))) && im(tmplis))
			death(" error", __FILE__, __LINE__, s);
		tmplis = tmplis->next;
	}
	return (head);
}

void	lstjoin(t_list **one, t_list *two)
{
	t_list	*tmp;

	if (*one == NULL)
	{
		*one = two;
		return ;
	}
	tmp = *one;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = two;
}

void	free_tab(char **s)
{
	char **tmp;

	tmp = s;
	while (*s != NULL)
	{
		free(*s);
		s++;
	}
	free(tmp);
}

void	read_file(t_session *s, int fd)
{
	int		ret;
	char	*line;
	char	**nums;
	t_list	*out;
	int		line_num;

	out = NULL;
	line_num = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		nums = ft_strsplit(line, ' ');
		lstjoin(&out, nums2list(nums, s, line_num));
		free_tab(nums);
		free(line);
		line_num++;
	}
	s->map->height = line_num;
	if (out == NULL)
		death("out is NULL", __FILE__, __LINE__, s);
	s->map->points = out;
	map_center(s->map);
	map_scale(s);
}
