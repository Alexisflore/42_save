/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:10:07 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/15 17:32:44 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#ifdef __linux__

void	cleanup_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
	{
		mlx_loop_end(mlx->mlx);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}

#elif __APPLE__

/**
 * Avoid the usage of mlx_loop_end and mlx_destroy_display
 * Because we use the OpenGL Lib and these functions aren't present
 */
void	cleanup_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		free(mlx->mlx);
}

#endif

void	free_texture(t_mlx *mlx, t_xpm *xpm)
{
	if (xpm == NULL)
		return ;
	if (xpm->img)
		mlx_destroy_image(mlx->mlx, xpm->img);
	free(xpm);
}

void	free_path(t_data *data, t_path *path)
{
	if (path == NULL)
		return ;
	if (path->textures != NULL)
	{
		free_texture(&data->mlx, path->textures->west);
		free_texture(&data->mlx, path->textures->east);
		free_texture(&data->mlx, path->textures->north);
		free_texture(&data->mlx, path->textures->south);
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
}
