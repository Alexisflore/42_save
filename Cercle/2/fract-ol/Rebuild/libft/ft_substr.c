/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:10:51 by alfloren          #+#    #+#             */
/*   Updated: 2023/11/15 18:11:04 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <string.h>

// size_t	ft_strlen1(const char *s)
// {
// 	size_t	i;

// 	i = -1;
// 	while (*(s + ++i))
// 		;
// 	return (i);
// }

// size_t	ft_strlen2(const char *s)
// {
// 	size_t	i;

// 	i = -1;
// 	while (*(s + ++i))
// 		;
// 	return (i);
// }

// void	ft_putstr_fd1(char *s, int fd)
// {
// 	if (fd >= 0)
// 		write(fd, s, ft_strlen2(s));
// }

// int main(int argc, char **argv)
// {
// 	ft_putstr_fd1(ft_substr("abcdefg", 3, 2), 1);
// 	ft_putstr_fd1(substr("abcdefg", 3, 2), 1);
// 	return (0);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	str = (char*)malloc(sizeof(*s) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (i >= start && j < len)
// 		{
// 			str[j] = s[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	str[j] = 0;
// 	return (str);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || !(*s))
		len = 0;
	else if (start + len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len && s[start + i] && start < ft_strlen(s))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
