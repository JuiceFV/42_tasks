/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:38:52 by olongbot          #+#    #+#             */
/*   Updated: 2019/10/05 17:17:32 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press(int button, int x, int y, void *param)
{
	t_session	*s;
	t_mouse		*mouse;

	(void)x;
	(void)y;
	(void)button;
	s = (t_session *)param;
	mouse = s->mouse;
	mouse->prev_x = mouse->x;
	mouse->prev_y = mouse->y;
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_mouse		*mouse;

	mouse = (t_mouse *)param;
	mouse->x = x;
	mouse->y = y;
	return (0);
}

void	redraw(t_session *s)
{
	ft_bzero(s->img, (s->size_line * WIN_HEIGHT));
	draw_map(s);
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
}

int		deal_key2(int key, t_session *s)
{
	if (key == 35 && s->iso == 0)
		iso(s);
	else if (s->iso == 1)
	{
		s->iso = 0;
		map_origin(s);
	}
	if (key == 8)
		map_origin(s);
	if (key == 31)
		iso2(s);
	if (key == 126)
		s->d_move_y += 10;
	if (key == 125)
		s->d_move_y -= 10;
	if (key == 123)
		s->d_move_x += 10;
	if (key == 124)
		s->d_move_x -= 10;
	return (0);
}

int		deal_key(int key, void *param)
{
	t_session *s;

	s = (t_session *)param;
	if (key == 14)
		apply_rot(s->map->points, 'z', 1 * s->delta);
	if (key == 12)
		apply_rot(s->map->points, 'z', -1 * s->delta);
	if (key == 0)
		apply_rot(s->map->points, 'y', 1 * s->delta);
	if (key == 2)
		apply_rot(s->map->points, 'y', -1 * s->delta);
	if (key == 13)
		apply_rot(s->map->points, 'x', 1 * s->delta);
	if (key == 1)
		apply_rot(s->map->points, 'x', -1 * s->delta);
	if (key == 27)
		s->map->scale = s->map->scale > 1 ? s->map->scale - 1 : 1;
	if (key == 24)
		s->map->scale = s->map->scale < 10 ? s->map->scale + 1 : 10;
	if (key == 53)
		ft_close(s);
	deal_key2(key, s);
	redraw(s);
	return (0);
}
