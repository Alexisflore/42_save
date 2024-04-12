/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:10:07 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/12 18:05:51 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    free_texture(t_xpm *data)
{
    free(data->addr);
    free(data->texture);
    free(data->img);
    free(data);
}
void    free_data(t_data *data)
{
    free(data->mlx);
    free(data->win);
    free(data->img);
    free(data->img_ptr);
    free_texture(data->textures->west);
    free_texture(data->textures->east);
    free_texture(data->textures->north);
    free_texture(data->textures->south);
    free(data->textures);
    free(data->map);
    free(data);
}

void    free_intarray(int **array)
{
    int i;

    i = 0;
    if (array == NULL)
        return;
    while (array[i] != NULL)
    {
        free(array[i]);
        i++;
    }
    free(array);
}

void free_char_array(char **array)
{
    int i;

    i = 0;
    if (array == NULL)
        return;
    while (array[i] != NULL)
    {
        free(array[i]);
        i++;
    }
    free(array);
}

void free_map(t_map **map)
{
    t_map *tmp;
    
    while (*map != NULL)
    {
        tmp = *map;
        *map = (*map)->next;
        free(tmp->line);
        free(tmp);
    }
    free(*map);
}
