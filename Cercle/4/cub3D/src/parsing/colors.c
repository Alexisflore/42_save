#include "cub3D.h"

int convertRGBtoHex(int r, int g, int b)
{
    //return the hex value wiht 100% opacity
    return (r << 16 | g << 8 | b);
}