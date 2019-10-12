/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:18:52 by olongbot          #+#    #+#             */
/*   Updated: 2019/10/05 17:16:22 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		rgb2one(int r, int g, int b)
{
	int out;

	out = 0;
	out |= (r & 255) << 16 | (g & 255) << 8 | (b & 255);
	return (out);
}

void	mlx_putpix(t_session *sess, t_vector vec)
{
	int		pos;
	int		x;
	int		y;

	x = round(vec.x * sess->map->scale) + WIN_WIDTH / 2 + sess->d_move_x;
	y = round(vec.y * sess->map->scale) + WIN_HEIGHT / 2 + sess->d_move_y;
	pos = x * sess->bits_per_pixel + sess->size_line * y;
	if (x > WIN_WIDTH || y > WIN_HEIGHT || y < 0 || x < 0)
	{
		return ;
	}
	ft_memcpy(&(sess->img[pos]), &(vec.color), sess->bits_per_pixel);
}

void	free_list(t_list *t)
{
	t_list *tmp;

	while (t != NULL)
	{
		tmp = t->next;
		free(((t_vector *)(t->content)));
		free(t);
		t = tmp;
	}
}

int		im(t_list *v)
{
	if (v != NULL)
		free_list(v);
	return (1);
}

int		calc_color(t_session *s, t_vector a, t_vector b)
{
	double	result_red;
	double	result_green;
	double	result_blue;
	int		a_h;

	a_h = ft_abs((int)(((a.o_z + b.o_z) / 2 / s->map->max_z) * 255)) & 255;
	result_red = a_h;
	result_green = a_h;
	result_blue = 255;
	return (rgb2one(result_red, result_green, result_blue));
}
