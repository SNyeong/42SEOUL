/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:35:50 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/28 06:42:44 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_sprite_coordinates(t_struct *data, int *i_spt, int i, int j)
{
	data->sprite[*i_spt].x = ((float)j + 0.5f) * SQUARE_SIZE;
	data->sprite[*i_spt].y = ((float)i + 0.5f) * SQUARE_SIZE;
	(*i_spt)++;
}

void	set_sprite_distance(t_struct *data, int *i)
{
	while (*i < data->count_spt)
	{
		data->sprite[*i].dis = distance_between_points(data->x, data->y,
				data->sprite[*i].x, data->sprite[*i].y);
		(*i)++;
	}
}

float	calc_sprite_y_offset(t_struct *data, int i_spt)
{
	return ((float)data->w_height / 2 - data->sprite[i_spt].size / 2);
}

float	calc_sprite_x_offset(t_struct *data, int i_spt, float spt_angle)
{
	int w_width;

	w_width = data->w_width;
	return (((degree(spt_angle) - degree(data->rotation_angle)) * w_width)
			/ 60 + (((float)w_width / 2)
				- (data->sprite[i_spt].size / 2)));
}

int		not_valid_distance(const t_struct *data,
		float x_off, int index, size_t i)
{
	return (g_rays[(int)(x_off + i)].distance <= data->sprite[index].dis);
}
