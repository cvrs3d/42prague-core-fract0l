/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:52:35 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/19 19:45:59 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int acount, char **avalues)
{
	t_fractal	fract;

	if (2 == acount && !ft_strncmp(avalues[1], "mandelbrot", 10)
		|| 4 == acount && !ft_strncmp(avalues[1], "julia", 5))
	{
		fract.name = avalues[1];
		if (!ft_strncmp(avalues[1], "julia", 5))
		{
			fract.julia_x = atodbl(avalues[2]);
			fract.julia_y = atodbl(avalues[3]);
		}
		fractal_init(&fract);
		fractal_render(&fract);
		mlx_loop(fract.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MASSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
