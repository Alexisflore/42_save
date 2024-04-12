/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:46 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/12 19:05:30 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void t_map_add_back(t_map **alst, t_map *new)
{
    t_map **tmp;

    if (*alst == NULL)
    {
        *alst = new;
        return;
    }
    tmp = alst;
    while ((*tmp)->next != NULL)
        tmp = &(*tmp)->next;
    (*tmp)->next = new;
}

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

// void init_path(t_path *path)
// {
//     path->mlx = mlx_init();
//     path->i = 0;
//     path->player_orientation = 0;
//     path->floor = NULL;
//     path->ceiling = NULL;
//     path->map = NULL;
//     path->textures = malloc(sizeof(t_texture));
//     if (path->textures == NULL)
//         error_path(path, "Error\nMalloc textures\n");
//     path->textures->west = NULL;
//     path->textures->east = NULL;
//     path->textures->north = NULL;
//     path->textures->south = NULL;
//     path->map_array = NULL;
//     path->split = NULL;
//     path->rgb = NULL;
// }

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

void    fill_rgb(t_path *path, t_rgb **rgb)
{
    check_nbr(path->rgb[0], path, &(*rgb)->r);
    check_nbr(path->rgb[1], path, &(*rgb)->g);
    check_nbr(path->rgb[2], path, &(*rgb)->b);
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

void    init_tmap(t_map *new, t_path *path)
{
    new->next = NULL;
    new->size = ft_strlen(path->line);
    new->line = malloc(sizeof(int) * (new->size + 1));
    if (new->line == NULL)
        error_path(path, "Error\nMalloc map\n");
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

int size_x(t_map *map)
{
    int size;
    t_map *tmp;

    tmp = map;
    size = 0;
    while (tmp != NULL)
    {
        size++;
        tmp = tmp->next;
    }
    return (size);
}

int max_size(t_path *path, t_map *map)
{
    int max;
    t_map *tmp;

    if (map == NULL)
        error_path(path, "Error\nEmpty map\n");
    tmp = map;
    max = 0;
    while (tmp->next != NULL)
    {
        if (tmp->size > max)
            max = tmp->size;
        tmp = tmp->next;
    }
    return (max);
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

void check_wall_around(t_path *path, int i, int j)
{
    if (path->map_array[i][j] == 0 || path->map_array[i][j] == 2)
        test4wall(path, i, j);
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

void   check_map(t_path *path)
{
    create_map_array(path);
    verify_closed_map(path);
}

void    final_check(t_path *path)
{
    if (is_all_textures(path) == 0)
        error_path(path, "Error\nMissing texture\n");
    if (path->player_orientation == 0)
        error_path(path, "Error\nMissing player orientation\n");
    check_map(path);
}

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

void next_data(t_path *path, int fd)
{
    free(path->line);
    path->line = get_next_line(fd);
}

void check_data(int fd, t_path *path)
{
    path->line = get_next_line(fd);
    while (path->line != NULL && is_all_textures(path) == 0)
    {
        if (is_all_spaces_or_newline(path) == 1)
        {
            next_data(path, fd);
            continue;
        }
        check_textures_and_rgb(path);
        next_data(path, fd);
    }
    while (path->line != NULL && is_all_spaces_or_newline(path) == 1)
        next_data(path, fd);
    while (path->line != NULL && is_all_textures(path) == 1)
    {
        create_map(path);
        next_data(path, fd);
    }
    final_check(path);
    close(fd);
}

t_path *check_args(int argc, char **argv)
{
    int fd;
    t_path *path;

    path = malloc(sizeof(t_path));
    if (path == NULL)
        error_check(path, "Error\nMalloc path\n");
    if (argc != 2)
        error_check(path, "Error\nInvalid number of arguments\n");
    if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
        error_check(path, "Error\nInvalid file extension\n");
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        error_check(path, "Error\nFile not found\n");
    init_path(path);
    check_data(fd, path);
    return (path);
}

