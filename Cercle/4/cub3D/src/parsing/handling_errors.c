/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:55:00 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/13 09:16:19 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void free_path(t_path **path)
{
    free((*path)->textures->west);
    free((*path)->textures->east);
    free((*path)->textures->north);
    free((*path)->textures->south);
    free((*path)->textures);
    (*path)->textures = NULL;
    free((*path)->floor);
    (*path)->floor = NULL;
    free((*path)->ceiling);
     (*path)->ceiling = NULL;
    free_char_array((*path)->split);
    (*path)->split = NULL;
    free_char_array((*path)->rgb);
    (*path)->rgb = NULL;
    free_map(&(*path)->map);
    (*path)->map = NULL;
    free_intarray((*path)->map_array);
     (*path)->map_array = NULL;
    free((*path));
    *path = NULL;
}

void error_path(t_path *path, char *message)
{
    perror(message);
    free_path(&path);
    exit(1);
}

void error_check(t_path *path, char *message)
{
    perror(message);
    free(path);
    exit(1);
}