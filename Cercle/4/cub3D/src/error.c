/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:47:54 by ladloff           #+#    #+#             */
/*   Updated: 2024/04/15 17:32:21 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_error(char *message, t_data *data)
{
	ft_putstr_fd(message, 2);
	free_path(data, &data->path);
	cleanup_mlx(&data->mlx);
	exit(1);
}

void	error_path(t_data *data, t_path *path, char *message)
{
	ft_putstr_fd(message, 2);
	free_path(data, path);
	cleanup_mlx(&data->mlx);
	exit(1);
}

void	error_check(t_path *path, char *message)
{
	ft_putstr_fd(message, 2);
	free(path);
	exit(1);
}
