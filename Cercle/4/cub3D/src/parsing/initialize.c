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
    data->horizon = 8;
    data->map = worldmap;
    data->px = PIXEL_SIZE + 1;
    data->py = PIXEL_SIZE + 1;
    data->pdx = 0;
    data->pdy = 0;
    data->pa = PI / 2;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx,SIDE_LEN,320, "cub3D");
	data->img = mlx_new_image(data->mlx,SIDE_LEN,320);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bpp, &data->sl, &data->endian);
    malloc_textures(data);
    init_image_texture(data, data->textures->west, "textures/west.xpm");
    init_image_texture(data, data->textures->east, "textures/east.xpm");
    init_image_texture(data, data->textures->north, "textures/north.xpm");
    init_image_texture(data, data->textures->south, "textures/south.xpm");
}
