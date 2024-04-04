/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:09:22 by alfloren          #+#    #+#             */
/*   Updated: 2024/03/29 11:07:35 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int key_hook(int keycode, t_fractol *data)
{
	if (keycode == KEY_ESC)
	{
        free_fractol(data);
        exit(1);
    }
	else if (keycode == KEY_PLUS)
		data->it_max += 50;
	else if (keycode == KEY_MINUS)
		data->it_max -= 50;
	else if (keycode == KEY_LEFT)
		data->x1 -= 30 / data->zoom;
	else if (keycode == KEY_RIGHT)
		data->x1 += 30 / data->zoom;
	else if (keycode == KEY_UP)
		data->y1 -= 30 / data->zoom;
	else if (keycode == KEY_DOWN)
		data->y1 += 30 / data->zoom;
	else if (keycode == KEY_SPACE)
		fract_init(data, data->fract);
	else if (keycode == KEY_C)
		data->color = 1677216;
	key_hook2(keycode, data);
	calc_pixel(data);
	return (0);
}


int key_hook2(int keycode, t_fractol *data)
{
	if (keycode == KEY_V)
		data->color = 2050;
	else if (keycode == KEY_B)
		data->color = 265;
	else if (keycode == KEY_J)
		data->julia_mouse = !data->julia_mouse;
	else if (keycode == KEY_T)
		data->show_text = !data->show_text;
    return (0);
}

int mouse_hook(int mousecode, int x, int y, t_fractol *data) {
    if (mousecode == MOUSE_SCROLL_UP || mousecode == MOUSE_LEFT_CLICK)
        ft_zoom(x, y, data);
    else if (mousecode == MOUSE_SCROLL_DOWN || mousecode == MOUSE_RIGHT_CLICK)
        ft_dezoom(x, y, data);
    calc_pixel(data);
    return 0;
}

void ft_zoom(int x, int y, t_fractol *data)
{
    double factor = 1.3;
    data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * factor));
    data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * factor));
    data->zoom *= factor;
    data->it_max++;
}

void ft_dezoom(int x, int y, t_fractol *data)
{
    double factor = 1.3;
    data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom / factor));
    data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / factor));
    data->zoom /= factor;
    data->it_max--;
}