/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:00:53 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/14 13:37:42 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	close_window_event(t_data *data)
{
	free_path(data, data->path);
	free_data(data);
	exit(0);
}

int	main(void)
{
	char	*argv[2];
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	argv[1] = "cub/valid.cub";
	data.path = check_args(2, argv, &data);
	mlx_win_init(&data, data.path);
	drawrays_3d(&data);
	mlx_hook(data.win, 17, (1L << 17), close_window_event, &data);
	mlx_hook(data.win, 02, (1L << 0), player_move_with_angle, &data);
	mlx_loop(data.mlx);
	free_path(&data, data.path);
	free_data(&data);
	return (0);
}
