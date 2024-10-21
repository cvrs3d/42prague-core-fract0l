/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleprocessing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:08:29 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/21 15:11:23 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_window,
		fractal->img.img_pointer, 0, 0);
}
