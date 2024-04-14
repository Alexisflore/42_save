/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_linux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:50:36 by ladloff           #+#    #+#             */
/*   Updated: 2024/04/14 13:37:24 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#ifdef __linux__

static void	init_x_y_wall(t_data *data, double *x, double *y, int key)
{
	if (key == XK_w || key == XK_W)
	{
		*x += data->pdx;
		*y += data->pdy;
	}
	else if (key == XK_s || key == XK_S)
	{
		*x -= data->pdx;
		*y -= data->pdy;
	}
	else if (key == XK_d || key == XK_D)
	{
		*x -= data->pdy;
		*y += data->pdx;
	}
	else if (key == XK_a || key == XK_A)
	{
		*x += data->pdy;
		*y -= data->pdx;
	}
}

static void	key_move(int key, t_data *data)
{
	if (key == XK_w || key == XK_W)
	{
		data->px += data->pdx;
		data->py += data->pdy;
	}
	else if (key == XK_s || key == XK_S)
	{
		data->px -= data->pdx;
		data->py -= data->pdy;
	}
	else if (key == XK_d || key == XK_D)
	{
		data->px -= data->pdy;
		data->py += data->pdx;
	}
	else if (key == XK_a || key == XK_A)
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
	if (key == XK_Left)
	{
		data->pa -= 0.1;
		if (data->pa < 0)
			data->pa += 2 * PI;
		data->pdx = cos(data->pa) * 10;
		data->pdy = sin(data->pa) * 10;
	}
	else if (key == XK_Right)
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
	if (key == XK_Escape)
	{
		free_path(data, data->path);
		free_data(data);
		exit(0);
	}
	else if (key == XK_Left || key == XK_Right)
		key_cam_move(key, data);
	else if (is_wall(data, key) == false)
		key_move(key, data);
	drawrays_3d(data);
	return (0);
}

#endif

