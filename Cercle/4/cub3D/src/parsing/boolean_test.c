/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolean_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:09:38 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/12 19:11:33 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int is_all_textures(t_path *path)
{
    if (path->textures->west != NULL
    && path->textures->east != NULL
    && path->textures->north != NULL
    && path->textures->south != NULL
    && path->floor != NULL
    && path->ceiling != NULL)
        return (1);
    return (0);
}

int is_a_direction(char c)
{
    if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
        return (1);
    return (0);
}

int is_all_spaces_or_newline(t_path *path)
{
    int i;

    i = 0;
    while (path->line[i] != '\0')
    {
        if (path->line[i] != ' '
            && path->line[i] != '\t'
            && path->line[i] != '\n')
            return (0);
        i++;
    }
    return (1);
}

int    is_texture(char *str)
{
    if (ft_strcmp(str, "NO") == 0
        || ft_strcmp(str, "SO") == 0
        || ft_strcmp(str, "WE") == 0
        || ft_strcmp(str, "EA") == 0)
        return (1);
    return (0);
}

int is_rgb(char *str)
{
    if (ft_strcmp(str, "F") == 0
        || ft_strcmp(str, "C") == 0)
        return (1);
    return (0);
}