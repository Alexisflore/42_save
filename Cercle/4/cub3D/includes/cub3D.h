/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:26:41 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/09 15:20:55 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx_opengl/mlx.h"
#include <stdlib.h>
#include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

#define MALLOC_ERROR    1
#define	SIDE_LEN        600
#define ESC_KEY         53
#define KEY_UP          13
#define KEY_DOWN        1
#define KEY_LEFT        0
#define KEY_RIGHT       2

#define KEY_CAM_LEFT    123
#define KEY_CAM_RIGHT   124

#define SUCCESS         0
#define FAILURE         1
#define PI              3.14159265359
#define P2              PI / 2
#define P3              3 * PI / 2
#define DR              0.00174533
#define PIXEL_SIZE      64
#define PIXEL_TEXTURE   64

typedef struct t_wall
{
    double tx;
    double ty;
    double ty_step;
    double lineOff;
    double  lineH;
    double  color;
}           t_wall;

typedef struct rgb
{
    int r;
    int g;
    int b;
}               t_rgb;

typedef struct t_xpm
{
    void *img;
    char *addr;
    int width;
    int height;
    int size_line;
    int *texture;
    int bpp;
    int sl;
    int endian;
}               t_xpm;

typedef struct t_texture
{
    t_xpm *north;
    t_xpm *south;
    t_xpm *west;
    t_xpm *east;
}               t_texture;

typedef struct s_map
{
    int **map;
    int mapX;
    int mapY;
    t_texture *texture;
    t_rgb *floor;
    t_rgb *ceiling;
}               t_map;

typedef struct s_pixel
{
    int size;
    int x;
    int y;
    int color;
}               t_pixel;

typedef struct s_ray
{
    int r;
    int mx;
    int my;
    int mp;
    int dof;
    double rx;
    double ry;
    double ra;
    double xo;
    double yo;
    double disT;
}               t_ray;

typedef struct	s_data
{
    void	*mlx;
    void	*win;
    void    *img;
    char    *img_ptr;
    int     bpp;
    int     sl;
    int     endian;
    int     **map;
    int     mapX;
    int     mapY;
    int     horizon;
    double  px;
    double  py;
    double  pdx;
    double  pdy;
    double  pa;
    t_ray   *ray;
    double  distT;
    double  shade;
    t_texture *textures;
    t_xpm *texture;
}				t_data;


typedef struct t_collision
{
    int xo;
    int yo;
    int ipx;
    int ipy;
    int ipx_add_xo;
    int ipx_sub_xo;
    int ipy_add_yo;
    int ipy_sub_yo;
}               t_collision;

/* parsing */
int check_args(int argc, char **argv);

/* rendering */
t_pixel pixel(int x, int y, int size, int color);
void    pixel_drawing(t_data *data, t_pixel pix);
void    draw_line(t_data *data, int x1, int y1, int x2, int y2, int color);
void    draw_floor_and_ceiling(t_data *data);
void    drawrays3D(t_data *data);
void    mlx_win_init(t_data *data, int **worldmap);
void    put_pxl_to_img(t_data *data, int x, int y, int color);
void    draw3Dwall(t_data *data, t_ray *rayH, t_ray *rayV);
void    find_angle(t_ray *rayH, t_ray *rayV);
void    check_vertical_lines(t_data *data, t_ray *ray);
void    init_rayV(t_ray *ray, t_data *data);
void    check_horizontal_lines(t_data *data, t_ray *ray);
void    init_rayH(t_ray *ray, t_data *data);
void    draw_ray(t_data *data, t_ray *rayH, t_ray *rayV, int color);
double  dist(double x1, double y1, double x2, double y2);
int     convertRGBtoHex(int r, int g, int b);
void    find_distT(t_data *data, t_ray *rayH, t_ray *rayV);
int     get_fps(void);
void    drawmap(t_data *data);

/* move */
bool is_wall(t_data *data, int key);
int player_move_with_angle(int key, t_data *data);
void    next_position(t_data *data, t_collision *col, int key);


void    colision(t_data *data, t_collision *col);




