/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:31:02 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/28 06:39:54 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_pressed(int keycode, t_struct *data)
{
	if (keycode == A)
	{
		data->left = (M_PI * 0.5F) * (-1);
		data->walk_direction = 1;
	}
	if (keycode == D)
	{
		data->left = M_PI * 0.5F;
		data->walk_direction = 1;
	}
	if (keycode == W)
		data->walk_direction = 1;
	if (keycode == S)
		data->walk_direction = -1;
	if (keycode == RIGHT)
		data->turn_direction = 1;
	if (keycode == LEFT)
		data->turn_direction = -1;
	if (keycode == ESC)
	{
		destruct(data);
		ft_close(data);
	}
	return (TRUE);
}

int	key_released(int keycode, t_struct *data)
{
	if (keycode == W)
		data->walk_direction = 0;
	if (keycode == S)
		data->walk_direction = 0;
	if (keycode == RIGHT)
		data->turn_direction = 0;
	if (keycode == LEFT)
		data->turn_direction = 0;
	if (keycode == A)
	{
		data->left = 0;
		data->walk_direction = 0;
	}
	if (keycode == D)
	{
		data->left = 0;
		data->walk_direction = 0;
	}
	return (TRUE);
}

int	is_not_valid_xpm(t_struct *data)
{
	return (!data->xpm_ptr1 || !data->xpm_ptr2 || !data->xpm_ptr3
			|| !data->xpm_ptr4 || !data->sprite_xpm);
}
