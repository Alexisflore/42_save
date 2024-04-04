/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:09:36 by alfloren          #+#    #+#             */
/*   Updated: 2024/03/28 18:04:12 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_close(t_fractol *data)
{
	free_fractol(data);
	exit(1);
	return (0);
}

void	put_pxl_to_img(t_fractol *data, int x, int y, int color)
{
	if (data->x < WIDTH && data->y < WIDTH)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4,
			&color, sizeof(int));
	}
}

void	put_text(t_fractol *data)
{
	char	*text;
	char	*nb;

	nb = ft_itoa(data->it_max);
	text = ft_strjoin("iterations : ", nb);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, text);
	free(nb);
	free(text);
}

void	free_fractol(t_fractol *data)
{
	if (data->mlx && data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
	}
	free(data);
}

int mouse_julia(int x, int y, t_fractol *data)
{
    if (data->fract == JULIA && data->julia_mouse == 1)
	{
        data->c_r = x * 2;
        data->c_i = y * 2 - 800;
        calculate_fractal(data, JULIA);
    }
    return (0);
}

void init_fractol_defaults(t_fractol *data, int fractal_type)
{
    data->it_max = DEFAULT_IT_MAX;
    data->zoom = DEFAULT_ZOOM;
    data->color = 265;
	if (fractal_type == JULIA)
    	data->julia_mouse = 1;
	else
		data->julia_mouse = 0;
    data->y_max = 0;
    data->it = 0;
    data->show_text = 0;
    data->endian = 0;
    data->sl = 0;
    data->bpp = 0;
	data->x1 = -2.2;
    data->y1 = -2.5;
	if (data->show_text)
        put_text(data);
	render_fractal_lines(data, fractal_type);
}