#include "cub3D.h"
#include <time.h>



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

//find the number of frames per second
int	get_fps(void)
{
	static int		fps = 0;
	static time_t	oldtime = 0;
	time_t			newtime;

	time(&newtime);
	if (newtime != oldtime)
	{
		oldtime = newtime;
		fps = 0;
	}
	fps++;
	return (fps);
}