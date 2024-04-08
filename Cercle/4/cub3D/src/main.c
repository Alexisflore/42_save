#include "cub3D.h"

void   drawrays3D(t_data *data);
int    mapX = 8;
int    mapY = 8;

int	f(int keysym, t_data *data)
{
    printf("key = %d\n", keysym);
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    return (0);
}

bool    is_wall(t_data *data, int key)
{
    double x = data->px;
    double y = data->py;
    if (key == KEY_UP)
    {
        x += data->pdx;
        y += data->pdy;
    }
    else if (key == KEY_DOWN)
    {
        x -= data->pdx;
        y -= data->pdy;
    }
    else if (key == KEY_RIGHT)
    {
        x -= data->pdy;
        y += data->pdx;
    }
    else if (key == KEY_LEFT)
    {
        x += data->pdy;
        y -= data->pdx;
    }
    if (data->map[(int)(x / PIXEL_SIZE)][(int)(y / PIXEL_SIZE)] == 1
        || data->map[(int)((x + 10) / PIXEL_SIZE)][(int)((y + 10)/ PIXEL_SIZE)] == 1)
        return (true);
    return (false);
}

void pixel_drawing(t_data *data, t_pixel pix);

t_pixel pixel(int x, int y, int size, int color)
{
    t_pixel pix;
    pix.size = size;
    pix.x = x;
    pix.y = y;
    pix.color = color;
    return (pix);
}
//function that takes the touch of the keyboard (key_up, key_down, key_left, key_right, esc) and make a player symbolizes by a pixel move
//the player can move in the 4 directions and can quit the game with the esc key
int   player_move(int key, t_data *data)
{
   //erase the previous position of the player
    pixel_drawing(data, pixel(data->px, data->py, 10, 0x00000000));
    if (key == KEY_UP && is_wall(data, key) == false)
        data->py -= 10;
    else if (key == KEY_DOWN && is_wall(data, key) == false)
        data->py += 10;
    else if (key == KEY_LEFT && is_wall(data, key) == false)
        data->px -= 10;
    else if (key == KEY_RIGHT && is_wall(data, key) == false)
        data->px += 10;
    else if (key == ESC_KEY)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    //draw the new position of the player
    pixel_drawing(data, pixel(data->px, data->py, 10, 0x00FF0000));
    return (0);
}

//draw a line between two points
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

int player_move_with_angle(int key, t_data *data)
{
    // t_collision col;

    // colision(data, &col);
    // next_position(data, &col, key);
    if (key == ESC_KEY)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    else if (key == KEY_CAM_LEFT)
    {
        data->pa -= 0.1;
        if (data->pa < 0)
            data->pa += 2 * PI;
        data->pdx = cos(data->pa) * 10;
        data->pdy = sin(data->pa) * 10;
    }
    else if (key == KEY_CAM_RIGHT)
    {
        data->pa += 0.1;
        if (data->pa > 2 * PI)
            data->pa -= 2 * PI;
        data->pdx = cos(data->pa) * 10;
        data->pdy = sin(data->pa)* 10;
    }
    if (is_wall(data, key) == false)
    {
        if (key == KEY_UP)
        {
            data->px += data->pdx;
            data->py += data->pdy;
        }
        else if (key == KEY_DOWN)
        {
            data->px -= data->pdx;
            data->py -= data->pdy;
        }
        else if (key == KEY_RIGHT)
        {
            data->px -= data->pdy;
            data->py += data->pdx;
        }
        else if (key == KEY_LEFT)
        {
            data->px += data->pdy;
            data->py -= data->pdx;
        }
    }
    // else if (key == KEY_LEFT)
    // {
    //     data->pa -= 0.1;
    //     if (data->pa < 0)
    //         data->pa += 2 * PI;
    //     data->pdx = cos(data->pa) * 10;
    //     data->pdy = sin(data->pa) * 10;
    // }
    // else if (key == KEY_RIGHT)
    // {
    //     data->pa += 0.1;
    //     if (data->pa > 2 * PI)
    //         data->pa -= 2 * PI;
    //     data->pdx = cos(data->pa) * 10;
    //     data->pdy = sin(data->pa)* 10;
    // }
    else if (key == ESC_KEY)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    drawrays3D(data);
    pixel_drawing(data, pixel(data->px, data->py, 10, 0x00FF0000));
    return (0);
}


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

