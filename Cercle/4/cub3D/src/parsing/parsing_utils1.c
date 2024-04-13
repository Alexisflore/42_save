/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:32:32 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/13 17:24:49 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	array_size(char **array)
{
	int	size;

	size = 0;
	if (array == NULL)
		return (0);
	while (array[size] != NULL)
		size++;
	return (size);
}

void	delete_newline(char ***array)
{
	int	i;
	int	j;

	i = 0;
	while ((*array)[i] != NULL)
	{
		j = 0;
		while ((*array)[i][j] != '\0')
		{
			if ((*array)[i][j] == '\n')
				(*array)[i][j] = '\0';
			j++;
		}
		i++;
	}
	i = 0;
	while ((*array)[i] != NULL)
	{
		if ((*array)[i][0] == '\0')
			(*array)[i] = NULL;
		i++;
	}
}
