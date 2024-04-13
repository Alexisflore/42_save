/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:25:44 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/13 17:41:21 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_rayh(t_ray *ray, t_data *data)
{
	float	atan;

	ray->dist = 1000000;
	ray->dof = 0;
	atan = -1 / tan(ray->ra);
	if (ray->ra > PI)
	{
		ray->ry = (((int)data->py >> 6) << 6) - 0.0001;
		ray->rx = (data->py - ray->ry) * atan + data->px;
		ray->yo = -PIXEL_SIZE;
		ray->xo = -ray->yo * atan;
	}
	if (ray->ra < PI)
	{
		ray->ry = (((int)data->py >> 6) << 6) + PIXEL_SIZE;
		ray->rx = (data->py - ray->ry) * atan + data->px;
		ray->yo = PIXEL_SIZE;
		ray->xo = -ray->yo * atan;
	}
	if (ray->ra == 0 || ray->ra == PI)
	{
		ray->rx = data->px;
		ray->ry = data->py;
		ray->dof = data->horizon;
	}
}

void	check_horizontal_lines(t_data *data, t_ray *ray)
{
	ray->dist = 1000000;
	init_rayh(ray, data);
	while (ray->dof < data->horizon)
	{
		ray->mx = (int)(ray->rx) >> 6;
		ray->my = (int)(ray->ry) >> 6;
		ray->mp = ray->my * ray->mx;
		if (ray->mx >= 0 && ray->my >= 0 && ray->mx < data->mapx
			&& ray->my < data->mapy && data->map[ray->my][ray->mx] == 1)
		{
			ray->dof = data->horizon;
			ray->dist = dist(data->px, data->py, ray->rx, ray->ry);
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
	}
}

void	init_rayv(t_ray *ray, t_data *data)
{
	double	ntan;

	ray->dof = 0;
	ray->dist = 1000000;
	ntan = -tan(ray->ra);
	if (ray->ra > P2 && ray->ra < P3)
	{
		ray->rx = (((int)data->px >> 6) << 6) - 0.0001;
		ray->ry = (data->px - ray->rx) * ntan + data->py;
		ray->xo = -PIXEL_SIZE;
		ray->yo = -ray->xo * ntan;
	}
	if (ray->ra < P2 || ray->ra > P3)
	{
		ray->rx = (((int)data->px >> 6) << 6) + PIXEL_SIZE;
		ray->ry = (data->px - ray->rx) * ntan + data->py;
		ray->xo = PIXEL_SIZE;
		ray->yo = -ray->xo * ntan;
	}
	if (ray->ra == 0 || ray->ra == PI)
	{
		ray->rx = data->px;
		ray->ry = data->py;
		ray->dof = data->horizon;
	}
}

void	check_vertical_lines(t_data *data, t_ray *ray)
{
	init_rayv(ray, data);
	while (ray->dof < data->horizon)
	{
		ray->mx = (int)(ray->rx) >> 6;
		ray->my = (int)(ray->ry) >> 6;
		ray->mp = ray->my * ray->mx;
		if (ray->mx >= 0 && ray->my >= 0 && ray->mx < data->mapx
			&& ray->my < data->mapy && data->map[ray->my][ray->mx] == 1)
		{
			ray->dof = data->horizon;
			ray->dist = dist(data->px, data->py, ray->rx, ray->ry);
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
	}
}
