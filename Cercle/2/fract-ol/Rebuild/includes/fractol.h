/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:44:38 by alfloren          #+#    #+#             */
/*   Updated: 2024/03/28 17:42:07 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifdef __APPLE__
#  include "../minilibx_opengl/mlx.h"
#  define OS "macos"
# elif __linux__
#  include "../minilibx-linux/mlx.h"
#  define OS "linux"
# endif
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "math.h"
# include "pthread.h"
# define WIDTH 600
# define N_WIDTH 5
# define MAX_NUMBER 120

#define DEFAULT_IT_MAX 50
#define DEFAULT_ZOOM 300
#define DEFAULT_X1 -2.05
#define DEFAULT_Y1 -1.3
#define DEFAULT_COLOR 265
#define DEFAULT_JULIA_MOUSE 0
#define JULIA 1
#define MANDELBROT 2
#define BURNINGSHIP 3

#define ZOOM_FACTOR 1.3
#define DEZOOM_FACTOR (1.0 / ZOOM_FACTOR)
#define MAX_ITERATION_STEP 50
#define KEY_ESC     65307
#define KEY_PLUS    65450
#define KEY_MINUS   65455
#define KEY_LEFT    65361
#define KEY_RIGHT   65363
#define KEY_UP      65362
#define KEY_DOWN    65364
#define KEY_SPACE   32
#define KEY_V       118
#define KEY_B       98
#define KEY_J       106
#define KEY_T       116
#define KEY_C       99
#define MOUSE_SCROLL_UP    4
#define MOUSE_SCROLL_DOWN  5

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			endian;
	int			sl;
	int			bpp;
	int			fract;
	int			color;
	int			julia_mouse;
	int			x;
	int			y;
	int			y_max;
	int			it;
	int			it_max;
	int			show_text;
	double		zoom;
	double		x1;
	double		y1;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
}				t_fractol;

int				key_hook(int keycode, t_fractol *data);
int				key_hook2(int keycode, t_fractol *data);
void			ft_zoom(int x, int y, t_fractol *data);
void			ft_dezoom(int x, int y, t_fractol *data);
int				mouse_hook(int mousecode, int x, int y, t_fractol *data);
void			free_fractol(t_fractol *data);

int				mouse_julia(int x, int y, t_fractol *data);

int				ft_close(t_fractol *data);
void			put_pxl_to_img(t_fractol *data, int x, int y, int color);
void			put_text(t_fractol *data);

// void			fract_calc(t_fractol *data);
// void			fract_init(t_fractol *data);
void			mlx_win_init(t_fractol *data);
int				fract_comp(char **av, t_fractol *data);

void 			init_fractol_defaults(t_fractol *data, int fractal_type);
void			calculate_fractal(t_fractol *data, int fractal_type);
void			calculate_mandelbrot(t_fractol *data);
void			calculate_julia(t_fractol *data);
void			calculate_burningship(t_fractol *data);
void			render_fractal_lines(t_fractol *data, int fractal_type);
#endif
