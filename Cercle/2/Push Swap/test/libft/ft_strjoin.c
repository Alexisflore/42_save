/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:28:28 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/07 16:18:47 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlen2(char const *nbr)
{
	int	i;

	i = 0;
	while (*(nbr + i))
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	str = malloc(sizeof(char) * (ft_strlen2(s1) + ft_strlen2(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2 && s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	return (str);
}
