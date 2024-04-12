/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:12:31 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/12 19:16:17 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

void check_first_texture(t_xpm **texture, t_path *path)
{
    if (*texture != NULL)
        error_path(path, "Error\nDuplicate texture\n");
    *texture = malloc(sizeof(t_xpm));
    if (*texture == NULL)
        error_path(path, "Error\nMalloc texture\n");
    init_img_xpm(texture, path, path->split[1]);
}

void check_texture(t_path *path)
{
    // is_right_xpm_file(path, path->split[1]);
    if (ft_strcmp(path->split[0], "SO") == 0)
        check_first_texture(&path->textures->south, path);
    else if (ft_strcmp(path->split[0], "WE") == 0)
        check_first_texture(&path->textures->west, path);
    else if (ft_strcmp(path->split[0], "EA") == 0)
        check_first_texture(&path->textures->east, path);
    else if (ft_strcmp(path->split[0], "NO") == 0)
        check_first_texture(&path->textures->north, path);
}

void check_nbr(char *str, t_path *path, int *rgb)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(str);
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
    if (ft_strlen(str) > 3)
        error_path(path, "Error\nInvalid RGB value\n");
    while (str[i] != '\0')
    {
        if (ft_isdigit(str[i]) == 0)
            error_path(path, "Error\nInvalid RGB value\n");
        i++;
    }
    *rgb = ft_atoi(str);
    if (*rgb < 0 || *rgb > 255)
        error_path(path, "Error\nInvalid RGB value\n");
}

void check_rgb(t_path *path)
{
    path->rgb = ft_split(path->split[1], ',');
    if (path->rgb == NULL)
        error_path(path, "Error\nMalloc RGB\n");
    if (ft_strcmp(path->split[0], "F") == 0)
        create_rgb(path, &path->floor);
    else if (ft_strcmp(path->split[0], "C") == 0)
        create_rgb(path, &path->ceiling);
    free_char_array(path->rgb);
    path->rgb = NULL;
}

void check_wall_around(t_path *path, int i, int j)
{
    if (path->map_array[i][j] == 0 || path->map_array[i][j] == 2)
        test4wall(path, i, j);
}