//create an array of integers that represents the map
int worldMap[9][9] =
{
    {1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,1,1},
    {1,0,1,0,0,0,0,1},
    {1,0,1,1,1,1,0,1},
    {1,0,0,0,0,1,0,1},
    {1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1}
};

//draw the map
void drawmap(t_data *data)
{
    int x;
    int y;
    int color;

    x = 0;
    //make all the pixels black
    while (x < SIDE_LEN)
    {
        y = 0;
        while (y < SIDE_LEN)
        {
            if (x > 530 && y < 160)
                pixel_drawing(data, pixel(x, y, 1, convertRGBtoHex(102, 178, 255)));
            else if (x > 530 && y > 160 && y < 320)
                pixel_drawing(data, pixel(x, y, 1, convertRGBtoHex(128, 64, 32)));
            else
                pixel_drawing(data, pixel(x, y, 1, convertRGBtoHex(0, 0, 0)));
            y++;
        }
        x++;
    }
    x = 0;
    y = 0;
    while (x < data->mapX)
    {
        y = 0;
        while (y < data->mapY)
        {
            if (data->map[x][y] == 1)
                color = 0x00FFFFFF; 
            else
                color = 0x00000000;
            pixel_drawing(data, pixel(x * PIXEL_SIZE, y * PIXEL_SIZE, PIXEL_SIZE, color));
            y++;
        }
        x++;
    }
}

