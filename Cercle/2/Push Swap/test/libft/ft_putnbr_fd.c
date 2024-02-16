/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:25:42 by alfloren          #+#    #+#             */
/*   Updated: 2023/11/07 18:06:31 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar_fd1(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (fd >= 0)
	{
		if (nb < 0)
		{
			nb = -nb;
			write(fd, "-", 1);
		}
		if (nb < 10)
			ft_putchar_fd1(nb + '0', fd);
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putchar_fd1(nb % 10 + '0', fd);
		}
	}
}
