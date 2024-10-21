/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:37:01 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/21 12:55:58 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_pixel_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = (scale(x, -2, +2) * fractal->zoom) + fractal->shift_x;
	z.y = (scale(y, +2, -2) * fractal->zoom) + fractal->shift_y;
	toggle_fractal(&z, &c, fractal);
	i = 0;
	while (i < fractal->max_iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_val)
		{
			color = compute_color(i, BLUE, NEON_ORANGE, fractal->max_iter);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
		my_pixel_put(x, y, &fractal->img, BLACK);
	}
}
