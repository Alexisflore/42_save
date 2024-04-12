/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:55:00 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/12 18:09:16 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void error_path(t_path *path, char *message)
{
    perror(message);
    free(path->textures->west);
    free(path->textures->east);
    free(path->textures->north);
    free(path->textures->south);
    free(path->textures);
    free(path->floor);
    free(path->ceiling);
    free_char_array(path->split);
    free_char_array(path->rgb);
    free_map(&path->map);
    free_intarray(path->map_array);
    free(path);
    exit(1);
}

void error_check(t_path *path, char *message)
{
    perror(message);
    free(path);
    exit(1);
}