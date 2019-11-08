/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:48:37 by cspider           #+#    #+#             */
/*   Updated: 2019/10/01 17:04:11 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexisdigit(char c)
{
	if (ft_isdigit(c) || (c >= 'a' && c <= 'f') ||
		(c >= 'A' && c <= 'F'))
		return (1);
	else
		return (0);
}
