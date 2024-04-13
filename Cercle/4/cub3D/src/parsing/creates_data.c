/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creates_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:21:12 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/13 17:42:14 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	create_map_array(t_path *path)
{
	int		i;
	t_map	*tmp;

	i = 0;
	path->mapx = max_size(path, path->map);
	path->mapy = size_x(path->map);
	path->map_array = malloc(sizeof(int *) * (path->mapy + 1));
	if (path->map_array == NULL)
		error_path(path, "Error\nMalloc map_array\n");
	tmp = path->map;
	while (i < path->mapy)
	{
		create_x_array(path, i, tmp);
		tmp = tmp->next;
		i++;
	}
	free_map(&path->map);
	path->map = NULL;
}

void	create_x_array(t_path *path, int i, t_map *tmp)
{
	int	j;

	j = 0;
	path->map_array[i] = malloc(sizeof(int) * (path->mapx) + 1);
	if (path->map_array[i] == NULL)
		error_path(path, "Error\nMalloc map_array\n");
	while (j < tmp->size)
	{
		path->map_array[i][j] = tmp->line[j];
		if (tmp->line[j] == 2)
			initial_position(path, j, i, path->player_orientation);
		j++;
	}
	while (j < path->mapx)
	{
		path->map_array[i][j] = -1;
		j++;
	}
	path->map_array[i][j] = '\0';
}

void	create_map(t_path *path)
{
	t_map	*new;
	int		i;

	new = malloc(sizeof(t_map));
	if (new == NULL)
		error_path(path, "Error\nMalloc map\n");
	init_tmap(new, path);
	i = 0;
	if (path->line[new->size - 1] == '\n')
	{
		path->line[new->size - 1] = '\0';
		new->size--;
	}
	while (path->line[i] != '\0')
	{
		new->line[i] = int_line(&path, i);
		i++;
	}
	new->line[i] = '\0';
	t_map_add_back(&(path->map), new);
	free(path->line);
	path->line = NULL;
}

void	create_rgb(t_path *path, t_rgb **rgb)
{
	if (*rgb != NULL)
		error_path(path, "Error\nDuplicate floor\n");
	*rgb = malloc(sizeof(t_rgb));
	if (*rgb == NULL)
		error_path(path, "Error\nMalloc floor\n");
	fill_rgb(path, rgb);
}

void	create_final_map(t_path *path)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < path->mapy)
	{
		x = 0;
		while (x < path->mapx)
		{
			if (path->map_array[y][x] == -1)
				path->map_array[y][x] = 1;
			x++;
		}
		y++;
	}
}
