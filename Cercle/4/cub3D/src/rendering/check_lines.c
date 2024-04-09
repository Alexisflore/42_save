#include "cub3D.h"

void init_rayH(t_ray *ray, t_data *data)
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
}

void check_horizontal_lines(t_data *data, t_ray *ray)
{
    ray->disT = 1000000;
    init_rayH(ray, data);
    while (ray->dof < 8)
    {
        ray->mx = (int)(ray->rx) >> 6;
        ray->my = (int)(ray->ry) >> 6;
        ray->mp = ray->my * ray->mx;
        if (ray->mx >= 0 && ray->my >= 0 && ray->mx <= data->mapX && ray->my <= data->mapY && data->map[ray->mx][ray->my] == 1)
        {
            ray->dof = data->horizon;
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

void init_rayV(t_ray *ray, t_data *data)
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
}

void check_vertical_lines(t_data *data, t_ray *ray)
{
    init_rayV(ray, data);
    while (ray->dof < 8)
    {
        ray->mx = (int)(ray->rx) >> 6;
        ray->my = (int)(ray->ry) >> 6;
        ray->mp = ray->my * ray->mx;
        if (ray->mx >= 0 && ray->my >= 0 && ray->mx <= data->mapX
            && ray->my <= data->mapY && data->map[ray->mx][ray->my] == 1)
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