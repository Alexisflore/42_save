/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:47:54 by ladloff           #+#    #+#             */
/*   Updated: 2024/04/15 16:59:07 by ladloff          ###   ########.fr       */
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
