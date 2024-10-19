/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:03:57 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/19 16:57:56 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <unistd.h>
# ifndef ERROR_MASSAGE
#  define ERROR_MASSAGE "./fractol mandelbrot\n\t./fractol julia <real> <imag>"
# endif

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

/*
* Image structure
* This structure holds, all the data
* from the mlx_new_image function
* and the mlx_get_data_addr function
* 1. img_pointer - pointer to the image
* 2. pixels_pointer - pointer to some pixel of the image
* 3. bpp - number of bits per pixel
* 4. endian - endianess of the image
*/
typedef struct s_image
{
	void	*img_pointer;
	char	*pixels_pointer;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;
/*
* Fractal structure
* This structure holds, all the data
* from the mlx_init, mlx_new_window, mlx_new_image
* and mlx_get_data_addr functions
* 1. name - name of the fractal
* 2. mlx_connection - pointer to the connection to the X server
* 3. mlx_window - pointer to the window
* 4. img - structure that holds the image data
*/
typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_val;
	int		max_iter;
}				t_fractal;

# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000  // RGB(0, 0, 0)
# define WHITE 0xFFFFFF  // RGB(255, 255, 255)
# define RED 0xFF0000  // RGB(255, 0, 0)
# define GREEN 0x00FF00  // RGB(0, 255, 0)
# define BLUE 0x0000FF  // RGB(0, 0, 255)
# define MAGENTA_BURST 0xFF00FF  // A vibrant magenta
# define LIME_SHOCK 0xCCFF00  // A blinding lime
# define NEON_ORANGE 0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
# define AQUA_DREAM 0x33CCCC  // A bright turquoise
# define HOT_PINK 0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE 0x0066FF  // A radiant blue
# define LAVA_RED 0xFF3300  // A bright, molten red

int			ft_strncmp(char *s1, char *s2, int n);
void		putstr_fd(char *s, int fd);
void		fractal_init(t_fractal *fractal);
double		scale(double unscaled_num, double new_min, double new_max);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);

#endif
