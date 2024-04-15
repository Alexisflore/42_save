/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:17:54 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/15 11:55:37 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	draw_ray(t_data *data, t_ray *rayH, t_ray *rayV, int color)
// {
// 	if (rayH->disT < rayV->disT)
// 	{
// 		draw_line(data, data->px, data->py, rayH->rx, rayH->ry, color);
// 	}
// 	else
// 	{
// 		draw_line(data, data->px, data->py, rayV->rx, rayV->ry, color);
// 	}
// }

void	draw_floor_and_ceiling(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < 1200)
	{
		y = 0;
		while (y < 640)
		{
			if (y < (HEIGHT / 2) && x < 1200)
				put_pxl_to_img(data, x, y, convert_rgb_to_hex(data->ceiling));
			else if (y >= (HEIGHT / 2) && y < HEIGHT && x < 1200)
				put_pxl_to_img(data, x, y, convert_rgb_to_hex(data->floor));
			y++;
		}
		x++;
	}
}

// draw the map
void	drawmap(t_data *data)
{
	draw_floor_and_ceiling(data);
}

void	directtion_line(t_data *data, int color)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		put_pxl_to_img(data, data->px + i * cos(data->pa) + 5, data->py + i
			* sin(data->pa) + 5, color);
		i++;
	}
}

// void draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
// {
//     int dx = x2 - x1;
//     int dy = y2 - y1;
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
//     float Xinc = dx / (float)steps;
//     float Yinc = dy / (float)steps;
//     float X = x1;
//     float Y = y1;
//     int i = 0;
//     while (i <= steps)
//     {
//         // mlx_pixel_put(data->mlx, data->win, X, Y, color);
//         put_pxl_to_img(data, X, Y, color);
//         X += Xinc;
//         Y += Yinc;
//         i++;
//     }
// }