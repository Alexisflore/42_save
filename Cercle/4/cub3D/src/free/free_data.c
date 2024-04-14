/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:10:07 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/14 08:17:13 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#ifdef __linux__

void	cleanup_mlx(t_data *data)
{
	if (!data)
		return ;
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

#elif __APPLE__

/**
 * Avoid the usage of mlx_loop_end and mlx_destroy_display
 * Because we use the OpenGL Lib and these functions aren't present
 */
void	cleanup_mlx(t_data *data)
{
	if (!data)
		return ;
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
}

#endif

void	free_texture(t_data *data, t_xpm *xpm)
{
	if (xpm == NULL)
		return ;
	if (xpm->img)
		mlx_destroy_image(data->mlx, xpm->img);
	free(xpm);
}

void	free_data(t_data *data)
{
	if (data == NULL)
		return ;
	cleanup_mlx(data);
}
