/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:44:30 by olongbot          #+#    #+#             */
/*   Updated: 2019/10/05 15:57:01 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_session *sess)
{
	t_list	*point;
	t_list	*p_below;
	int		i;

	point = sess->map->points;
	p_below = sess->map->points;
	i = -1;
	while (++i < sess->map->width && p_below != NULL)
		p_below = p_below->next;
	i = 1;
	while (point->next != NULL)
	{
		if (i % sess->map->width != 0)
			ft_mlx_line(cr_line((*((t_vector *)(point->content))),
						*((t_vector *)((point->next)->content))), *sess);
		if (p_below != NULL)
		{
			ft_mlx_line(cr_line((*((t_vector *)point->content)),
						*((t_vector *)(p_below->content))), *sess);
			p_below = p_below->next;
		}
		point = point->next;
		i++;
	}
}

int		ft_close(t_session *s)
{
	if (s && s->map && s->map->points)
		free_list(s->map->points);
	if (s && s->map)
		free(s->map);
	if (s && s->mouse)
		free(s->mouse);
	if (s)
		free(s);
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_session	*sess;
	t_map		*map;
	int			fd;

	if (argc != 2)
	{
		ft_putstr("usage: fdf map.txt\n");
		(void)argv;
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	sess = sess_init();
	map = map_init(sess);
	sess->map = map;
	read_file(sess, fd);
	iso2(sess);
	redraw(sess);
	hooks_init(sess);
}
