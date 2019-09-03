/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 21:47:49 by cspider           #+#    #+#             */
/*   Updated: 2019/09/02 21:48:09 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int *temp;

	if (min >= max)
		return (NULL);
	temp = (int*)malloc(sizeof(int) * (max - min));
	i = min;
	while (i < max)
	{
		temp[i - min] = i;
		i++;
	}
	return (temp);
}
