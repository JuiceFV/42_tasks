/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:26:13 by olongbot          #+#    #+#             */
/*   Updated: 2019/10/05 17:24:46 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		death(char *er, char *f, int l, t_session *s)
{
	ft_putstr(er);
	ft_putstr("\n");
	ft_putstr(f);
	ft_putstr(" ");
	ft_putnbr(l);
	ft_putstr("\n");
	ft_close(s);
}

t_session	*sess_init(void)
{
	t_session	*sess;

	if (!(sess = (t_session *)malloc(sizeof(t_session))))
		death("session initialization", __FILE__, __LINE__, NULL);
	if (!(sess->mlx_ptr = mlx_init()))
		death("session initialization", __FILE__, __LINE__, sess);
	if (!(sess->win_ptr = mlx_new_window(sess->mlx_ptr,
					WIN_WIDTH, WIN_HEIGHT, WIN_NAME)))
		death("session initialization", __FILE__, __LINE__, sess);
	if (!(sess->mouse = (t_mouse *)malloc(sizeof(t_mouse))))
		death("session initialization", __FILE__, __LINE__, sess);
	if (!(sess->img_ptr = mlx_new_image(sess->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		death("session initialization", __FILE__, __LINE__, sess);
	if (!(sess->img = mlx_get_data_addr(sess->img_ptr, &(sess->bits_per_pixel),
			&(sess->size_line), &(sess->endian))))
		death("session initialization", __FILE__, __LINE__, sess);
	sess->bits_per_pixel = 4;
	sess->size_line = WIN_WIDTH * sess->bits_per_pixel;
	sess->endian = 0;
	sess->d_move_x = 0;
	sess->d_move_y = 0;
	sess->iso = 0;
	sess->delta = M_PI / 10;
	return (sess);
}

t_map		*map_init(t_session *s)
{
	t_map *map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		death("map initialization", __FILE__, __LINE__, s);
	map->width = 0;
	map->height = 0;
	map->scale = 1;
	map->z_scale = 1;
	map->max_z = 0;
	map->points = NULL;
	return (map);
}

void		hooks_init(t_session *sess)
{
	mlx_hook(sess->win_ptr, 2, 0, deal_key, sess);
	mlx_hook(sess->win_ptr, EXIT_WINDOW_ACTION, 0, ft_close, (void *)sess);
	mlx_hook(sess->win_ptr, 4, 0, mouse_press, sess);
	mlx_hook(sess->win_ptr, 6, 0, mouse_move, sess->mouse);
	mlx_loop(sess->mlx_ptr);
}
