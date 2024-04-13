/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:00:53 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/13 18:29:51 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window_event(t_data *data)
{
	free_path(&data->path);
	free_data(&data);
	exit(0);
}

int	main(void)
{
	char	*argv[2];
	t_path	*path;
	t_data	*data;

	argv[1] = "cub/valid.cub";
	data = malloc(sizeof(t_data));
	if (data == NULL)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		exit(1);
	}
	path = check_args(2, argv);
	mlx_win_init(data, path);
	drawrays_3d(data);
	mlx_hook(data->win, 02, (1L << 0), player_move_with_angle, data);
	mlx_hook(data->win, 17, (1L << 17),
		close_window_event, data->mlx);
	mlx_loop(data->mlx);
	free_path(&path);
	free_data(&data);
	return (0);
}
