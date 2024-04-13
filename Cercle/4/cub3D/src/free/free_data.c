/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:10:07 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/13 17:06:50 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_texture(t_xpm **data)
{
	if (*data == NULL)
		return ;
	free((*data)->addr);
	free((*data)->img);
	free(*data);
	*data = NULL;
}

void	free_data(t_data **data)
{
	if ((*data) == NULL)
		return ;
	mlx_destroy_window((*data)->mlx, (*data)->win);
	free((*data)->mlx);
	free((*data)->img);
	free((*data)->img_ptr);
	free((*data));
	*data = NULL;
}

void	free_intarray(int **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	free_map(t_map **map)
{
	t_map	*tmp;

	if (map == NULL)
		return ;
	while (*map != NULL)
	{
		tmp = *map;
		*map = (*map)->next;
		free(tmp->line);
		free(tmp);
	}
	free(*map);
}
