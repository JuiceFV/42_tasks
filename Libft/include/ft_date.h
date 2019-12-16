/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:13:15 by cspider           #+#    #+#             */
/*   Updated: 2019/10/05 13:17:31 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATE_H
# define FT_DATE_H

# include <stdint.h>

# define SEC_PER_MIN         60
# define SEC_PER_HOUR        3600
# define SEC_PER_DAY         86400
# define MON_PER_YEAR        12
# define EPOCH_YEAR          1970
# define IS_LEAP_YEAR_(year) (((year) % 4 == 0) && ((year) % 100 != 0))
# define IS_LEAP_YEAR(year)	(IS_LEAP_YEAR_(year) || ((year) % 400 == 0))
# define YEARSIZE(year)	(IS_LEAP_YEAR(year) ? 366 : 365)

long long	ft_datetoepoch(long date[6]);
long		*ft_epochtodate(long long epoch);

#endif
