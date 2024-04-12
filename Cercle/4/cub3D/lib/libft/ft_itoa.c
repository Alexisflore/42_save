/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:25:23 by alfloren          #+#    #+#             */
/*   Updated: 2023/11/09 16:22:10 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	size(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

// char	*reverse(char *nbr)
// {
// 	int		i;
// 	int		j;
// 	char	c;

// 	j = ft_strlen(nbr) - 1;
// 	i = 0;
// 	while (i < j - i)
// 	{
// 		c = nbr[i];
// 		nbr[i] = nbr[j - i];
// 		nbr[j - i] = c;
// 		i++;
// 	}
// 	return (nbr);
// }

char	*ft_itoa(int nb)
{
	char	*nbr;
	int		len;
	long	n;

	n = nb;
	len = size(n);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	if (n == 0)
		nbr[0] = '0';
	nbr[len] = 0;
	len--;
	if (n < 0)
	{
		nbr[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		nbr[len--] = n % 10 + '0';
		n /= 10;
	}
	return (nbr);
}

// void	main()
// {
// 	printf("%s", ft_itoa(-2147483648));
// 	printf("%s", "hahah");
// }
