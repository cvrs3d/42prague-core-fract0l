/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:12:25 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/19 13:18:46 by yustinov         ###   ########.fr       */
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
