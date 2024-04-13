#include "cub3D.h"

void   exit_error(char *message, t_data *data)
{
    perror(message);
    free_path(&data->path);
    free_data(data);
    exit(1);
}

static int  find_horizon(t_path *path)
{
    if (path->mapX < path->mapY)
        return(path->mapY);
    return(path->mapX);
}

void    init_values(t_data *data, t_path *path)
{
    data->mapX = path->mapX;
    data->mapY = path->mapY;
    data->horizon = find_horizon(path);
    data->map = path->map_array;
    data->px = path->player_x;
    data->py = path->player_y;
    data->pdx = 0;
    data->pdy = 0;
    data->pa = path->player_angle;
    data->textures = path->textures;
    data->ceiling = path->ceiling;
    data->floor = path->floor;
    data->path = path;
}


// void    init_image_texture(t_data *data, t_xpm *texture, char *file)
// {
//     texture->img = mlx_xpm_file_to_image(data->mlx, file,
//         &texture->width, &texture->height);
//     if (texture->img == NULL)
//         exit_error("Error texture img\n", data);
//     texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
//         &texture->size_line, &texture->endian);
//     texture->texture = (int *)mlx_get_data_addr(texture->img, &texture->bpp,
//         &texture->size_line, &texture->endian);
// }

// void malloc_textures(t_data *data)
// {
//     data->textures = malloc(sizeof(t_texture) * 4);
//     if (data->textures == NULL)
//         exit_error("Error textures malloc\n", data);
//     data->textures->west = NULL;
//     data->textures->east = NULL;
//     data->textures->north = NULL;
//     data->textures->south = NULL;
//     data->textures->west = malloc(sizeof(t_xpm));
//     if (data->textures->west == NULL)
//         exit_error("Error textures west malloc\n", data);
//     data->textures->east = malloc(sizeof(t_xpm));
//     if (data->textures->east == NULL)
//         exit_error("Error textures east malloc\n", data);
//     data->textures->north = malloc(sizeof(t_xpm));
//     if (data->textures->north == NULL)
//         exit_error("Error textures north malloc\n", data);
//     data->textures->south = malloc(sizeof(t_xpm));
//     if (data->textures->south == NULL)
//         exit_error("Error textures south malloc\n", data);
// }

void	mlx_win_init(t_data *data, t_path *path)
{
    init_values(data, path);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx,SIDE_LEN,320, "cub3D");
	data->img = mlx_new_image(data->mlx,SIDE_LEN,320);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bpp, &data->sl, &data->endian);
    // malloc_textures(data);
    // init_image_texture(data, data->textures->west, "textures/west.xpm");
    // init_image_texture(data, data->textures->east, "textures/east.xpm");
    // init_image_texture(data, data->textures->north, "textures/north.xpm");
    // init_image_texture(data, data->textures->south, "textures/south.xpm");
}