/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:52:35 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/19 13:12:02 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int acount, char **avalues)
{
	if (2 == acount && !ft_strncmp(avalues[1], "mandelbrot", 10)
		|| 4 == && !ft_strncmp(avalues[1], "julia", 5))
	{
	}
	else
	{
		putstring_fd(ERROR_MASSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
