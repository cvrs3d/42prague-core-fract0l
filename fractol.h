/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:03:57 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/19 14:22:10 by yustinov         ###   ########.fr       */
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
/*
* Image structure
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
*/
typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
}				t_fractal;

# define WIDTH 800
# define HEIGHT 800

int		ft_strncmp(char *s1, char *s2, int n);
void	putstr_fd(char *s, int fd);
void	fractal_init(t_fractal *fractal);

#endif
