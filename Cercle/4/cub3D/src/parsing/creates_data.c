/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creates_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:21:12 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/12 19:29:44 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void create_map_array(t_path *path)
{
    int i;
    t_map *tmp;

    i = 0;
    path->mapX = max_size(path, path->map);
    path->mapY = size_x(path->map);
    path->map_array = malloc(sizeof(int *) * ( path->mapY + 1));
    if (path->map_array == NULL)
        error_path(path, "Error\nMalloc map_array\n");
    tmp = path->map;
    while (i < path->mapY)
    {
        create_x_array(path, i, tmp);
        tmp = tmp->next;
        i++;
    }
    free_map(&path->map);
    path->map = NULL;
}

void create_x_array(t_path *path, int i, t_map *tmp)
{
    int j;

    j = 0;
    path->map_array[i] = malloc(sizeof(int) * (path->mapX) + 1);
    if (path->map_array[i] == NULL)
        error_path(path, "Error\nMalloc map_array\n");
    while (j < tmp->size)
    {
        path->map_array[i][j] = tmp->line[j];
        j++;
    }
    while (j < path->mapX)
    {
        path->map_array[i][j] = -1;
        j++;
    }
    path->map_array[i][j] = '\0';
}

void create_map(t_path *path)
{
    t_map *new;
    int i;

    new = malloc(sizeof(t_map));
    if (new == NULL)
        error_path(path, "Error\nMalloc map\n");
    init_tmap(new, path);
    i = 0;
    if (path->line[new->size - 1] == '\n')
    {
        path->line[new->size - 1] = '\0';
        new->size--;
    }
    while (path->line[i] != '\0')
    {
        new->line[i] = int_line(&path, i);
        i++;
    }
    new->line[i] = '\0';
    t_map_add_back(&(path->map), new);
    free(path->line);
    path->line = NULL;
}

void create_rgb(t_path *path, t_rgb **rgb)
{
    if (*rgb != NULL)
        error_path(path, "Error\nDuplicate floor\n");
    *rgb = malloc(sizeof(t_rgb));
    if (*rgb == NULL)
        error_path(path, "Error\nMalloc floor\n");
    fill_rgb(path, rgb);
}

void create_final_map(t_path *path)
{
    int x;
    int y;

    while (y < path->mapY)
    {
        x = 0;
        while (x < path->mapX)
        {
            if (path->map_array[y][x] == -1)
                path->map_array[y][x] = 1;
            x++;
        }
        y++;
    }
}