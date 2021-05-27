/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:37:13 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/28 06:37:36 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	limit_angle(float angle)
{
	angle = remainderf(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (hypotf((x2 - x1), (y2 - y1)));
}

int		calculate_index(float value)
{
	return (floorf((value / SQUARE_SIZE)));
}

int		get_color_index(t_struct *data)
{
	return ((TEX_WIDTH * data->txt_offset_y) + data->txt_offset_x);
}

int		normalize_index(int index)
{
	static const int tex_space = TEX_HEIGHT * TEX_WIDTH;

	index = index <= 0 ? 0 : index;
	return (index >= (tex_space) ? (tex_space - 1) : index);
}
