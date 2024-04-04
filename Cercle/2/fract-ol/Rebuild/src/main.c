/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:09:29 by alfloren          #+#    #+#             */
/*   Updated: 2024/03/28 18:03:30 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <signal.h>

void mlx_win_init(t_fractol *data)
{
    data->win = mlx_new_window(data->mlx, WIDTH, WIDTH, "Fractol");
    data->img = mlx_new_image(data->mlx, WIDTH, WIDTH);
    data->img_ptr = mlx_get_data_addr(data->img, &data->bpp, &data->sl, &data->endian);
}

int fract_comp(char **av, t_fractol *data)
{
    if (ft_strcmp(av[1], "mandelbrot") == 0)
        data->fract = MANDELBROT;
    else if (ft_strcmp(av[1], "julia") == 0)
        data->fract = JULIA;
    else if (ft_strcmp(av[1], "burningship") == 0)
        data->fract = BURNINGSHIP;
    else
    {
        ft_putendl_fd("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"", 1);
        return (0);
    }
    return (1);
}

int main(int ac, char **av)
{
    t_fractol *data;

    if (ac == 2)
	{
        data = (t_fractol *)malloc(sizeof(t_fractol));
        if (!data)
            return (-1);
        data->mlx = mlx_init();
        mlx_win_init(data);
        if ((fract_comp(av, data)) == 0)
            return (free_fractol(data), 0);
        init_fractol_defaults(data, data->fract);
        mlx_hook(data->win, 17, 0, ft_close, data);
        mlx_hook(data->win, 6, 1L << 6, mouse_julia, data);
        mlx_key_hook(data->win, key_hook, data);
        mlx_mouse_hook(data->win, key_hook, data);
        mlx_loop(data->mlx);
        mlx_destroy_image(data->mlx, data->img);
        free(data->mlx);
    }
	else
        ft_putendl_fd("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"", 1);
    return (0);
}
