/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:25:23 by cspider           #+#    #+#             */
/*   Updated: 2019/10/03 16:28:07 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WCHAR_H
# define FT_WCHAR_H

# include <wchar.h>
# include "libft.h"

size_t		ft_wstrlen(const wchar_t *wstr);
size_t		ft_wstrconv(char *buff, const wchar_t *wstr);
size_t		ft_wstrnconv(char *buff, const wchar_t *wstr, size_t n);
size_t		ft_widetoa(char *buff, wint_t w);

#endif
