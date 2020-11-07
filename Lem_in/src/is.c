/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:34:39 by olongbot          #+#    #+#             */
/*   Updated: 2018/10/26 23:59:47 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_command(char *str)
{
	if (str)
	{
		if (ft_strlen(str) >= 2
			&& !ft_strncmp(str, "##", 2))
			return (1);
	}
	return (0);
}

int			is_comment(char *str)
{
	if (str)
	{
		if (ft_strlen(str)
			&& !is_command(str)
			&& !ft_strncmp(str, "#", 1))
			return (1);
	}
	return (0);
}

static int	is_room_name(char *str)
{
	if (str && ft_strlen(str))
	{
		if (str[0] != 'L' && str[0] != '#')
			return (1);
	}
	return (0);
}

int			is_room(char *str)
{
	int		result;
	char	**strsplit;

	result = 0;
	if (!(strsplit = ft_strsplit(str, ' ')))
		terminate("ERROR");
	if (ft_strsplit_len(strsplit) == 3)
	{
		if (is_room_name(strsplit[0])
			&& ft_isint(strsplit[1], 1)
			&& ft_isint(strsplit[2], 1))
			result = 1;
	}
	ft_strsplit_free(&strsplit);
	return (result);
}
