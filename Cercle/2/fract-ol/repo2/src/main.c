/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:09:29 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/19 18:58:29 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <signal.h>

void	fract_calc(t_fractol *data)
{
	if (data->it_max < 0)
		data->it_max = 0;
	if (data->fract == 3)
		mandelbrot_line(data);
	else if (data->fract == 1)
		julia_line(data);
	else if (data->fract == 2)
		burningship_line(data);
	if (data->show_text)
		put_text(data);
}

void	fract_init(t_fractol *data)
{
	if (data->fract == 3)
		mandelbrot_init(data);
	else if (data->fract == 1)
		julia_init(data);
	else if (data->fract == 2)
		burningship_init(data);
	fract_calc(data);
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
		data->fract = 3;
	else if (ft_strcmp(av[1], "julia") == 0)
		data->fract = 1;
	else if (ft_strcmp(av[1], "burningship") == 0)
		data->fract = 2;
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
		fract_init(data);
		mlx_hook(data->win, 17, 0, ft_close, data);
		mlx_hook(data->win, 6, 1L << 6, mouse_julia, data);
		mlx_key_hook(data->win, key_hook, data);
		mlx_mouse_hook(data->win, mouse_hook, data);
		mlx_loop(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	else
		ft_putendl_fd("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"", 1);
	return (0);
}
