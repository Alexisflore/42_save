/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:03:22 by ladloff           #+#    #+#             */
/*   Updated: 2024/02/15 17:37:21 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len_total;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	len_total = ft_strlen(s1) + ft_strlen(s2);
	strjoin = malloc((len_total + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	i = -1;
	while (s1[++i])
		strjoin[i] = s1[i];
	j = -1;
	while (i + ++j < len_total)
		strjoin[i + j] = s2[j];
	strjoin[i + j] = '\0';
	return (strjoin);
}

char	*ft_strjoin1(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len_total;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	len_total = ft_strlen(s1) + ft_strlen(s2);
	strjoin = malloc((len_total + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	i = -1;
	while (s1[++i])
		strjoin[i] = s1[i];
	j = -1;
	while (i + ++j < len_total)
		strjoin[i + j] = s2[j];
	strjoin[i + j] = '\0';
	free(s1);
	return (strjoin);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len_total;
	char	*strjoin;

	if (!s2)
		return (NULL);
	if (!s1)
		len_total = ft_strlen(s2);
	else
		len_total = ft_strlen(s1) + ft_strlen(s2);
	strjoin = malloc((len_total + 1) * sizeof(char));
	if (!strjoin)
		return (free(s1), free(s2), NULL);
	i = -1;
	if (s1)
		while (s1[++i])
			strjoin[i] = s1[i];
	else
		i = 0;
	j = -1;
	while (i + ++j < len_total)
		strjoin[i + j] = s2[j];
	strjoin[i + j] = '\0';
	return (free(s1), free(s2), strjoin);
}

char	*ft_strjoin3(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len_total;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	len_total = ft_strlen(s1) + ft_strlen(s2);
	strjoin = malloc((len_total + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	i = -1;
	while (s1[++i])
		strjoin[i] = s1[i];
	j = -1;
	while (i + ++j < len_total)
		strjoin[i + j] = s2[j];
	strjoin[i + j] = '\0';
	free(s2);
	return (strjoin);
}
