/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:00:53 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/15 16:43:45 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	close_window_event(t_data *data)
{
	free_path(data, data->path);
	cleanup_mlx(&data->mlx);
	exit(0);
}

void	exit_error(char *message, t_data *data)
{
	ft_putstr_fd(message, 2);
	free_path(data, data->path);
	cleanup_mlx(&data->mlx);
	exit(1);
}

static int	find_horizon(t_path *path)
{
	if (path->mapx < path->mapy)
		return (path->mapy);
	return (path->mapx);
}

void	init_values(t_data *data, t_path *path)
{
	data->mapx = path->mapx;
	data->mapy = path->mapy;
	data->horizon = find_horizon(path);
	data->map = path->map_array;
	data->px = path->player_x;
	data->py = path->player_y;
	data->pdx = 0;
	data->pdy = -10;
	data->pa = path->player_angle;
	data->textures = path->textures;
	data->ceiling = path->ceiling;
	data->floor = path->floor;
	data->path = path;
}

t_mlx	setup_mlx(char *title)
{
	t_mlx	mlx;

	ft_memset(&mlx, 0, sizeof(t_mlx));
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		exit (2);
	mlx.win = mlx_new_window(mlx.mlx, 1200, 640, ft_strchr(title, '/') + 1);
	if (!mlx.win)
		exit(3);
	mlx.img = mlx_new_image(mlx.mlx, 1200, 640);
	if (!mlx.img)
		exit(4);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_line,
		&mlx.endian);
	if (!mlx.addr)
		exit(5);
	return (mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (EXIT_FAILURE);
	ft_memset(&data, 0, sizeof(t_data));
	data.mlx = setup_mlx(argv[0]);
	data.path = check_args(2, argv, &data);
	init_values(&data, data.path);
	drawrays_3d(&data);
	mlx_hook(data.mlx.win, 17, (1L << 17), close_window_event, &data);
	mlx_hook(data.mlx.win, 02, (1L << 0), player_move_with_angle, &data);
	mlx_loop(data.mlx.mlx);
	free_path(&data, data.path);
	cleanup_mlx(&data.mlx);
	return (EXIT_SUCCESS);
}
