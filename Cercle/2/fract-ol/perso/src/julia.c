/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:09:25 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/19 18:47:02 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_julia(int x, int y, t_fractol *data)
{
	if (data->fract == 1 && data->julia_mouse == 1)
	{
		data->c_r = x * 2;
		data->c_i = y * 2 - 800;
		fract_calc(data);
	}
	return (0);
}

void	julia_init(t_fractol *data)
{
	data->it_max = 50;
	data->zoom = 200;
	data->x1 = -2.0;
	data->y1 = -1.9;
	data->color = 265;
	data->c_r = -74.5429;
	data->c_i = 5;
	data->julia_mouse = 1;
	data->x = 0;
	data->y = 0;
	data->y_max = 0;
	data->it = 0;
	data->show_text = 0;
	data->endian = 0;
	data->sl = 0;
	data->bpp = 0;
	data->tmp = 0.0;
}

void	julia_calc(t_fractol *data)
{
	data->z_r = data->x / data->zoom + data->x1;
	data->z_i = data->y / data->zoom + data->y1;
	data->it = 0;
	while (data->z_r * data->z_r + data->z_i
		* data->z_i < 4 && data->it < data->it_max)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r
			- data->z_i * data->z_i - 0.8 + (data->c_r / WIDTH);
		data->z_i = 2 * data->z_i * data->tmp + data->c_i / WIDTH;
		data->it++;
	}
	if (data->it == data->it_max)
		put_pxl_to_img(data, data->x, data->y, 0x000000);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}

void	*julia(void *tab)
{
	int			tmp;
	t_fractol	*data;

	data = (t_fractol *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			julia_calc(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	julia_line(t_fractol *data)
{
	t_fractol	tab[MAX_NUMBER];
	int			i;

	i = 0;
	while (i < MAX_NUMBER)
	{
		ft_memcpy((void *)&tab[i], (void *)data, sizeof(t_fractol));
		tab[i].y = N_WIDTH * i;
		tab[i].y_max = N_WIDTH * (i + 1);
		julia(&tab[i]);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
