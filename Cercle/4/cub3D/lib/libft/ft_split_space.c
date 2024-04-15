/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:25:12 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/15 17:42:48 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static int	countwords(const char *s)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	if (!s)
		return (-1);
	if (s && s[i] && !is_whitespace(s[i]))
	{
		sum++;
		i++;
	}
	while (s[i] && s)
	{
		if (!is_whitespace(s[i]) && is_whitespace(s[i - 1]))
			sum++;
		i++;
	}
	return (sum);
}

static int	longword(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && !is_whitespace(s[i]))
		i++;
	return (i);
}

static char	**free_split(char **split)
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

char	**ft_split_space(char const *s)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**split;

	split = malloc(sizeof(char *) * (countwords(s) + 1));
	if (!split || !s)
		return (NULL);
	i = -1;
	k = 0;
	while (++i < ft_strlen(s))
	{
		if (!is_whitespace(s[i]))
		{
			split[k] = malloc(sizeof(char) * (1 + longword(s + i)));
			if (!split[k])
				return (free_split(split));
			j = 0;
			while (s[i] && !is_whitespace(s[i]))
				split[k][j++] = s[i++];
			split[k++][j] = 0;
		}
	}
	split[k] = NULL;
	return (split);
}
