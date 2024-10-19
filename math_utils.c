/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:52:24 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/19 15:24:53 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double unscaled_num, double new_min, double new_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (800 - 0) + new_min);
}
/*
*	Test:
* 	>>> 0 --> -2.00000
....
....
	>>> 800 --> 2.0000
#include <stdio.h>
int	main(void)
{
	for (int i = 0; i <= 800; i++)
	{
		printf("%d --> %f\n", i, scale((double)i, -2, 2));
	}
}
*/
