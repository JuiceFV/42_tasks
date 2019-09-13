/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <myxaosa@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:07:56 by olongbot          #+#    #+#             */
/*   Updated: 2019/09/04 23:45:33 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_MINE_FILLIT_H
# define FILLIT_MINE_FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_tetra
{
	int			letter;
	int			x[3];
	int			y[3];
	int			end;
}				t_tetra;
int				read_fillit(int fd, t_tetra tetras[27]);
void			fill_field(int field[104][104]);
void			print_field(int field[104][104], int size);
int				print_error(void);
int				check_place(int *xy, t_tetra tetra,
							int field[104][104], int size);
void			tetra_set(int x, int y, t_tetra tetra, int field[104][104]);
void			tetra_unset(int x, int y, t_tetra tetra, int field[104][104]);
int				connections(char *str);
int				counts_hecker(char *str);
int				count_nl(char *s);

#endif
