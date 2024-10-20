/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiprocessing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:49:43 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/20 14:53:24 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void render_chunk(int start_x, int end_x, int start_y, int end_y, t_fractal *fractal)
{
	int x, y;
	for (y = start_y; y < end_y; y++)
	{
		for (x = start_x; x < end_x; x++)
		{
			handle_pixel(x, y, fractal);
		}
	}
}

void fractal_render(t_fractal *fractal)
{
	int num_processes = NM_PROC;
	int chunk_size_x = WIDTH / num_processes;
	int chunk_size_y = HEIGHT / num_processes;
	pid_t pids[num_processes * num_processes];
	int i, j, k = 0;

	for (i = 0; i < num_processes; i++)
	{
		for (j = 0; j < num_processes; j++)
		{
			int start_x = i * chunk_size_x;
			int end_x = (i + 1) * chunk_size_x;
			int start_y = j * chunk_size_y;
			int end_y = (j + 1) * chunk_size_y;

			if ((pids[k] = fork()) == 0)
			{
				render_chunk(start_x, end_x, start_y, end_y, fractal);
				exit(0);
			}
			++k;
		}
	}

	for (i = 0; i < num_processes * num_processes; ++i)
	{
		if (waitpid(pids[i], NULL, 0) < 0)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_pointer, 0, 0);
}
