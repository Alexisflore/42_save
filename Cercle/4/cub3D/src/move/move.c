/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:11:35 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/14 13:08:44 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_collision(t_collision *col)
{
	col->xo = 0;
	col->yo = 0;
	col->ipx = 0;
	col->ipy = 0;
	col->ipx_add_xo = 0;
	col->ipx_sub_xo = 0;
	col->ipy_add_yo = 0;
	col->ipy_sub_yo = 0;
}

void	colision(t_data *data, t_collision *col)
{
	init_collision(col);
	if (data->pdx < 0)
		col->xo = -20;
	else
		col->xo = 20;
	if (data->pdy < 0)
		col->yo = -20;
	else
		col->yo = 20;
	if (data->pdx < 0)
		col->xo = -20;
	else
		col->xo = 20;
	col->ipx = data->px / 64.0;
	col->ipx_add_xo = (data->px + col->xo) / 64.0;
	col->ipx_sub_xo = (data->px - col->xo) / 64.0;
	col->ipy = data->py / 64.0;
	col->ipy_add_yo = (data->py + col->yo) / 64.0;
	col->ipy_sub_yo = (data->py - col->yo) / 64.0;
}
