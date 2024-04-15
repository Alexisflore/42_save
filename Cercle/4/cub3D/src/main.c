/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:00:53 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/15 16:58:52 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	close_window_event(t_data *data)
{
	free_path(data, &data->path);
	cleanup_mlx(&data->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (EXIT_FAILURE);
	ft_memset(&data, 0, sizeof(t_data));
	data.mlx = setup_mlx(argv[0]);
	data.path = check_args(argv, &data);
	init_values(&data, &data.path);
	drawrays_3d(&data);
	mlx_hook(data.mlx.win, 17, (1L << 17), close_window_event, &data);
	mlx_hook(data.mlx.win, 02, (1L << 0), player_move_with_angle, &data);
	mlx_loop(data.mlx.mlx);
	free_path(&data, &data.path);
	cleanup_mlx(&data.mlx);
	return (EXIT_SUCCESS);
}
