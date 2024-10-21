/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:52:24 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/21 13:41:52 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
* Function that scales the unscaled_num
* from the range 0 to WIDTH = 800
* to the new range from new_min to new_max
*/
double	scale(double unscaled_num, double new_min, double new_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (WIDTH - 0) + new_min);
}

/*
* Function that sums two complex numbers
*/
t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

/*
* Function that squares the complex number
* using the formula (a + bi)^2 = a^2 - b^2 + 2abi
* where a is the real part and b is the imaginary part
* resluting in a new complex number
*/
t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

/*
* Cube the complex number
* using the formula (a + bi)^3 = a^3 - 3ab^2 + 3a^2b - b^3
* where a is the real part and b is the imaginary part
* resulting in a new complex number
* i is omitted in the formula
* Using for the (p) = z^3 - 1 fractal
*/
t_complex	cube_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x * z.x) - (3 * (z.x * (z.y * z.y)));
	result.y = (3 * (z.y * (z.x * z.x))) - (z.y * z.y * z.y);
	return (result);
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
