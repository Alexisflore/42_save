/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:16:58 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/14 18:35:08 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_textures_and_rgb(t_data *data, t_path *path)
{
	path->split = ft_split_space(path->line);
	if (path->split == NULL)
		error_path(data, path, "Error\nMalloc split\n");
	delete_newline(&path->split);
	if (array_size(path->split) != 2)
		error_path(data, path, "Error\nWrong arguments");
	if (is_texture(path->split[0]) == 1)
		check_texture(data, path);
	else if (is_rgb(path->split[0]) == 1)
		check_rgb(data, path);
	free_char_array(path->split);
	path->split = NULL;
}

void	check_map(t_data *data, t_path *path)
{
	create_map_array(data, path);
	verify_closed_map(data, path);
}

void	test4wall(t_data *data, t_path *path, int i, int j)
{
	if (i == 0 || i == path->mapy - 1 || j == 0 || j == path->mapx - 1)
		error_path(data, path, "Error\nMap not closed\n");
	if (path->map_array[i - 1][j] == -1 || path->map_array[i + 1][j] == -1
		|| path->map_array[i][j - 1] == -1 || path->map_array[i][j + 1] == -1)
		error_path(data, path, "Error\nMap not closed\n");
}

void	verify_closed_map(t_data *data, t_path *path)
{
	int	i;
	int	j;

	i = 0;
	while (i < path->mapy)
	{
		j = 0;
		while (j < path->mapx)
		{
			check_wall_around(data, path, i, j);
			j++;
		}
		i++;
	}
}

void	initial_position(t_path *path, int x, int y, char c)
{
	path->player_x = 64 * x + 32;
	path->player_y = 64 * y + 32;
	if (c == 'N')
		path->player_angle = P3;
	else if (c == 'S')
		path->player_angle = PI / 2;
	else if (c == 'W')
		path->player_angle = PI;
	else if (c == 'E')
		path->player_angle = 0;
}
