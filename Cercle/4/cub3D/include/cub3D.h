/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:26:41 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/12 17:10:28 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"
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
// # include <X11/keysym.h>
// # include <X11/X.h>

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
    int *line;
    int size;
    struct s_map *next;
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

typedef struct t_path
{
    t_data *data;
    void *mlx;
    char *no;
    char *so;
    char *we;
    char *ea;
    char *s;
    char *line;
    char **split;
    char **rgb;
    int   i;
    t_rgb *floor;
    t_rgb *ceiling;
    t_texture *textures;
    t_map *map;
    int **map_array;
    int mapX;
    int mapY;
    char player_orientation;
}               t_path;

/* parsing */
void    exit_error(char *message, t_data *data);
int     is_all_textures(t_path *path);
void    free_intarray(int **array);
void    free_char_array(char **array);
void    error_path(t_path *path, char *message);
void    init_path(t_path *path);
void    is_right_xpm_file(t_path *path, char *file);
void    check_first_texture(t_xpm **texture, t_path *path);
void    check_texture(t_path *path);
void    check_nbr(char *str, t_path *path, int *rgb);
void    fill_rgb(t_path *path, t_rgb **rgb);
void    create_rgb(t_path *path, t_rgb **rgb);
void    check_rgb(t_path *path);
void    init_tmap(t_map *new, t_path *path);
void    create_map(t_path *path);
int     is_texture(char *str);
int     is_rgb(char *str);
void    free_map(t_map **map);
int     size_x(t_map *map);
int     max_size(t_path *path, t_map *map);
void    create_x_array(t_path *path, int i, t_map *map);
void    test4wall(t_path *path, int i, int j);
void    check_wall_around(t_path *path, int i, int j);
void    verify_closed_map(t_path *path);
void    create_map_array(t_path *path);
void    check_map(t_path *path);
void    final_check(t_path *path);
void    check_textures_and_rgb(t_path *path);
void    check_data(int fd, t_path *path);
t_path  *check_args(int argc, char **argv);
void    t_map_add_back(t_map **alst, t_map *new);
void    error_check(t_path *path, char *message);
void    init_image_texture(t_data *data, t_xpm *texture, char *file);
int     is_all_spaces_or_newline(t_path *path);

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

/* free */
void    free_data(t_data *data);

void    colision(t_data *data, t_collision *col);




