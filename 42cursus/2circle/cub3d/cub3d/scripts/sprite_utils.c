/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:35:35 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/28 06:39:17 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	swap(t_struct *data, int j)
{
	t_sprite	tmp;

	tmp = data->sprite[j];
	data->sprite[j] = data->sprite[j + 1];
	data->sprite[j + 1] = tmp;
}

void	bubble_sort(t_struct *data)
{
	int			i;
	int			j;

	i = -1;
	while (++i < data->count_spt)
	{
		j = -1;
		while (++j < data->count_spt - i && j + 1 < data->count_spt)
			if (data->sprite[j].dis < data->sprite[j + 1].dis)
				swap(data, j);
	}
}

int		get_color_id(int i, int j, int size)
{
	int			id;
	const int	e = SPRITE_SIZE * SPRITE_SIZE;

	id = SPRITE_SIZE * (SPRITE_SIZE * j / size)
		+ (SPRITE_SIZE * i / size);
	id = id >= (e) ? (e - 1) : id;
	return (id);
}

void	normalize_sprite_angle(t_struct *data, float *spt_angle)
{
	while (*spt_angle - data->rotation_angle > M_PI)
		*spt_angle -= 2 * M_PI;
	while (*spt_angle - data->rotation_angle < -M_PI)
		*spt_angle += 2 * M_PI;
}

void	normalize_sprite_size(t_struct *data, int *i_spt)
{
	data->sprite[*i_spt].size = ((float)data->w_width
			/ data->sprite[*i_spt].dis) * SQUARE_SIZE;
}
