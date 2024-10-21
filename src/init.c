/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:52:08 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/21 16:18:32 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * Function that handles the malloc problems
 * and exits the program
*/
static void	graceful_backoff(void)
{
	perror("Malloc problems");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_val = 4;
	fractal->max_iter = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress,
		KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress,
		ButtonPressMask, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify,
		StructureNotifyMask, close_handler, fractal);
}

/*
 * Function that initializes the fractal structure
 * 1. Initializes the connection to the X server
 * 2. Creates a window
 * 3. Creates an image
 * 4. Gets the image data
*/
void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (NULL == fractal->mlx)
		graceful_backoff();
	fractal->mlx_window = mlx_new_window(fractal->mlx,
			WIDTH, HEIGHT, fractal->name);
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		graceful_backoff();
	}
	fractal->img.img_pointer = mlx_new_image(fractal->mlx,
			WIDTH, HEIGHT);
	if (NULL == fractal->img.img_pointer)
	{
		mlx_destroy_window(fractal->mlx, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		graceful_backoff();
	}
	fractal->img.pixels_pointer = mlx_get_data_addr(fractal->img.img_pointer,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	data_init(fractal);
	events_init(fractal);
}
