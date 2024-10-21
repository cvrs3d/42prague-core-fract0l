/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:45:28 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/21 15:12:34 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
* Function prototyped like this
* int (f*)(void* param);
*/
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img_pointer);
	mlx_destroy_window(fractal->mlx, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}

/*
* Function prototyped like
* int (*f)(int keykode, void *param)
*/
int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_plus || keysym == XK_equal)
		fractal->max_iter += 10;
	else if (keysym == XK_minus || keysym == XK_underscore)
		fractal->max_iter -= 10;
	fractal_render(fractal);
	return (0);
}

/*
* Function prototyped like this
* int (f*)(int button, int x, int y, void* param);
*/
int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	int	tmp;

	tmp = x + y;
	if (button == Button5)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	tmp = 0;
	return (tmp);
}

/*
* Function prototyped like this
* int (f*)(int x, int y, void* param);
*/
int	mouse_track(int x, int y, t_fractal *fractal)
{
	static int	prev_x = -1;
	static int	prev_y = -1;

	if (prev_x != -1 && prev_y != -1)
	{
		fractal->shift_x += (x - prev_x) * fractal->zoom * 0.001;
		fractal->shift_y -= (y - prev_y) * fractal->zoom * 0.001;
	}
	prev_x = x;
	prev_y = y;
	return (0);
}
