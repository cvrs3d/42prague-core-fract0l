/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:24:35 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/19 17:28:31 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_pointer + offset) = color;
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = 0.0;
	z.y = 0.0;
	c.x = scale(x, -2, +2);
	c.y = scale(y, +2, -2);
	i = 0;
	while (i < fractal->max_iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_val)
		{
			color = compute_color(i, BLACK, WHITE, fractal->max_iter);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
		my_pixel_put(x, y, &fractal->img, AQUA_DREAM);
	}
}

/*
 * This function renders the fractal

 *    0_____________800x
 *    |_|_|_|_|_|_|_|
 *    |_|_|_|_|_|_|_|
 *    |_____________|800 y
 * 	  |_____________|
 *    |_____________|
*/
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
}
