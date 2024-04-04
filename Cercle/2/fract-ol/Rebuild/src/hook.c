/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:09:22 by alfloren          #+#    #+#             */
/*   Updated: 2024/03/28 17:50:39 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void handle_color_keys(int keycode, t_fractol *data)
{
    if (keycode == KEY_V)
        data->color = 2050;
    else if (keycode == KEY_B)
        data->color = 265;
    else if (keycode == KEY_C)
        data->color = 1677216;
}

void handle_iteration_keys(int keycode, t_fractol *data)
{
    if (keycode == KEY_PLUS)
        data->it_max += MAX_ITERATION_STEP;
    else if (keycode == KEY_MINUS)
        data->it_max -= MAX_ITERATION_STEP;
}

void handle_movement_keys(int keycode, t_fractol *data)
{
    double move_factor_x = 30.0 / data->zoom;
    double move_factor_y = 30.0 / data->zoom;

    if (keycode == KEY_LEFT)
        data->x1 -= move_factor_x;
    else if (keycode == KEY_RIGHT)
        data->x1 += move_factor_x;
    else if (keycode == KEY_UP)
        data->y1 -= move_factor_y;
    else if (keycode == KEY_DOWN)
        data->y1 += move_factor_y;
}

void handle_special_keys(int keycode, t_fractol *data)
{
    if (keycode == KEY_SPACE)
        init_fractol_defaults(data, data->fract);
    else if (keycode == KEY_T)
        data->show_text = !data->show_text;
    else if (keycode == KEY_ESC) {
        free_fractol(data);
        exit(1);
    }
}

int key_hook(int keycode, t_fractol *data)
{
    handle_color_keys(keycode, data);
    handle_iteration_keys(keycode, data);
    handle_movement_keys(keycode, data);
    handle_special_keys(keycode, data);
    if (keycode == KEY_J)
        data->julia_mouse = !data->julia_mouse;
    calculate_fractal(data, data->fract);
    return (0);
}