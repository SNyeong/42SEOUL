/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:30:40 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/28 11:51:26 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_close(void *param)
{
	(void)param;
	exit(0);
}

int	destruct(t_struct *data)
{
	int i;

	i = 0;
	if (data->sprite)
		free(data->sprite);
	if (data->map[0])
	{
		while (i < data->y_lines - 1)
		{
			free(data->map[i]);
			i++;
		}
	}
	if (data)
		free(data);
	if (g_rays)
		free(g_rays);
	ft_close(0);
	return (0);
}
