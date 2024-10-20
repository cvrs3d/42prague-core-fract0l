/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:45:28 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/20 15:18:55 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
* Function prototyped like this
* int (f*)(void* param);
*/
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_pointer);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
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
	if (ft_strncmp(fractal->name, "julia", 5) == 0)
	{
		fractal->julia_x = scale(x, -2, +2) * fractal->zoom
			+ fractal->shift_x;
		fractal->julia_y = scale(y, +2, -2) * fractal->zoom
			+ fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
