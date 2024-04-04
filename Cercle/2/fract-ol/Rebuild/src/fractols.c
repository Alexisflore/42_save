/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:34:02 by macbookpro        #+#    #+#             */
/*   Updated: 2024/03/28 18:14:27 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void calculate_fractal(t_fractol *data, int fractal_type)
{
    if (fractal_type == MANDELBROT)
        calculate_mandelbrot(data);
    else if (fractal_type == JULIA)
        calculate_julia(data);
    else if (fractal_type == BURNINGSHIP)
        calculate_burningship(data);
}

void calculate_mandelbrot(t_fractol *data)
{
    data->c_r = data->x / data->zoom + data->x1;
    data->c_i = data->y / data->zoom + data->y1;
    data->z_r = 0;
    data->z_i = 0;
    data->it = 0;
    while (data->z_r * data->z_r + data->z_i * data->z_i < 4 && data->it < data->it_max)
    {
        data->tmp = data->z_r;
        data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
        data->z_i = 2 * data->z_i * data->tmp + data->c_i;
        data->it++;
    }
    if (data->it == data->it_max)
        data->color = 0x000000;
    else
        data->color = data->color * data->it;
}

void calculate_julia(t_fractol *data)
{
    data->z_r = data->x / data->zoom + data->x1;
    data->z_i = data->y / data->zoom + data->y1;
    data->it = 0;
    while (data->z_r * data->z_r + data->z_i * data->z_i < 4 && data->it < data->it_max)
    {
        data->tmp = data->z_r;
        data->z_r = data->z_r * data->z_r - data->z_i * data->z_i - 0.8 + (data->c_r / WIDTH);
        data->z_i = 2 * data->z_i * data->tmp + data->c_i / WIDTH;
        data->it++;
    }
    if (data->it == data->it_max)
        data->color = 0x000000;
    else
        data->color = data->color * data->it;
}

void calculate_burningship(t_fractol *data)
{
    data->c_r = data->x / data->zoom + data->x1;
    data->c_i = data->y / data->zoom + data->y1;
    data->z_r = 0;
    data->z_i = 0;
    data->it = 0;
    while (data->z_r * data->z_r + data->z_i * data->z_i < 4 && data->it < data->it_max)
    {
        data->tmp = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
        data->z_i = fabs(2 * data->z_r * data->z_i) + data->c_i;
        data->z_r = data->tmp;
        data->it++;
    }
    if (data->it == data->it_max)
        data->color = 0x000000;
    else
        data->color = data->color * data->it;
}

void render_fractal_lines(t_fractol *data, int fractal_type)
{
    int i = 0;
    while (i < MAX_NUMBER)
    {
        data->y = N_WIDTH * i;
        data->y_max = N_WIDTH * (i + 1);
        int x = 0;
        while (x < WIDTH)
        {
            data->x = x;
            calculate_fractal(data, fractal_type);
            x++;
        }
        i++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
