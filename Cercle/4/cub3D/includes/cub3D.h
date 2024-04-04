/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:26:41 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/04 13:37:39 by macbookpro       ###   ########.fr       */
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
#define	SIDE_LEN        900
#define ESC_KEY         53
#define KEY_UP          126
#define KEY_DOWN        125
#define KEY_LEFT        123
#define KEY_RIGHT       124
#define SUCCESS         0
#define FAILURE         1
#define PI              3.14159265359
#define P2              PI / 2
#define P3              3 * PI / 2   
#define DR              0.0174533
#define PIXEL_SIZE      64

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
    double  px;
    double  py;
    double  pdx;
    double  pdy;
    double  pa;
    t_ray   *ray;
    double  distT;
}				t_data;


int check_args(int argc, char **argv);

void    mlx_win_init(t_data *data);
void    put_pxl_to_img(t_data *data, int x, int y, int color);