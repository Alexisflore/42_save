/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:26:30 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/14 02:04:00 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int   player_move(int key, t_data *data)
// {
//    //erase the previous position of the player
//     pixel_drawing(data, pixel(data->px, data->py, 10, 0x00000000));
//     if (key == KEY_UP && is_wall(data, key) == false)
//         data->py -= 10;
//     else if (key == KEY_DOWN && is_wall(data, key) == false)
//         data->py += 10;
//     else if (key == KEY_LEFT && is_wall(data, key) == false)
//         data->px -= 10;
//     else if (key == KEY_RIGHT && is_wall(data, key) == false)
//         data->px += 10;
//     else if (key == ESC_KEY)
//     {
//         mlx_destroy_window(data->mlx, data->win);
//         exit(0);
//     }
//     //draw the new position of the player
//     pixel_drawing(data, pixel(data->px, data->py, 10, 0x00FF0000));
//     return (0);
// }
void	init_x_y_wall(t_data *data, double *x, double *y, int key)
{
	if (key == KEY_UP)
	{
		*x += data->pdx;
		*y += data->pdy;
	}
	else if (key == KEY_DOWN)
	{
		*x -= data->pdx;
		*y -= data->pdy;
	}
	else if (key == KEY_RIGHT)
	{
		*x -= data->pdy;
		*y += data->pdx;
	}
	else if (key == KEY_LEFT)
	{
		*x += data->pdy;
		*y -= data->pdx;
	}
}

bool	is_wall(t_data *data, int key)
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

void	key_move(int key, t_data *data)
{
	if (key == KEY_UP)
	{
		data->px += data->pdx;
		data->py += data->pdy;
	}
	else if (key == KEY_DOWN)
	{
		data->px -= data->pdx;
		data->py -= data->pdy;
	}
	else if (key == KEY_RIGHT)
	{
		data->px -= data->pdy;
		data->py += data->pdx;
	}
	else if (key == KEY_LEFT)
	{
		data->px += data->pdy;
		data->py -= data->pdx;
	}
}

void	key_cam_move(int key, t_data *data)
{
	if (key == KEY_CAM_LEFT)
	{
		data->pa -= 0.1;
		if (data->pa < 0)
			data->pa += 2 * PI;
		data->pdx = cos(data->pa) * 10;
		data->pdy = sin(data->pa) * 10;
	}
	else if (key == KEY_CAM_RIGHT)
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
	if (key == ESC_KEY)
	{
		free_path(&data->path);
		free_data(data);
		exit(0);
	}
	else if (key == KEY_CAM_LEFT || key == KEY_CAM_RIGHT)
		key_cam_move(key, data);
	else if (is_wall(data, key) == false)
		key_move(key, data);
	drawrays_3d(data);
	return (0);
}
