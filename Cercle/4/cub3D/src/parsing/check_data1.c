/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:16:58 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/12 19:24:22 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    check_textures_and_rgb(t_path *path)
{
    path->split = ft_split(path->line, ' ');
    if (path->split == NULL)
        error_path(path, "Error\nMalloc split\n");
    if (is_texture(path->split[0]) == 1)
        check_texture(path);
    else if (is_rgb(path->split[0]) == 1)
        check_rgb(path);
    free_char_array(path->split);
    path->split = NULL;
}

void   check_map(t_path *path)
{
    create_map_array(path);
    verify_closed_map(path);
}

void test4wall(t_path *path, int i, int j)
{
    if (i == 0 || i == path->mapY - 1 || j == 0 || j == path->mapX - 1)
        error_path(path, "Error\nMap not closed\n");
    if (path->map_array[i - 1][j] == -1
    || path->map_array[i + 1][j] == -1
    || path->map_array[i][j - 1] == -1
    || path->map_array[i][j + 1] == -1)
    error_path(path, "Error\nMap not closed\n");
}

void verify_closed_map(t_path *path)
{
    int i;
    int j;

    i = 0;
    while (i < path->mapY)
    {
        j = 0;
        while (j < path->mapX)
        {
            check_wall_around(path, i, j);
            j++;
        }
        i++;
    }
}