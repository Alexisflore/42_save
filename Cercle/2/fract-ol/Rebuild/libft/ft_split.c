/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:05:53 by alfloren          #+#    #+#             */
/*   Updated: 2023/11/17 12:26:10 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h> // printf

int	countwords(const char *s, char c)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	if (!s)
		return (-1);
	if (s[i] != c && s[i] && s)
	{
		sum++;
		i++;
	}
	while (s[i] && s)
	{
		if (s[i] != c && s[i - 1] == c)
			sum++;
		i++;
	}
	return (sum);
}

int	longword(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**free_split(char **split)
{
	int	i;

	i = -1;
	if (split)
	{
		while (split[++i])
			free(split[i]);
		free(split);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**split;

	split = malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (!split || !s)
		return (NULL);
	i = -1;
	k = 0;
	while (++i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			split[k] = malloc(sizeof(char) * (1 + longword(s + i, c)));
			if (!split[k])
				return (free_split(split));
			j = 0;
			while (s[i] != c && s[i])
				split[k][j++] = s[i++];
			split[k++][j] = 0;
		}
	}
	split[k] = NULL;
	return (split);
}

// int	main(void)
// {
// 	int i = 0;
// 	char **tab;

// 	tab = ft_split("chinimala", ' ');
// 	while (tab[i])
// 	{
// 		printf("string %d : %s\n", i, tab[i]);
// 		i++;
// 	}
// 	return (0);
// }