double dist(double ax, double ay, double bx, double by)
{
    return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void check_horizontal_lines(t_data *data, t_ray *ray)
{
    ray->disT = 1000000;
    ray->dof = 0;
    float aTan = -1 / tan(ray->ra);
    if (ray->ra > PI)
    {
        ray->ry = (((int)data->py>>6)<<6) - 0.0001;
        ray->rx = (data->py - ray->ry) * aTan + data->px;
        ray->yo = -PIXEL_SIZE;
        ray->xo = -ray->yo * aTan;
    }
    if (ray->ra < PI)
    {
        ray->ry = (((int)data->py>>6)<<6) + PIXEL_SIZE;
        ray->rx = (data->py - ray->ry) * aTan + data->px;
        ray->yo = PIXEL_SIZE;
        ray->xo = -ray->yo * aTan;
    }
    if (ray->ra == 0 || ray->ra == PI)
    {
        ray->rx = data->px;
        ray->ry = data->py;
        ray->dof = 8;
    }
    while (ray->dof < 8)
    {
        ray->mx = (int)(ray->rx) >> 6;
        ray->my = (int)(ray->ry) >> 6;
        ray->mp = ray->my * ray->mx;
        if (ray->mx >= 0 && ray->my >= 0 && ray->mx <= data->mapX && ray->my <= data->mapY && data->map[ray->mx][ray->my] == 1)
        {
            ray->dof = 8;
            ray->disT = dist(data->px, data->py, ray->rx, ray->ry);
        }
        else
        {
            ray->rx += ray->xo;
            ray->ry += ray->yo;
            ray->dof++;
        }
    }
}

void check_vertical_lines(t_data *data, t_ray *ray)
{
    ray->dof = 0;
    ray->disT = 1000000;
    double nTan = - tan(ray->ra);
    if (ray->ra > P2 && ray->ra < P3)
    {
        ray->rx = (((int)data->px>>6)<<6) - 0.0001;
        ray->ry = (data->px - ray->rx) * nTan + data->py;
        ray->xo = -PIXEL_SIZE;
        ray->yo = -ray->xo * nTan;
    }
    if (ray->ra < P2 || ray->ra > P3)
    {
        ray->rx = (((int)data->px>>6)<<6) + PIXEL_SIZE;
        ray->ry = (data->px - ray->rx) * nTan + data->py;
        ray->xo = PIXEL_SIZE;
        ray->yo = -ray->xo * nTan;
    }
    if (ray->ra == 0 || ray->ra == PI)
    {
        ray->rx = data->px;
        ray->ry = data->py;
        ray->dof = 8;
    }
    while (ray->dof < 8)
    {
        ray->mx = (int)(ray->rx) >> 6;
        ray->my = (int)(ray->ry) >> 6;
        ray->mp = ray->my * ray->mx;
        if (ray->mx >= 0 && ray->my >= 0 && ray->mx <= data->mapX && ray->my <= data->mapY && data->map[ray->mx][ray->my] == 1)
        {
            ray->dof = 8;
            ray->disT = dist(data->px, data->py, ray->rx, ray->ry);
        }
        else
        {
            ray->rx += ray->xo;
            ray->ry += ray->yo;
            ray->dof++;
        }
    }
}

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

void find_angle(t_ray *rayH, t_ray *rayV)
{
    if (rayV->ra < 0)
        rayV->ra += 2 * PI;
    if (rayV->ra > 2 * PI)
        rayV->ra -= 2 * PI;
    rayH->ra = rayV->ra;
}

void    find_distT(t_data *data, t_ray *rayH, t_ray *rayV)
{
    double ca;
    ca = data->pa - rayH->ra;
    if (ca < 0)
        ca += 2 * PI;
    if (ca > 2 * PI)
        ca -= 2 * PI;
    if (rayH->disT < rayV->disT)
    {
        data->distT = rayH->disT;
        if (rayH->ra < PI && rayH->ra > 0)
            data->texture = data->textures->north;
        else
            data->texture = data->textures->south;
    }
    else
    {
        if (rayV->ra > P2 && rayV->ra < P3)
            data->texture = data->textures->west;
        else
            data->texture = data->textures->east;
        data->distT = rayV->disT;
        data->shade = 0.5;
    }
    data->distT *= cos(ca);
}

void    draw3Dwall(t_data *data, t_ray *rayH, t_ray *rayV)
{
    data->shade = 1;
    find_distT(data, rayH, rayV);
    int lineH = (PIXEL_SIZE * 320) / data->distT;
    double ty_step = 64.0 / (double)lineH;
    double lineOff;
    lineOff = 160 - (lineH>>1);
    // t_xpm wall;

    // wall = data->texture;
    double ty = 0;
    double tx = 0;
    // double tx_step = 1;
    if (data->shade == 1)
    {
        tx = (int) (rayH->rx/2) % 64;
        if (rayH->ra > PI)
            tx = 64 - tx - 1;
    }
    else
    {
        tx = (int) (rayV->ry/2) % 64;
        if (rayV->ra < P2 || rayV->ra > P3)
            tx = 64 - tx - 1;
    }
    // wall.img = mlx_xpm_file_to_image(data->mlx, "Ouest.xpm", &wall.width, &wall.height);
    // if (wall.img == NULL)
    // {
    //     // Handle error loading texture
    //     return;
    // }
    // Get the pixel data of the texture
    // wall.texture = (int *)mlx_get_data_addr(wall.img, &wall.bpp, &wall.size_line, &wall.endian);
    //Draw the texture
    int j = 0;
    int i = 0;
    // double x;
    while (j < lineH && lineOff + j <= 320)
    {
        i = 0;
        if (lineOff + j >= 0)
        {
            // x = (int)tx;
            // while (i < 8)
            // {
                // int color = wall.texture[(int)tx + 32 * (int)ty];
                int color = data->texture->texture[(int)tx + 64 * (int)ty];
                put_pxl_to_img(data, 530 + rayH->r + i, lineOff + j, color);
                // pixel_drawing(data, pixel(530 + rayH->r , lineOff + j, 4, color));
            //     i++;
            // //     // x += tx_step;
            // }
        }
        ty += ty_step;
        j++;
    }
}

void   drawrays3D(t_data *data)
{
    t_ray rayH;
    t_ray rayV;

    drawmap(data);
    rayV.ra = data->pa - DR8 * 30 * 8;
    find_angle(&rayH, &rayV);
    rayH.r = 0;
    while (rayH.r < 60 * 8)
    {
        rayH.disT = 1000000;
        rayV.disT = 1000000;
        check_horizontal_lines(data, &rayH);
        check_vertical_lines(data, &rayV);
        draw_ray(data, &rayH, &rayV, 0x0000FF00);
        draw3Dwall(data, &rayH, &rayV);
        rayV.ra += DR8;
        find_angle(&rayH, &rayV);
        rayH.r++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	main(void)
{
    int **worldmap = malloc(sizeof(int *) * 9);
    for (int i = 0; i < 9; i++)
        worldmap[i] = malloc(sizeof(int) * 9);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            worldmap[i][j] = worldMap[j][i];
    }
    t_data data;
    mlx_win_init(&data, worldmap);
    // mlx_key_hook(data.win, f, &data);
    mlx_hook(data.win, KeyPress, KeyPressMask, player_move_with_angle, &data);
    mlx_loop(data.mlx);
    return (0);
}