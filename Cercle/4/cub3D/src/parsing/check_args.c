/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:46 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/12 10:23:05 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void t_map_add_back(t_map **alst, t_map *new)
{
    t_map *tmp;

    if (*alst == NULL)
    {
        *alst = new;
        return;
    }
    tmp = *alst;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}

int nbr_of_texture(t_path *path)
{
    if (path->so == NULL
        || path->we == NULL
        || path->ea == NULL
        || path->no == NULL
        || path->floor == NULL
        || path->ceiling == NULL)
        return (1);
    return (0);
}
void    free_intarray(int **array)
{
    int i;

    i = 0;
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
    while (array[i] != NULL)
    {
        free(array[i]);
        i++;
    }
    free(array);
}

void error_path(t_path *path, char *message)
{
    perror(message);
    free(path->so);
    free(path->we);
    free(path->ea);
    free(path->no);
    free(path->floor);
    free(path->ceiling);
    free_char_array(path->split);
    free_char_array(path->rgb);
    free_map(&path->map);
    free_intarray(path->map_array);
    free(path);
    exit(1);
}

void init_path(t_path *path, t_data *data)
{
    path->i = 0;
    path->player_orientation = 0;
    path->so = NULL;
    path->we = NULL;
    path->ea = NULL;
    path->no = NULL;
    path->floor = NULL;
    path->ceiling = NULL;
    path->data = data;
    path->map = malloc(sizeof(t_map *));
    if (path->map == NULL)
        error_path(path, "Error\nMalloc map\n");
    path->textures = malloc(sizeof(t_texture));
    if (path->textures == NULL)
        error_path(path, "Error\nMalloc textures\n");
    path->textures->west = NULL;
    path->textures->east = NULL;
    path->textures->north = NULL;
    path->textures->south = NULL;
    // path->textures->west = malloc(sizeof(t_xpm));
    // if (path->textures->west == NULL)
    //     error_path(path, "Error\nMalloc textures west\n");
    // path->textures->east = malloc(sizeof(t_xpm));
    // if (path->textures->east == NULL)
    //     error_path(path, "Error\nMalloc textures east\n");
    // path->textures->north = malloc(sizeof(t_xpm));
    // if (path->textures->north == NULL)
    //     error_path(path, "Error\nMalloc textures north\n");
    // path->textures->south = malloc(sizeof(t_xpm));
    // if (path->textures->south == NULL)
    //     error_path(path, "Error\nMalloc textures south\n");
    path->map->next = NULL;
    path->map->line = NULL;
    path->map_array = NULL;
    path->split = NULL;
    path->rgb = NULL;
}

void is_right_xpm_file(t_path *path, char *file)
{
    void *img;
    void *mlx;
    int width;
    int height;

    img = NULL;
    mlx = mlx_init();
    img = mlx_xpm_file_to_image(mlx, file,
        &width, &height);
    if (img == NULL)
        error_path(path, "Error\nInvalid texture\n");
    mlx_destroy_image(mlx, img);
}

void check_first_texture(t_xpm *texture, t_path *path)
{
    if (texture != NULL)
        error_path(path, "Error\nDuplicate texture\n");
    texture = malloc(sizeof(t_xpm));
    if (texture == NULL)
        error_path(path, "Error\nMalloc texture\n");
    init_image_texture(path->data, texture, path->split[1]);
}

void check_texture(t_path *path)
{
    // is_right_xpm_file(path, path->split[1]);
    if (ft_strcmp(path->split[0], "SO") == 0)
        check_first_texture(path->textures->south, path);
    else if (ft_strcmp(path->split[0], "WE") == 0)
        check_first_texture(path->textures->west, path);
    else if (ft_strcmp(path->split[0], "EA") == 0)
        check_first_texture(path->textures->east, path);
    else if (ft_strcmp(path->split[0], "NO") == 0)
        check_first_texture(path->textures->north, path);
}

int check_nbr(char *str, t_path *path, int *rgb)
{
    int i;

    i = 0;
    if (ft_strlen(str) > 3)
        error_path(path, "Error\nInvalid RGB value\n");
    while (str[i] != '\0')
    {
        if (ft_isdigit(str[i]) == 0)
            error_path(path, "Error\nInvalid RGB value\n");
        i++;
    }
    if (str[0] > '2' || str[1] > '5' || str[2] > '5')
        error_path(path, "Error\nInvalid RGB value\n");
    *rgb = ft_atoi(str);
    if (*rgb < 0 || *rgb > 255)
        error_path(path, "Error\nInvalid RGB value\n");
    return (0);
}

void    fill_rgb(t_path *path, t_rgb *rgb)
{
    rgb->r = check_nbr(path->rgb[0], path, &rgb->r);
    rgb->g = check_nbr(path->rgb[1], path, &rgb->g);
    rgb->b = check_nbr(path->rgb[2], path, &rgb->b);
}

void create_rgb(t_path *path, t_rgb **rgb)
{
    if (*rgb != NULL)
        error_path(path, "Error\nDuplicate floor\n");
    *rgb = malloc(sizeof(t_rgb));
    if (*rgb == NULL)
        error_path(path, "Error\nMalloc floor\n");
    fill_rgb(path, *rgb);
}

