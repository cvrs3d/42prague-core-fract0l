/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiprocessing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:49:43 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/21 15:19:48 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	render_chunk(t_thread chunk, t_fractal *fractal)
{
	int	x;
	int	y;

	y = chunk.start_y;
	while (y < chunk.end_y)
	{
		x = chunk.start_x;
		while (x < chunk.end_x)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
}

static void	init_chunck(t_thread *chunk, int i, int j)
{
	chunk->start_x = i * chunk->chunk_size_x;
	chunk->end_x = (i + 1) * chunk->chunk_size_x;
	chunk->start_y = j * chunk->chunk_size_y;
	chunk->end_y = (j + 1) * chunk->chunk_size_y;
}

static void	chunck_set_size(t_thread *chunk, int i, int j)
{
	chunk->num_processes = NM_PROC;
	chunk->chunk_size_x = WIDTH / i;
	chunk->chunk_size_y = HEIGHT / j;
}

static void	init_vars(int *i, int *j, int *k)
{
	*i = -1;
	*k = 0;
	*j = -1;
}

void	fractal_render(t_fractal *f)
{
	t_thread	chunk;
	pid_t		pids[NM_PROC * NM_PROC];
	int			i;
	int			j;
	int			k;

	chunck_set_size(&chunk, NM_PROC, NM_PROC);
	init_vars(&i, &j, &k);
	while (++i < NM_PROC)
	{
		j = -1;
		while (++j < NM_PROC)
		{
			init_chunck(&chunk, i, j);
			pids[k] = fork();
			if (pids[k] == 0)
			{
				render_chunk(chunk, f);
				exit(0);
			}
			k++;
		}
	}
	wait_for_children(pids);
	mlx_put_image_to_window(f->mlx, f->mlx_window, f->img.img_pointer, 0, 0);
}
