/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:41:40 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/12 17:43:46 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_path(t_path *path)
{
    path->mlx = mlx_init();
    path->i = 0;
    path->player_orientation = 0;
    path->floor = NULL;
    path->ceiling = NULL;
    path->map = NULL;
    path->textures = malloc(sizeof(t_texture));
    if (path->textures == NULL)
        error_path(path, "Error\nMalloc textures\n");
    path->textures->west = NULL;
    path->textures->east = NULL;
    path->textures->north = NULL;
    path->textures->south = NULL;
    path->map_array = NULL;
    path->split = NULL;
    path->rgb = NULL;
}