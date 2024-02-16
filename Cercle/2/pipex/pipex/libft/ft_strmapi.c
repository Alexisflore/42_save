/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:55:54 by alfloren          #+#    #+#             */
/*   Updated: 2023/11/07 18:29:41 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup1(const char *s)
{
	char	*copy;
	int		i;

	if (!s)
		return (NULL);
	copy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		copy[i] = *(s + i);
		i++;
	}
	copy[i] = 0;
	return (copy);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapi;
	size_t	i;

	i = -1;
	mapi = ft_strdup1(s);
	if (!mapi)
		return (NULL);
	while (mapi[++i])
		mapi[i] = (*f)(i, mapi[i]);
	return (mapi);
}
