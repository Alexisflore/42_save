#include "cub3D.h"

void    init_image_texture(t_data *data, t_xpm *texture, char *path)
{
    texture->img = mlx_xpm_file_to_image(data->mlx, path, &texture->width, &texture->height);
    if (texture->img == NULL)
    {
        printf("Error\n");
        exit(1);
    }
    texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, &texture->size_line, &texture->endian);
    texture->texture = (int *)mlx_get_data_addr(texture->img, &texture->bpp, &texture->size_line, &texture->endian);
}

void malloc_textures(t_data *data)
{
    data->textures = malloc(sizeof(t_texture) * 4);
    data->textures->west = malloc(sizeof(t_xpm));
    data->textures->east = malloc(sizeof(t_xpm));
    data->textures->north = malloc(sizeof(t_xpm));
    data->textures->south = malloc(sizeof(t_xpm));
}

void	mlx_win_init(t_data *data, int **worldmap)
{
    data->mapX = 8;
    data->mapY = 8;
    data->map = worldmap;
    data->px = PIXEL_SIZE + 1;
    data->py = PIXEL_SIZE + 1;
    data->pdx = 0;
    data->pdy = 0;
    //data->pa represents the angle of the player in radians
    data->pa = PI / 2;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SIDE_LEN, SIDE_LEN, "cub3D");
	data->img = mlx_new_image(data->mlx, SIDE_LEN, SIDE_LEN);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bpp, &data->sl, &data->endian);
    // t_texture *textures = malloc(sizeof(t_texture) * 5);
    // data->textures = textures;
    // data->textures->west = malloc(sizeof(t_xpm));
    // data->textures->east = malloc(sizeof(t_xpm));
    malloc_textures(data);
    init_image_texture(data, data->textures->west, "textures/west.xpm");
    init_image_texture(data, data->textures->east, "textures/east.xpm");
    init_image_texture(data, data->textures->north, "textures/north.xpm");
    init_image_texture(data, data->textures->south, "textures/south.xpm");
    // data->textures->west->img = mlx_xpm_file_to_image(data->mlx, "textures/south.xpm", &data->textures->west->width, &data->textures->west->height);
    // data->textures->east->img = mlx_xpm_file_to_image(data->mlx, "textures/north.xpm", &data->textures->east->width, &data->textures->east->height);
    // data->textures->west->addr = mlx_get_data_addr(data->textures->west->img, &data->textures->west->bpp, &data->textures->west->size_line, &data->textures->west->endian);
    // data->textures->east->addr = mlx_get_data_addr(data->textures->east->img, &data->textures->east->bpp, &data->textures->east->size_line, &data->textures->east->endian);
    // data->textures->west->texture = (int *)mlx_get_data_addr( data->textures->west->img, &data->textures->west->bpp, &data->textures->west->size_line, &data->textures->west->endian);
    // printf("succes\n");
    // data->textures->east->texture = (int *)mlx_get_data_addr( data->textures->east->img, &data->textures->east->bpp, &data->textures->east->size_line, &data->textures->east->endian);
}


// void init_textures(t_data *data)
// {
//     data->textures = malloc(sizeof(t_texture) * 4);
//     init_image_texture(data, data->textures->west, "textures/west.xpm");
//     init_image_texture(data, data->textures->east, "textures/east.xpm");
//     init_image_texture(data, data->textures->north, "textures/north.xpm");
//     init_image_texture(data, data->textures->south, "textures/south.xpm");
// }
// void	mlx_win_init(t_data *data, int **worldmap)
// {
//     data->mapX = 8;
//     data->mapY = 8;
//     data->map = worldmap;
//     data->px = PIXEL_SIZE + 1;
//     data->py = PIXEL_SIZE + 1;
//     data->pdx = 0;
//     data->pdy = 0;
//     //data->pa represents the angle of the player in radians
//     data->pa = PI / 2;
// 	data->mlx = mlx_init();
// 	data->win = mlx_new_window(data->mlx, SIDE_LEN, SIDE_LEN, "cub3D");
// 	data->img = mlx_new_image(data->mlx, SIDE_LEN, SIDE_LEN);
// 	data->img_ptr = mlx_get_data_addr(data->img,
// 			&data->bpp, &data->sl, &data->endian);
//     init_textures(data);
// }