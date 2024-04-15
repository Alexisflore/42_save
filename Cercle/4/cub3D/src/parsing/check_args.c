/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:46 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/15 16:57:37 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	final_check(t_data *data, t_path *path)
{
	if (is_all_textures(path) == 0)
		error_path(data, path, "Error\nMissing texture\n");
	if (path->player_orientation == 0)
		error_path(data, path, "Error\nMissing player orientation\n");
	check_map(data, path);
	create_final_map(path);
}

void	check_data(int fd, t_data *data, t_path *path)
{
	path->line = get_next_line(fd, false);
	while (path->line != NULL && is_all_textures(path) == 0)
	{
		if (is_all_spaces_or_newline(path) == 1)
		{
			next_data(path, fd);
			continue ;
		}
		check_textures_and_rgb(data, path);
		next_data(path, fd);
	}
	while (path->line != NULL && is_all_spaces_or_newline(path) == 1)
		next_data(path, fd);
	while (path->line != NULL && is_all_textures(path) == 1)
	{
		create_map(data, path);
		next_data(path, fd);
	}
	final_check(data, path);
	close(fd);
}

t_path	check_args(char **argv, t_data *data)
{
	int		fd;
	t_path	path;

	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
		error_check(&path, "Error\nInvalid file extension\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_check(&path, "Error\nFile not found\n");
	init_path(data, &path);
	check_data(fd, data, &path);
	return (path);
}
