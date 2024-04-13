/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:19:57 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/13 17:36:11 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_angle(t_ray *rayH, t_ray *rayV)
{
	if (rayV->ra < 0)
		rayV->ra += 2 * PI;
	if (rayV->ra > 2 * PI)
		rayV->ra -= 2 * PI;
	rayH->ra = rayV->ra;
}

void	find_dist_t(t_data *data, t_ray *rayH, t_ray *rayV)
{
	double	ca;

	ca = data->pa - rayH->ra;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	if (rayH->dist < rayV->dist)
	{
		data->dist = rayH->dist;
		if (rayH->ra < PI && rayH->ra > 0)
			data->texture = data->textures->north;
		else
			data->texture = data->textures->south;
	}
	else
	{
		if (rayV->ra > P2 && rayV->ra < P3)
			data->texture = data->textures->west;
		else
			data->texture = data->textures->east;
		data->dist = rayV->dist;
		data->shade = 0.5;
	}
	data->dist *= cos(ca);
}

double	dist(double ax, double ay, double bx, double by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}
