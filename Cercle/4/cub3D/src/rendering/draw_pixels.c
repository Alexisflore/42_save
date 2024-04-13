/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:27:35 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/13 17:27:53 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	pixel_drawing(t_data *data, t_pixel pix)
{
	int	i;
	int	j;

	i = 0;
	while (i < pix.size)
	{
		j = 0;
		while (j < pix.size)
		{
			put_pxl_to_img(data, pix.x + i, pix.y + j, pix.color);
			j++;
		}
		i++;
	}
}

t_pixel	pixel(int x, int y, int size, int color)
{
	t_pixel	pix;

	pix.size = size;
	pix.x = x;
	pix.y = y;
	pix.color = color;
	return (pix);
}
