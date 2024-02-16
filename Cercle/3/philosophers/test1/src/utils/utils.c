/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:01:58 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/22 10:37:30 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/philo.h"
#include <limits.h>

long long	ft_atoi(const char *str)
{
	long	result;

	while (*str > 8 && *str < 14)
		str++;
	if (*str == '-' && *(str + 1) != '0')
		return (-1);
	if (*str == '+' || *str == '-')
		str++;
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LLONG_MAX - (*str - '0')) / 10)
			return (-1);
		result = 10 * result + (*str - '0');
		str++;
	}
	if (*str != 0)
		return (-1);
	return (result);
}

int	input_checker(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) < 0)
			return (error("Invalid input", NULL));
	}
	return (0);
}

int	ft_usleep(long long time)
{
	usleep(time * 1000);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}
