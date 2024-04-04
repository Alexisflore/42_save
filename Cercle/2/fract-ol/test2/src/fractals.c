/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:26:18 by macbookpro        #+#    #+#             */
/*   Updated: 2024/03/29 15:16:22 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void fractal_calc(t_fractol *data) {
	if (data->fract == MANDELBROT_FRACT) 
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r
			- data->z_i * data->z_i + data->c_r;
		data->z_i = 2 * data->z_i * data->tmp + data->c_i;
	}
	else if (data->fract == JULIA_FRACT)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r
			- data->z_i * data->z_i - 0.8 + (data->c_r / WIDTH);
		data->z_i = 2 * data->z_i * data->tmp + data->c_i / WIDTH;
	}
	else if (data->fract == BURNINGSHIP_FRACT)
	{
		data->tmp = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i = fabs(2 * data->z_r * data->z_i) + data->c_i;
		data->z_r = data->tmp;
	}
}

void init_calc(t_fractol *data)
{
	if (data->fract == MANDELBROT_FRACT || data->fract == BURNINGSHIP_FRACT)
	{
		data->c_r = data->x / data->zoom + data->x1;
		data->c_i = data->y / data->zoom + data->y1;
		data->z_r = 0;
		data->z_i = 0;
	}
	else if (data->fract == JULIA_FRACT)
	{
		data->z_r = data->x / data->zoom + data->x1;
		data->z_i = data->y / data->zoom + data->y1;
	}
	data->it = 0;
}

void calc_iteration(t_fractol *data)
{
    init_calc(data);
    while (data->z_r * data->z_r + data->z_i * data->z_i < 4 && data->it < data->it_max)
    {
        fractal_calc(data);
        data->it++;
    }
    if (data->it == data->it_max)
        put_pxl_to_img(data, data->x, data->y, 0x000000);
    else
        put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}

void	calc_pixel(t_fractol *data)
{
	if (data->it_max < 0)
		data->it_max = 0;
    data->y = 0;
    while (data->y < HEIGHT)
    {
        data->x = 0;
        while (data->x < WIDTH)
        {
			calc_iteration(data);
            data->x++;
        }
        data->y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	if (data->show_text)
		put_text(data);
}