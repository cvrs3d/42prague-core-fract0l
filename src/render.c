/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:24:35 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/21 14:08:46 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_pointer + offset) = color;
}

void	toggle_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 5) == 0)
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
		handle_pixel_mandelbrot(x, y, fractal);
	else if (ft_strncmp(fractal->name, "julia", 5) == 0)
		handle_pixel_julia(x, y, fractal);
	else if (ft_strncmp(fractal->name, "burningship", 11) == 0)
	{
		perror("burningship is not implemented yet");
		exit(EXIT_FAILURE);
	}
	else
	{
		putstr_fd(ERROR_MASSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
