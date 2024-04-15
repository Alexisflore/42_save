/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:28:26 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/15 15:48:15 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <time.h>

void	put_pxl_to_img(t_data *data, int x, int y, int color)
{
	if (x < 1200 && y < 640)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->addr + 4 * 1200 * y + x * 4, &color,
			sizeof(int));
	}
}

void	put_pxl_to_720_img(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	if (x < 1200 && y < HEIGHT)
	{
		color = mlx_get_color_value(data->mlx, color);
		j = 0;
		while (j < 2)
		{
			i = 0;
			while (i < 2)
			{
				ft_memcpy(data->addr + 4 * 1200 * (y + j) + (x + i) * 4, &color,
					sizeof(int));
				i++;
			}
			j++;
		}
	}
}

t_wall	*init_wall(t_data *data, t_ray *rayH, t_ray *rayV)
{
	t_wall	*wall;

	wall = malloc(sizeof(t_wall));
	if (wall == NULL)
		exit_error("Error malloc wall\n", data);
	data->shade = 1;
	find_dist_t(data, rayH, rayV);
	wall->lineh = (PIXEL_SIZE * 320) / data->dist;
	wall->ty_step = 64.0 / (double)wall->lineh;
	wall->lineoff = (320 / 2) - wall->lineh / 2;
	wall->ty = 0;
	wall->tx = 0;
	if (data->shade == 1)
	{
		wall->tx = (int)(rayH->rx * 2) % PIXEL_SIZE;
		if (rayH->ra > PI)
			wall->tx = PIXEL_SIZE - wall->tx - 1;
	}
	else
	{
		wall->tx = (int)(rayV->ry * 2) % PIXEL_SIZE;
		if (rayV->ra < P2 || rayV->ra > P3)
			wall->tx = PIXEL_SIZE - wall->tx - 1;
	}
	return (wall);
}

void	draw_3d_wall(t_data *data, t_ray *rayH, t_ray *rayV)
{
	t_wall	*wall;
	int		j;

	wall = init_wall(data, rayH, rayV);
	j = 0;
	while (j < wall->lineh && wall->lineoff + j <= 320)
	{
		if (wall->lineoff + j >= 0)
		{
			wall->color = data->texture->texture[(int)wall->tx + PIXEL_SIZE
				* (int)wall->ty];
			put_pxl_to_720_img(data, rayH->r * 2, wall->lineoff * 2 + j * 2,
				wall->color);
		}
		wall->ty += wall->ty_step;
		j++;
	}
	free(wall);
}

void	drawrays_3d(t_data *data)
{
	t_ray	rayh;
	t_ray	rayv;

	drawmap(data);
	rayv.ra = data->pa - DR * 300;
	find_angle(&rayh, &rayv);
	rayh.r = 0;
	while (rayh.r < 600)
	{
		check_horizontal_lines(data, &rayh);
		check_vertical_lines(data, &rayv);
		draw_3d_wall(data, &rayh, &rayv);
		rayv.ra += DR;
		find_angle(&rayh, &rayv);
		rayh.r += 1;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
