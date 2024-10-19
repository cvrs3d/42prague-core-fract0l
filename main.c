/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:52:35 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/19 14:23:39 by yustinov         ###   ########.fr       */
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
