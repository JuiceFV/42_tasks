/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:32:17 by olongbot          #+#    #+#             */
/*   Updated: 2019/10/05 14:56:07 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector		cr_vec(int x, int y, int z, int color)
{
	t_vector	out;

	out.x = x;
	out.y = y;
	out.z = z;
	out.o_x = x;
	out.o_y = y;
	out.o_z = z;
	out.color = color;
	return (out);
}

t_line			cr_line(t_vector st, t_vector end)
{
	t_line		out;
	t_vector	tmp;

	if (st.x > end.x)
	{
		tmp = st;
		st = end;
		end = tmp;
	}
	out.start = st;
	out.end = end;
	out.dx = end.x - st.x;
	out.dy = end.y - st.y;
	return (out);
}

static void		line_low(t_line l, t_session sess)
{
	int iy;
	int m;

	iy = 1;
	if (l.dy < 0)
	{
		iy = -1;
		l.dy *= -1;
	}
	m = 2 * l.dy - l.dx;
	while (l.start.x < l.end.x)
	{
		mlx_putpix(&sess, l.start);
		if (m > 0)
		{
			l.start.y += iy;
			m -= 2 * l.dx;
		}
		m += 2 * l.dy;
		l.start.x++;
	}
}

static void		line_high(t_line l, t_session sess)
{
	int ix;
	int m;

	ix = 1;
	if (l.dx < 0)
	{
		ix = -1;
		l.dx *= -1;
	}
	m = 2 * l.dx - l.dy;
	while (l.start.y < l.end.y)
	{
		mlx_putpix(&sess, l.start);
		if (m > 0)
		{
			l.start.x += ix;
			m -= 2 * l.dy;
		}
		m += 2 * l.dx;
		l.start.y++;
	}
}

void			ft_mlx_line(t_line line, t_session sess)
{
	t_vector	tmp;

	line.start.color = calc_color(&sess, line.start, line.end);
	line.end.color = calc_color(&sess, line.start, line.end);
	if (abs(line.dx) > abs(line.dy))
		line_low(line, sess);
	else
	{
		if (line.start.y > line.end.y)
		{
			tmp = line.start;
			line.start = line.end;
			line.end = tmp;
			line.dx *= -1;
			line.dy *= -1;
		}
		line_high(line, sess);
	}
	return ;
}
