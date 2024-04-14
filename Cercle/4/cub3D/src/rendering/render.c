/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:28:26 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/14 14:41:58 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <time.h>

void	put_pxl_to_img(t_data *data, int x, int y, int color)
{
	if (x < SIDE_LEN && y < SIDE_LEN)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->addr + 4 * SIDE_LEN * y + x * 4, &color,
			sizeof(int));
	}
}

int	get_fps(void)
{
	static int		fps = 0;
	static clock_t	time = 0;
	static clock_t	old_time = 0;
	static int		frames = 0;
	static int		old_frames = 0;

	time = clock();
	if (time - old_time > CLOCKS_PER_SEC)
	{
		fps = frames - old_frames;
		old_time = time;
		old_frames = frames;
	}
	frames++;
	return (fps);
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
	wall->lineoff = 160 - wall->lineh / 2;
	wall->ty = 0;
	wall->tx = 0;
	if (data->shade == 1)
	{
		wall->tx = (int)(rayH->rx * 2) % 64;
		if (rayH->ra > PI)
			wall->tx = 64 - wall->tx - 1;
	}
	else
	{
		wall->tx = (int)(rayV->ry * 2) % 64;
		if (rayV->ra < P2 || rayV->ra > P3)
			wall->tx = 64 - wall->tx - 1;
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
			wall->color = data->texture->texture[(int)wall->tx + 64
				* (int)wall->ty];
			put_pxl_to_img(data, rayH->r, wall->lineoff + j, wall->color);
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
	rayv.ra = data->pa - DR * 30 * 10;
	find_angle(&rayh, &rayv);
	rayh.r = 0;
	while (rayh.r < 60 * 10)
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
