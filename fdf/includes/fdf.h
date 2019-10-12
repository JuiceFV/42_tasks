/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:06 by olongbot          #+#    #+#             */
/*   Updated: 2019/10/12 15:17:25 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <../libft/libft.h>
# include <fcntl.h>
# include <math.h>
# define EXIT_WINDOW_ACTION	17
# define WIN_WIDTH			1280
# define WIN_HEIGHT			720
# define WIN_NAME			"Rainbow Crash"

typedef struct	s_mouse
{
	int			pressed;
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;
}				t_mouse;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	double		o_x;
	double		o_y;
	double		o_z;
	int			color;
}				t_vector;

typedef struct	s_line
{
	t_vector	start;
	t_vector	end;
	int			dx;
	int			dy;
}				t_line;

typedef struct	s_points
{
	int			**xyz;
	int			h;
	int			w;
}				t_points;

typedef struct	s_map
{
	t_list		*points;
	int			width;
	int			height;
	int			z_scale;
	int			scale;
	int			max_z;
}				t_map;

typedef struct	s_session
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mouse		*mouse;
	void		*img_ptr;
	t_map		*map;
	char		*img;
	int			size_line;
	int			bits_per_pixel;
	int			d_move_x;
	int			d_move_y;
	int			endian;
	double		delta;
	int			iso;
}				t_session;

void			ft_mlx_line(t_line line, t_session sess);
int				rgb2one(int r, int g, int b);
int				ft_close(t_session *s);
void			ft_putchar(char c);
int				deal_key(int key, void *param);
t_vector		cr_vec(int x, int y, int z, int color);
t_line			cr_line(t_vector st, t_vector end);
int				mouse_press(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
t_session		*sess_init();
void			death(char *er, char *f, int l, t_session *s);
void			mlx_putpix(t_session *sess, t_vector vec);
void			x_rotation(t_vector *vec, double t);
void			y_rotation(t_vector *vec, double t);
void			z_rotation(t_vector *vec, double t);
t_map			*map_init(t_session *s);
void			hooks_init(t_session *sess);
void			apply_rot(t_list *p, char a, double d);
void			draw_map(t_session *sess);
void			apply_rot(t_list *p, char a, double d);
void			apply_move(t_list *p, char a, double d);
void			read_file(t_session *s, int fd);
void			map_center(t_map *map);
void			map_scale(t_session *s);
void			redraw(t_session *s);
int				im(t_list *v);
void			free_list(t_list *t);
int				calc_color(t_session *s, t_vector a, t_vector b);
void			map_origin(t_session *s);
void			map_iso(t_session *s);
void			iso(t_session *s);
void			iso2(t_session *s);
#endif
