/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:41:40 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/13 10:53:57 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_path(t_path *path)
{
    path->mlx = mlx_init();
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

void init_img_xpm(t_xpm **texture, t_path *path, char *file)
{
    (*texture)->img = mlx_xpm_file_to_image(path->mlx, file,
        &(*texture)->width, &(*texture)->height);
    if ((*texture)->img == NULL)
        error_path(path, "Error\nInvalid (*texture)\n");
    (*texture)->addr = mlx_get_data_addr((*texture)->img, &(*texture)->bpp,
        &(*texture)->size_line, &(*texture)->endian);
    (*texture)->texture = (int *)mlx_get_data_addr((*texture)->img, &(*texture)->bpp,
        &(*texture)->size_line, &(*texture)->endian);
}

int int_line(t_path **path, int i)
{
    if ((*path)->line[i] == '1' || (*path)->line[i] == '0')
        return((*path)->line[i] - '0');
    else if (is_a_direction((*path)->line[i]))
    {
        (*path)->player_orientation = (*path)->line[i];
        return (2);
    }
    else if ((*path)->line[i] == ' ' || (*path)->line[i] == '\t')
        return (-1);
    else
    {
        error_path(*path, "Error\nInvalid map\n");
        return (-1);
    }
}

void    init_tmap(t_map *new, t_path *path)
{
    new->next = NULL;
    new->size = ft_strlen(path->line);
    new->line = malloc(sizeof(int) * (new->size + 1));
    if (new->line == NULL)
        error_path(path, "Error\nMalloc map\n");
}