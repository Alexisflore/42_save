#include "cub3D.h"

void	mlx_win_init(t_data *data)
{
	data->win = mlx_new_window(data->mlx, SIDE_LEN, SIDE_LEN, "cub3D");
	data->img = mlx_new_image(data->mlx, SIDE_LEN, SIDE_LEN);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bpp, &data->sl, &data->endian);
}

void	put_pxl_to_img(t_data *data, int x, int y, int color)
{
	if (x < SIDE_LEN && y < SIDE_LEN)
	{
		color = mlx_get_color_value(data->mlx, color);
		// put the color value in the image at the right place
		ft_memcpy(data->img_ptr + 4 * SIDE_LEN * y + x * 4,
				&color, sizeof(int));
	}
}