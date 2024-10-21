/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:55:23 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/21 15:19:51 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	wait_for_children(pid_t *pids)
{
	int	i;

	i = 0;
	while (i < NM_PROC * NM_PROC)
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}
}
