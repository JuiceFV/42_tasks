/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:26:40 by cspider           #+#    #+#             */
/*   Updated: 2019/09/02 22:26:45 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int			iter;
	int long	iter2;

	iter = 1;
	iter2 = 1;
	while (iter2 * iter2 < nb)
	{
		iter++;
		iter2++;
	}
	if (iter * iter == nb)
	{
		return (iter);
	}
	else
	{
		return (0);
	}
}
