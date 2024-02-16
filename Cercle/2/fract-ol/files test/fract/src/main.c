/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:39:21 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/08 13:09:11 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// mlx_init() to init connection
// -lmlx -lXext -lX11 to link other librauries
int	draw_fractal(t_fractol *fractal, char *query, double cx, double cy)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			if (ft_strncmp(query, "mandel", 7) == 0)
				calculate_mandelbrot(fractal);
			else if (ft_strncmp(query, "julia", 6) == 0)
				calculate_julia(fractal, cx, cy);
			else if (ft_strncmp(query, "ship", 5) == 0)
				calculate_burning_ship(fractal);
			else
			{
				ft_putendl_fd("Available fractals: mandel, julia, ship", 1);
				exit_fractal(fractal);
			}
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image,
		0, 0);
	return (0);
}
