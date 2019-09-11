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

#include "../libft/libft.h"

typedef struct	s_tetra
{
	int			letter;
	int			x[3];
	int			y[3];
	int			end;
}				t_tetra;

void			read_fillit(int fd, t_tetra ***tetras);
t_tetra			*fill_tetras(void);
void			fill_field(int field[104][104]);
void			print_field(int field[104][104], int size);


#endif
