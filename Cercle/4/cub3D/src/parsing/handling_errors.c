/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:55:00 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/14 14:33:09 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_path(t_data *data, t_path *path)
{
	if (path == NULL)
		return ;
	if (path->textures != NULL)
	{
		free_texture(data, path->textures->west);
		free_texture(data, path->textures->east);
		free_texture(data, path->textures->north);
		free_texture(data, path->textures->south);
	}
	get_next_line(-1, true);
	free(path->textures);
	free(path->floor);
	free(path->ceiling);
	free_map(path->map);
	free_intarray(path->map_array);
	free_char_array(path->split);
	free_char_array(path->rgb);
	free(path->line);
	free(path);
}

void	error_path(t_data *data, t_path *path, char *message)
{
	ft_putstr_fd(message, 2);
	free_path(data, path);
	free_data(data);
	exit(1);
}

void	error_check(t_path *path, char *message)
{
	ft_putstr_fd(message, 2);
	free(path);
	exit(1);
}
