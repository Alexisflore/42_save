#include "cub3D.h"

void draw_ray(t_data *data, t_ray *rayH, t_ray *rayV, int color)
{
    if (rayH->disT < rayV->disT)
    {
        draw_line(data, data->px, data->py, rayH->rx, rayH->ry, color);
    }
    else
    {
        draw_line(data, data->px, data->py, rayV->rx, rayV->ry, color);
    }
}

void draw_floor_and_ceiling(t_data *data)
{
    int x;
    int y;

    x = 0;
    while (x < SIDE_LEN)
    {
        y = 0;
        while (y < SIDE_LEN)
        {
            if (y < 160 && x < 600)
                put_pxl_to_img(data, x, y, convertRGBtoHex(data->floor));
            else if (y >= 160 && y < 320 && x < 600)
                put_pxl_to_img(data, x, y, convertRGBtoHex(data->ceiling));
            y++;
        }
        x++;
    }
}

//draw the map
void drawmap(t_data *data)
{
    // int x;
    // int y;
    // int color;

    draw_floor_and_ceiling(data);
    // x = 0;
    // y = 0;
    // while (x < data->mapX)
    // {
    //     y = 0;
    //     while (y < data->mapY)
    //     {
    //         if (data->map[x][y] == 1)
    //             color = 0x00FFFFFF; 
    //         else
    //             color = 0x00000000;
    //         pixel_drawing(data, pixel(x * PIXEL_SIZE, y * PIXEL_SIZE, PIXEL_SIZE, color));
    //         y++;
    //     }
    //     x++;
    // }
}

void draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float X = x1;
    float Y = y1;
    int i = 0;
    while (i <= steps)
    {
        // mlx_pixel_put(data->mlx, data->win, X, Y, color);
        put_pxl_to_img(data, X, Y, color);
        X += Xinc;
        Y += Yinc;
        i++;
    }
}

void    directtion_line(t_data *data, int color)
{
    int i = 0;
    while (i < 50)
    {
        // mlx_pixel_put(data->mlx, data->win, data->px + i * cos(data->pa) + 5, data->py + i * sin(data->pa) + 5, color);
        put_pxl_to_img(data, data->px + i * cos(data->pa) + 5, data->py + i * sin(data->pa) + 5, color);
        i++;
    }
}