void check_rgb(t_path *path)
{
    path->rgb = ft_split(path->split[1], ',');
    if (path->rgb == NULL)
        error_path(path, "Error\nMalloc RGB\n");
    if (ft_strcmp(path->split[0], "F") == 0)
    {
        // if (path->floor != NULL)
        //     error_path(path, "Error\nDuplicate floor\n");
        // path->floor = malloc(sizeof(t_rgb));
        // if (path->floor == NULL)
        //     error_path(path, "Error\nMalloc floor\n");
        // fill_rgb(path, path->floor);
        create_rgb(path, &path->floor);
    }
    else if (ft_strcmp(path->split[0], "C") == 0)
    {
        // if (path->ceiling != NULL)
        //     error_path(path, "Error\nDuplicate ceiling\n");
        // path->ceiling = malloc(sizeof(t_rgb));
        // if (path->ceiling == NULL)
        //     error_path(path, "Error\nMalloc ceiling\n");
        // fill_rgb(path, path->ceiling);
        create_rgb(path, &path->ceiling);
    }
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

void create_map(t_path *path)
{
    t_map *new;
    int i;

    new = malloc(sizeof(t_map));
    if (new == NULL)
        error_path(path, "Error\nMalloc map\n");
    init_tmap(new, path);
    i = 0;
    while (path->line[i] != '\0')
    {
        if (path->line[i] == '1' || path->line[i] == '0')
            new->line[i] = path->line[i] - '0';
        else if (path->line[i] == 'N' || path->line[i] == 'S'
            || path->line[i] == 'W' || path->line[i] == 'E')
            new->line[i] = path->line[i];
        else if (path->line[i] == ' ' || path->line[i] == '\t')
            new->line[i] = -1;
        else
            error_path(path, "Error\nInvalid map\n");
        i++;
    }
    new->line[i] = '\0';
    t_map_add_back(&path->map, new);
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

int size_x(t_map *map)
{
    int size;
    t_map *tmp;

    tmp = map;
    size = 0;
    while (tmp->next != NULL)
    {
        size++;
        tmp = tmp->next;
    }
    return (size);
}

int max_size(t_map *map)
{
    int max;
    t_map *tmp;

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

void create_x_array(t_path *path, int i, int size_y)
{
    int j;

    j = 0;
    path->map_array[i] = malloc(sizeof(int) * (size_y + 1));
    if (path->map_array[i] == NULL)
        error_path(path, "Error\nMalloc map_array\n");
    while (path->map->line[j] != '\0')
    {
        path->map_array[i][j] = path->map->line[j];
        j++;
    }
    while (j < size_y)
    {
        path->map_array[i][j] = -1;
        j++;
    }
    path->map_array[i][j] = '\0';
}

void test4wall(t_path *path, int i, int j)
{
    if (i == 0 || i == path->mapX - 1 || j == 0 || j == path->mapY - 1)
        error_path(path, "Error\nMap not closed\n");
    if (path->map_array[i - 1][j] == -1
    || path->map_array[i + 1][j] == -1
    || path->map_array[i][j - 1] == -1
    || path->map_array[i][j + 1] == -1)
    error_path(path, "Error\nMap not closed\n");
}

bool is_a_player(int c)
{
    if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
        return (true);
    return (false);
}

void check_wall_around(t_path *path, int i, int j)
{
    if (path->map_array[i][j] == 0 || is_a_player(path->map_array[i][j]))
        test4wall(path, i, j);
    if (is_a_player(path->map_array[i][j]))
    {
        if (path->player_orientation != 0)
            error_path(path, "Error\nDuplicate player\n");
        path->player_orientation = path->map_array[i][j];
    }
}

void verify_closed_map(t_path *path)
{
    int i;
    int j;

    i = 0;
    while (i < path->mapX)
    {
        j = 0;
        while (j < path->mapY)
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

    i = 0;
    path->mapY = max_size(path->map);
    path->mapX = size_x(path->map);
    path->map_array = malloc(sizeof(int *) * ( path->mapX + 1));
    if (path->map_array == NULL)
        error_path(path, "Error\nMalloc map_array\n");
    while (i < path->mapX)
    {
        create_x_array(path, i, path->mapY);
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
    if (nbr_of_texture(path) == 1)
        error_path(path, "Error\nMissing texture\n");
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
}

void check_data(int fd, t_path *path)
{
    path->line = get_next_line(fd);
    while (path->line != NULL && nbr_of_texture(path) == 1)
    {
        check_textures_and_rgb(path);
        path->line = get_next_line(fd);
    }
    while (path->line != NULL && nbr_of_texture(path) == 0)
    {
        create_map(path);
        path->line = get_next_line(fd);
    }
    final_check(path);
    close(fd);
}

void error_check(t_path *path, char *message)
{
    perror(message);
    free(path);
    exit(1);
}

//check if the argument is a valid ".cub" file
t_path *check_args(int argc, char **argv, t_data *data)
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
    init_path(path, data);
    check_data(fd, path);
    return (path);
}