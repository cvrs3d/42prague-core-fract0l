/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:12:25 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/19 19:07:07 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// When zero strings are equal
int	ft_strncmp(char *s1, char *s2, int n)
{
	if (NULL == s1 || NULL == s2 || n <= 0)
		return (-1);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		n--;
	}
	return (*s1 - *s2);
}

// Recursive
void	putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

int	chsign(char **c)
{
	if (**c == '-')
	{
		(*c)++;
		return (-1);
	}
	else if (**c == '+')
	{
		(*c)++;
		return (1);
	}
	(*c)++;
	return (1);
}

double	atodbl(char *s)
{
	long	ipart;
	double	fract;
	double	pow;
	int		sign;

	ipart = 0;
	fract = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		sign = chsign(&s);
	while (*s != '.' && *s)
		ipart = (ipart * 10) + (*s++ - 48);
	if (*s == '.')
		++s;
	while (*s)
	{
		pow /= 10;
		fract = fract + (*s++ - 48) * pow;
	}
	return ((ipart + fract) * sign);
}
