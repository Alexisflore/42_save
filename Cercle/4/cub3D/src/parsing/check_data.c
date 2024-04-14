/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:12:31 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/14 03:03:41 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_first_texture(t_data *data, t_xpm **texture, t_path *path)
{
	if (*texture != NULL)
		error_path(data, path, "Error\nDuplicate texture\n");
	*texture = malloc(sizeof(t_xpm));
	if (*texture == NULL)
		error_path(data, path, "Error\nMalloc texture\n");
	init_img_xpm(texture, data, path, path->split[1]);
}

void	check_texture(t_data *data, t_path *path)
{
	if (ft_strcmp(path->split[0], "SO") == 0)
		check_first_texture(data, &path->textures->south, path);
	else if (ft_strcmp(path->split[0], "WE") == 0)
		check_first_texture(data, &path->textures->west, path);
	else if (ft_strcmp(path->split[0], "EA") == 0)
		check_first_texture(data, &path->textures->east, path);
	else if (ft_strcmp(path->split[0], "NO") == 0)
		check_first_texture(data, &path->textures->north, path);
}

void	check_nbr(t_data *data, char *str, t_path *path, int *rgb)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 3)
		error_path(data, path, "Error\nInvalid RGB value\n");
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			error_path(data, path, "Error\nInvalid RGB value\n");
		i++;
	}
	*rgb = ft_atoi(str);
	if (*rgb < 0 || *rgb > 255)
		error_path(data, path, "Error\nInvalid RGB value\n");
}

void	check_rgb(t_data *data, t_path *path)
{
	path->rgb = ft_split(path->split[1], ',');
	if (path->rgb == NULL)
		error_path(data, path, "Error\nMalloc RGB\n");
	if (array_size(path->rgb) != 3)
		error_path(data, path, "Error\nWrong rgb argument");
	if (ft_strcmp(path->split[0], "F") == 0)
		create_rgb(data, path, &path->floor);
	else if (ft_strcmp(path->split[0], "C") == 0)
		create_rgb(data, path, &path->ceiling);
	free_char_array(path->rgb);
	path->rgb = NULL;
}

void	check_wall_around(t_data *data, t_path *path, int i, int j)
{
	if (path->map_array[i][j] == 0 || path->map_array[i][j] == 2)
		test4wall(data, path, i, j);
}
