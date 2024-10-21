/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelcube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:14:13 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/21 16:19:15 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_pixel_cubic(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	c.x = (x - WIDTH / 2.0) * 4.0 / WIDTH / fractal->zoom + fractal->shift_x;
	c.y = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / fractal->zoom + fractal->shift_y;
	z.x = 0;
	z.y = 0;
	i = 0;
	while (i < fractal->max_iter
		&& (z.x * z.x + z.y * z.y) < fractal->escape_val)
	{
		z = sum_complex(cube_complex(z), c);
		++i;
	}
	if ((z.x * z.x + z.y * z.y) >= fractal->escape_val)
	{
		color = compute_color(i, BLUE, NEON_ORANGE, fractal->max_iter);
		my_pixel_put(x, y, &fractal->img, color);
	}
	else
	{
		my_pixel_put(x, y, &fractal->img, BLACK);
	}
}
