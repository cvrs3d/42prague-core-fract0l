/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:52:40 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/19 17:21:01 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	compute_color(int unscaled_num, int new_min, int new_max, int max_i)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (max_i - 0) + new_min);
}
/*
#include <stdio.h>

void print_colored_text(int color, const char *text)
{
	printf("\033[38;2;%d;%d;%dm%s\033[0m\n",
		(color >> 16) & 0xFF,
		(color >> 8) & 0xFF,
		color & 0xFF,
		text);
}

int	main(void)
{
	for (int i = 0; i < 42; i++)
	{
		int color = compute_color(i, 0x000000, 0xFFFFFF, 42);
		char text[50];
		sprintf(text, "Iteration %d, color #%06x", i, color);
		print_colored_text(color, text);
	}

	return 0;
}
*/
