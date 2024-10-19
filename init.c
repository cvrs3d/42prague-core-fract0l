/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:52:08 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/19 14:21:23 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	graceful_backoff(void)
{
	perror("Malloc problems");
	exit(EXIT_FAILURE);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		graceful_backoff();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		graceful_backoff();
	}
	fractal->img.img_pointer = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (NULL == fractal->img.img_pointer)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		graceful_backoff();
	}
	fractal->img.pixels_pointer = mlx_get_data_addr(fractal->img.img_pointer,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
}
