#include "cub3D.h"

int convertRGBtoHex(t_rgb *rgb)
{
    //return the hex value wiht 100% opacity
    return (rgb->r << 16 | rgb->g << 8 | rgb->b);
}