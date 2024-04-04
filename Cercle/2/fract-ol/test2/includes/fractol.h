/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:44:38 by alfloren          #+#    #+#             */
/*   Updated: 2024/03/29 11:02:24 by macbookpro       ###   ########.fr       */
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
#define JULIA_FRACT 1
#define MANDELBROT_FRACT 3
#define BURNINGSHIP_FRACT 2
# define WIDTH 600
# define HEIGHT 600
# define N_WIDTH 5
# define MAX_NUMBER 120

#define KEY_ESC     65307
#define KEY_PLUS    65450
#define KEY_MINUS   65455
#define KEY_LEFT    65361
#define KEY_RIGHT   65363
#define KEY_UP      65362
#define KEY_DOWN    65364
#define KEY_SPACE   32
#define KEY_C    99
#define KEY_V	118
#define KEY_B	98
#define KEY_J	106
#define KEY_T	116

// Mouse codes
#define MOUSE_SCROLL_UP   4
#define MOUSE_SCROLL_DOWN 5
#define MOUSE_LEFT_CLICK  1
#define MOUSE_RIGHT_CLICK 2

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

void			fract_init(t_fractol *data, int fractal_type);
void			mlx_win_init(t_fractol *data);
int				fract_comp(char **av, t_fractol *data);
void 		  	calc_pixel(t_fractol *data);
void			calc_iteration(t_fractol *data);
void			init_calc(t_fractol *data);
void			fractal_calc(t_fractol *data);
#endif
