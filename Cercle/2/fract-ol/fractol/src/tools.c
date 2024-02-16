/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:09:36 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/13 19:16:51 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	ft_putstr_fd(text, 1);
	ft_putstr_fd(nb, 1);
	free(nb);
	free(text);
}

void	free_fractol(t_fractol *data)
{
	if (data->mlx && data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	// else if (data->mlx && data->img && data->fract == 3)
	// {
	// 	mlx_destroy_image(data->mlx, data->img);
	// 	mlx_destroy_window(data->mlx, data->win);
	// 	mlx_destroy_display(data->mlx);
	// 	free(data->mlx);
	// }
	free(data);
}
