/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:00:53 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/13 17:29:51 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(void)
{
	char	*argv[] = {"./cub3D", "cub/valid.cub"};
	t_path	*path;
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
	{
		perror("Error\nMalloc data\n");
		exit(1);
	}
	path = check_args(2, argv);
	mlx_win_init(data, path);
	drawrays_3d(data);
	mlx_hook(data->win, 02, (1L << 0), player_move_with_angle, data);
	mlx_loop(data->mlx);
	free_path(&path);
	free_data(&data);
	return (0);
}
