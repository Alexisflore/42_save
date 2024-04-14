/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:26:41 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/14 18:34:43 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# ifdef __linux__
#  include <X11/keysym.h>
# endif

# define MALLOC_ERROR 1
# define SIDE_LEN 600

# define PI 3.14159265359
# define P2 1.5708
# define P3 4.71239
# define DR 0.00174533
# define PIXEL_SIZE 64
# define PIXEL_TEXTURE 64

# ifdef __APPLE__

typedef enum e_apple_key
{
	APPLE_KEY_A = 0,
	APPLE_KEY_S = 1,
	APPLE_KEY_D = 2,
	APPLE_KEY_W = 13,
	APPLE_KEY_ESCAPE = 53,
	APPLE_KEY_LEFT = 123,
	APPLE_KEY_RIGHT = 124,
}					t_apple_key;

# endif

typedef struct t_wall
{
	double			tx;
	double			ty;
	double			ty_step;
	double			lineoff;
	double			lineh;
	double			color;
}					t_wall;

typedef struct rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct t_xpm
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				size_line;
	int				*texture;
	int				bpp;
	int				sl;
	int				endian;
}					t_xpm;

typedef struct t_texture
{
	t_xpm			*north;
	t_xpm			*south;
	t_xpm			*west;
	t_xpm			*east;
}					t_texture;

typedef struct s_map
{
	int				*line;
	int				size;
	struct s_map	*next;
}					t_map;

typedef struct s_pixel
{
	int				size;
	int				x;
	int				y;
	int				color;
}					t_pixel;

typedef struct s_ray
{
	int				r;
	int				mx;
	int				my;
	int				mp;
	int				dof;
	double			rx;
	double			ry;
	double			ra;
	double			xo;
	double			yo;
	double			dist;
}					t_ray;

typedef struct t_path
{
	void			*mlx;
	char			*s;
	char			*line;
	char			**split;
	char			**rgb;
	t_rgb			*floor;
	t_rgb			*ceiling;
	t_texture		*textures;
	t_map			*map;
	int				**map_array;
	int				mapx;
	int				mapy;
	char			player_orientation;
	int				player_x;
	int				player_y;
	double			player_angle;
}					t_path;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				sl;
	int				endian;
	int				**map;
	int				mapx;
	int				mapy;
	int				horizon;
	double			px;
	double			py;
	double			pdx;
	double			pdy;
	double			pa;
	t_ray			*ray;
	double			dist;
	double			shade;
	t_texture		*textures;
	t_xpm			*texture;
	t_rgb			*floor;
	t_rgb			*ceiling;
	t_path			*path;
}					t_data;

typedef struct t_collision
{
	int				xo;
	int				yo;
	int				ipx;
	int				ipy;
	int				ipx_add_xo;
	int				ipx_sub_xo;
	int				ipy_add_yo;
	int				ipy_sub_yo;
}					t_collision;

/* parsing */
void				exit_error(char *message, t_data *data);
int					is_all_textures(t_path *path);
void				free_intarray(int **array);
void				free_char_array(char **array);
void				free_texture(t_data *data, t_xpm *xpm);
void				error_path(t_data *data, t_path *path, char *message);
void				init_path(t_data *data, t_path *path);
void				check_first_texture(t_data *data, t_xpm **texture,
						t_path *path);
void				check_texture(t_data *data, t_path *path);
void				check_nbr(t_data *data, char *str, t_path *path, int *rgb);
void				fill_rgb(t_data *data, t_path *path, t_rgb **rgb);
void				create_rgb(t_data *data, t_path *path, t_rgb **rgb);
void				check_rgb(t_data *data, t_path *path);
void				init_tmap(t_data *data, t_map *new, t_path *path);
void				create_map(t_data *data, t_path *path);
int					is_texture(char *str);
int					is_rgb(char *str);
void				free_map(t_map *map);
int					size_x(t_map *map);
int					max_size(t_data *data, t_path *path, t_map *map);
void				create_x_array(t_data *data, t_path *path, int i,
						t_map *tmp);
void				test4wall(t_data *data, t_path *path, int i, int j);
void				check_wall_around(t_data *data, t_path *path, int i, int j);
void				verify_closed_map(t_data *data, t_path *path);
void				create_map_array(t_data *data, t_path *path);
void				check_map(t_data *data, t_path *path);
void				final_check(t_data *data, t_path *path);
void				check_textures_and_rgb(t_data *data, t_path *path);
void				check_data(int fd, t_data *data, t_path *path);
t_path				*check_args(int argc, char **argv, t_data *data);
void				t_map_add_back(t_map **alst, t_map *new);
void				error_check(t_path *path, char *message);
void				init_image_texture(t_data *data, t_xpm *texture,
						char *file);
int					is_all_spaces_or_newline(t_path *path);
void				init_img_xpm(t_xpm **texture, t_data *data, t_path *path,
						char *file);
int					int_line(t_data *data, t_path **path, int i);
int					is_a_direction(char c);
void				next_data(t_path *path, int fd);
void				create_final_map(t_path *path);
void				initial_position(t_path *path, int x, int y, char c);
void				free_path(t_data *data, t_path *path);
int					array_size(char **array);
void				delete_newline(char ***array);
char				**ft_split_space(char const *s);

/* rendering */
t_pixel				pixel(int x, int y, int size, int color);
void				pixel_drawing(t_data *data, t_pixel pix);
// void				draw_line(t_data *data, int x1, int y1, int x2, int y2,
// 						int color);
void				draw_floor_and_ceiling(t_data *data);
void				drawrays_3d(t_data *data);
void				mlx_win_init(t_data *data, t_path *path);
void				put_pxl_to_img(t_data *data, int x, int y, int color);
void				draw_3d_wall(t_data *data, t_ray *rayH, t_ray *rayV);
void				find_angle(t_ray *rayH, t_ray *rayV);
void				check_vertical_lines(t_data *data, t_ray *ray);
void				init_rayv(t_ray *ray, t_data *data);
void				check_horizontal_lines(t_data *data, t_ray *ray);
void				init_rayh(t_ray *ray, t_data *data);
void				draw_ray(t_data *data, t_ray *rayH, t_ray *rayV, int color);
double				dist(double x1, double y1, double x2, double y2);
int					convert_rgb_to_hex(t_rgb *rgb);
void				find_dist_t(t_data *data, t_ray *rayH, t_ray *rayV);
int					get_fps(void);
void				drawmap(t_data *data);

/* move */
void				next_position(t_data *data, t_collision *col, int key);

/* free */
void				free_data(t_data *data);

void				colision(t_data *data, t_collision *col);

int					player_move_with_angle(int key, t_data *data);

#endif
