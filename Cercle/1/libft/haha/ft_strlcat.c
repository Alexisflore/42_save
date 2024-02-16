/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:03:57 by alfloren          #+#    #+#             */
/*   Updated: 2023/11/15 13:55:25 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_length;
	size_t	src_length;

	if ((!src || !dst) && !size)
		return (0);
	src_length = ft_strlen(src);
	dest_length = ft_strlen(dst);
	i = 0;
	while (src && src[i] && dest_length + i < size - 1 && size > 0)
	{
		dst[dest_length + i] = src[i];
		i++;
	}
	dst[dest_length + i] = 0;
	if (dest_length >= size)
		dest_length = size;
	return (dest_length + src_length);
}
