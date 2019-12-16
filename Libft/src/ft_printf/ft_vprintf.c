/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:59:40 by olongbot          #+#    #+#             */
/*   Updated: 2019/10/06 17:00:19 by olongbot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vprintf(char const *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

int		ft_vdprintf(int fd, char const *format, va_list ap)
{
	char	*str;
	int		res;

	res = ft_vasprintf(&str, format, ap);
	if (res == -1)
		write(fd, str, ft_strlen(str));
	else
		write(fd, str, res);
	free(str);
	return (res);
}

/*
** TODO
** Finished | +
** Norme    | -
** Errors   | -
** Logic    | -
** Checked  | -
** included | -
*/
