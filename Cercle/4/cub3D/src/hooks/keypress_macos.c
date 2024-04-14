/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_macos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:50:30 by ladloff           #+#    #+#             */
/*   Updated: 2024/04/14 13:32:44 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#ifdef __APPLE__

static void	init_x_y_wall(t_data *data, double *x, double *y, int key)
{
	if (key == APPLE_KEY_W)
	{
		*x += data->pdx;
		*y += data->pdy;
	}
	else if (key == APPLE_KEY_S)
	{
		*x -= data->pdx;
		*y -= data->pdy;
	}
	else if (key == APPLE_KEY_D)
	{
		*x -= data->pdy;
		*y += data->pdx;
	}
	else if (key == APPLE_KEY_A)
	{
		*x += data->pdy;
		*y -= data->pdx;
	}
}

static void	key_move(int key, t_data *data)
{
	if (key == APPLE_KEY_W)
	{
		data->px += data->pdx;
		data->py += data->pdy;
	}
	else if (key == APPLE_KEY_S)
	{
		data->px -= data->pdx;
		data->py -= data->pdy;
	}
	else if (key == APPLE_KEY_D)
	{
		data->px -= data->pdy;
		data->py += data->pdx;
	}
	else if (key == APPLE_KEY_A)
	{
		data->px += data->pdy;
		data->py -= data->pdx;
	}
}

static bool	is_wall(t_data *data, int key)
{
	double	x;
	double	y;

	x = data->px;
	y = data->py;
	init_x_y_wall(data, &x, &y, key);
	if (data->map[(int)(y / PIXEL_SIZE)][(int)(x / PIXEL_SIZE)] == 1
		|| data->map[(int)((y) / PIXEL_SIZE)][(int)((x) / PIXEL_SIZE)] == 1)
		return (true);
	return (false);
}

static void	key_cam_move(int key, t_data *data)
{
	if (key == APPLE_KEY_LEFT)
	{
		data->pa -= 0.1;
		if (data->pa < 0)
			data->pa += 2 * PI;
		data->pdx = cos(data->pa) * 10;
		data->pdy = sin(data->pa) * 10;
	}
	else if (key == APPLE_KEY_RIGHT)
	{
		data->pa += 0.1;
		if (data->pa > 2 * PI)
			data->pa -= 2 * PI;
		data->pdx = cos(data->pa) * 10;
		data->pdy = sin(data->pa) * 10;
	}
}

int	player_move_with_angle(int key, t_data *data)
{
	if (key == APPLE_KEY_ESCAPE)
	{
		free_path(data, data->path);
		free_data(data);
		exit(0);
	}
	else if (key == APPLE_KEY_LEFT || key == APPLE_KEY_RIGHT)
		key_cam_move(key, data);
	else if (is_wall(data, key) == false)
		key_move(key, data);
	drawrays_3d(data);
	return (0);
}

#endif
