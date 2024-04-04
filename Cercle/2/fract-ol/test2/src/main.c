/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:09:29 by alfloren          #+#    #+#             */
/*   Updated: 2024/03/29 15:07:05 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <signal.h>

void init_xy(t_fractol *data, int fractal_type)
{
	if (fractal_type == MANDELBROT_FRACT)
    {
        data->x1 = -2.05;
        data->y1 = -1.3;
    }
    else if (fractal_type == JULIA_FRACT)
    {
        data->x1 = -2.0;
        data->y1 = -1.9;
        data->c_r = -74.5429;
        data->c_i = 5;
    }
    else if (fractal_type == BURNINGSHIP_FRACT)
    {
        data->x1 = -2.2;
        data->y1 = -2.5;
    }
	calc_pixel(data);
}

void	fract_init(t_fractol *data, int fractal_type)
{
    data->it_max = 50;
	if (fractal_type == MANDELBROT_FRACT)
    	data->zoom = 300;
	else
		data->zoom = 200;
    data->color = 265;
	if (fractal_type == JULIA_FRACT)
		data->julia_mouse = 1;
	else 
		data->julia_mouse = 0;
    data->y_max = 0;
    data->it = 0;
    data->show_text = 0;
    data->endian = 0;
    data->sl = 0;
    data->bpp = 0;
	init_xy(data, fractal_type);
}

void	mlx_win_init(t_fractol *data)
{
	data->win = mlx_new_window(data->mlx, WIDTH, WIDTH, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, WIDTH);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bpp, &data->sl, &data->endian);
}

int	fract_comp(char **av, t_fractol *data)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		data->fract = MANDELBROT_FRACT;
	else if (ft_strcmp(av[1], "julia") == 0)
		data->fract = JULIA_FRACT;
	else if (ft_strcmp(av[1], "burningship") == 0)
		data->fract = BURNINGSHIP_FRACT;
	else
	{
		ft_putendl_fd("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"", 1);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fractol	*data;

	if (ac == 2)
	{
		data = (t_fractol *)malloc(sizeof(t_fractol));
		if (!data)
			return (-1);
		data->mlx = mlx_init();
		mlx_win_init(data);
		if ((fract_comp(av, data)) == 0)
			return (free_fractol(data), 0);
		fract_init(data, data->fract);
		mlx_hook(data->win, 17, 0, ft_close, data);
		mlx_hook(data->win, 6, 1L << 6, mouse_julia, data);
		mlx_key_hook(data->win, key_hook, data);
		mlx_mouse_hook(data->win, mouse_hook, data);
		mlx_loop(data->mlx);
		mlx_destroy_image(data->mlx, data->img);
		free(data->mlx);
	}
	else
		ft_putendl_fd("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"", 1);
	return (0);
}
