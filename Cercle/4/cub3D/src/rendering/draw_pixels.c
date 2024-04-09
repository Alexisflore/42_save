#include "cub3D.h"

void pixel_drawing(t_data *data, t_pixel pix)
{
    int i = 0;
    while (i < pix.size)
    {
        int j = 0;
        while (j < pix.size)
        {
            put_pxl_to_img(data, pix.x + i, pix.y + j, pix.color);
            // mlx_pixel_put(data->mlx, data->win, pix.x + i, pix.y + j, pix.color);
            j++;
        }
        i++;
    }
}

t_pixel pixel(int x, int y, int size, int color)
{
    t_pixel pix;
    pix.size = size;
    pix.x = x;
    pix.y = y;
    pix.color = color;
    return (pix);
}