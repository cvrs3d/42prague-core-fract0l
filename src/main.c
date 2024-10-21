/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:52:35 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/21 16:17:51 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	start_mandelbrot(t_fractal *fract, char **avalues)
{
	fract->name = avalues[1];
	fractal_init(fract);
	fractal_render(fract);
	mlx_loop(fract->mlx);
}

static void	start_julia(t_fractal *fract, char **avalues)
{
	fract->name = avalues[1];
	if (is_garbage(avalues[2]) || is_garbage(avalues[3]))
	{
		putstr_fd(ERROR_MASSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fract->julia_x = atodbl(avalues[2]);
	fract->julia_y = atodbl(avalues[3]);
	fractal_init(fract);
	fractal_render(fract);
	mlx_loop(fract->mlx);
}

static void	start_cubic(t_fractal *fract, char **avalues)
{
	fract->name = avalues[1];
	fractal_init(fract);
	fractal_render(fract);
	mlx_loop(fract->mlx);
}

int	main(int acount, char **avalues)
{
	t_fractal	fract;

	if (2 == acount && !ft_strncmp(avalues[1], "mandelbrot", 10))
	{
		start_mandelbrot(&fract, avalues);
	}
	else if (4 == acount && !ft_strncmp(avalues[1], "julia", 5))
	{
		start_julia(&fract, avalues);
	}
	else if (2 == acount && !ft_strncmp(avalues[1], "cubic", 5))
	{
		start_cubic(&fract, avalues);
	}
	else
	{
		putstr_fd(ERROR_MASSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
