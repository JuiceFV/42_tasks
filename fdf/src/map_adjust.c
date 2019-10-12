/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_adjust.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:28:42 by olongbot          #+#    #+#             */
/*   Updated: 2019/10/05 17:22:50 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_center(t_map *map)
{
	t_list	*lst;

	lst = map->points;
	while (lst != NULL)
	{
		((t_vector *)(lst->content))->x -= map->width / 2;
		((t_vector *)(lst->content))->o_x -= map->width / 2;
		((t_vector *)(lst->content))->y -= map->height / 2;
		((t_vector *)(lst->content))->o_y -= map->height / 2;
		lst = lst->next;
	}
}

void	map_scale(t_session *s)
{
	int		scaler;
	t_list	*lst;

	lst = s->map->points;
	scaler = (s->map->width > s->map->height) ? s->map->width : s->map->height;
	while (lst != NULL)
	{
		((t_vector *)(lst->content))->x *= (600 / scaler);
		((t_vector *)(lst->content))->y *= (600 / scaler);
		((t_vector *)(lst->content))->z *= s->map->z_scale;
		((t_vector *)(lst->content))->o_x *= (600 / scaler);
		((t_vector *)(lst->content))->o_y *= (600 / scaler);
		((t_vector *)(lst->content))->o_z *= s->map->z_scale;
		lst = lst->next;
	}
}

void	map_origin(t_session *s)
{
	t_list	*lst;

	lst = s->map->points;
	s->d_move_x = 0;
	s->d_move_y = 0;
	s->map->scale = 1;
	while (lst != NULL)
	{
		((t_vector *)(lst->content))->x = ((t_vector *)(lst->content))->o_x;
		((t_vector *)(lst->content))->y = ((t_vector *)(lst->content))->o_y;
		((t_vector *)(lst->content))->z = ((t_vector *)(lst->content))->o_z;
		lst = lst->next;
	}
}

void	iso(t_session *s)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;
	t_list	*lst;

	map_origin(s);
	lst = s->map->points;
	while (lst != NULL)
	{
		prev_x = ((t_vector *)(lst->content))->x;
		prev_y = ((t_vector *)(lst->content))->y;
		prev_z = ((t_vector *)(lst->content))->z;
		((t_vector *)(lst->content))->x = (prev_x - prev_y) * cos(0.523599);
		((t_vector *)(lst->content))->y = -prev_z +
			(prev_x + prev_y) * sin(0.523599);
		lst = lst->next;
	}
	s->iso = 1;
}

void	iso2(t_session *s)
{
	map_origin(s);
	apply_rot(s->map->points, 'x', M_PI / 2);
	apply_rot(s->map->points, 'y', -asin(tan(M_PI / 6)));
	apply_rot(s->map->points, 'x', -M_PI / 4);
}
