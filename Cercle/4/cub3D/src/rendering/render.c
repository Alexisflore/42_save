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

int get_fps()
{
	static int fps = 0;
	static clock_t time = 0;
	static clock_t old_time = 0;
	static int frames = 0;
	static int old_frames = 0;

	time = clock();
	if (time - old_time > CLOCKS_PER_SEC)
	{
		fps = frames - old_frames;
		old_time = time;
		old_frames = frames;
	}
	frames++;
	return (fps);
}

t_wall *init_wall(t_data *data, t_ray *rayH, t_ray *rayV)
{
    t_wall *wall = malloc(sizeof(t_wall));
    data->shade = 1;
    find_distT(data, rayH, rayV);
    wall->lineH = (PIXEL_SIZE * 320) / data->distT;
    wall->ty_step = 64.0 / (double)wall->lineH;
    wall->lineOff = 160 - wall->lineH / 2;
    wall->ty = 0;
    wall->tx = 0;
    if (data->shade == 1)
    {
        wall->tx = (int) (rayH->rx * 2) % 64;
        if (rayH->ra > PI)
            wall->tx = 64 - wall->tx - 1;
    }
    else
    {
        wall->tx = (int)(rayV->ry * 2) % 64;
        if (rayV->ra < P2 || rayV->ra > P3)
            wall->tx = 64 - wall->tx - 1;
    }
    return (wall);
}   

void    draw3Dwall(t_data *data, t_ray *rayH, t_ray *rayV)
{
    t_wall *wall;
    
    wall = init_wall(data, rayH, rayV);
    int j = 0;
    while (j < wall->lineH && wall->lineOff + j <= 320)
    {
        if (wall->lineOff + j >= 0)
        {
            wall->color = data->texture->texture[(int)wall->tx + 64 * (int)wall->ty];
            put_pxl_to_img(data, rayH->r, wall->lineOff + j, wall->color);
        }
        wall->ty += wall->ty_step;
        j++;
    }
    free(wall);
}

void   drawrays3D(t_data *data)
{
    t_ray rayH;
    t_ray rayV;

    drawmap(data);
    rayV.ra = data->pa - DR * 30 * 10;
    find_angle(&rayH, &rayV);
    rayH.r = 0;
    while (rayH.r < 60 * 10)
    {
        check_horizontal_lines(data, &rayH);
        check_vertical_lines(data, &rayV);
        // draw_ray(data, &rayH, &rayV, 0x0000FF00);
        draw3Dwall(data, &rayH, &rayV);
        rayV.ra += DR;
        find_angle(&rayH, &rayV);
        rayH.r += 1;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}