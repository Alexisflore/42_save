/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:15:25 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/07 18:54:05 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;

	i = 0;
	s = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			s = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (i > (INT_MAX - (*nptr - '0')) / 10
			|| i < (-INT_MAX - 1 + (*nptr - '0')) / 10)
			return (0);
		i = i * 10 + (*nptr - '0') * s;
		nptr++;
	}
	return (i);
}
