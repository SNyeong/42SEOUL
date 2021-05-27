/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 15:14:09 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/28 06:39:11 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_sprites(t_struct *data, float x_off,
		float y_off, int index)
{
	size_t		i;
	size_t		j;
	size_t		size;
	int			id;

	i = 0;
	size = data->sprite[index].size;
	while (i++ < size)
	{
		if (not_valid_x_offset(data, x_off, i))
			continue;
		if (not_valid_distance(data, x_off, index, i))
			continue;
		j = 0;
		while (j++ < size)
		{
			if (not_valid_y_offset(data, y_off, j))
				continue;
			id = get_color_id(i, j, size);
			if (is_valid_color(data, id))
				ft_draw(data, x_off + i, y_off + j,
						data->sprite_tex_data[id]);
		}
	}
}

int		not_valid_y_offset(const t_struct *data, float y_off, size_t j)
{
	return (y_off + j < 0 || y_off + j > (float)data->w_height);
}

int		not_valid_x_offset(const t_struct *data, float x_off, size_t i)
{
	return (x_off + i < 0 || x_off + i > (float)data->w_width);
}

void	set_up_sprite(t_struct *data)
{
	float	spt_angle;
	int		i_spt;
	int		i;

	i = 0;
	i_spt = 0;
	set_sprite_distance(data, &i);
	bubble_sort(data);
	while (i_spt < data->count_spt)
	{
		spt_angle = atan2f(data->sprite[i_spt].y - data->y,
				data->sprite[i_spt].x - data->x);
		normalize_sprite_angle(data, &spt_angle);
		normalize_sprite_size(data, &i_spt);
		data->sprite[i_spt].y_off = calc_sprite_y_offset(data, i_spt);
		data->sprite[i_spt].x_off = calc_sprite_x_offset(data, i_spt,
				spt_angle);
		draw_sprites(data, data->sprite[i_spt].x_off,
				data->sprite[i_spt].y_off, i_spt);
		i_spt++;
	}
}

void	initialize_sprite(t_struct *data)
{
	int i;
	int j;
	int i_spt;

	i = -1;
	i_spt = 0;
	if (data->count_spt < 0)
		error("\e[0;31m sprite error");
	if (!(data->sprite = (t_sprite *)malloc(sizeof(t_sprite)
					* (data->count_spt))))
		return ;
	while (++i < data->y_lines)
	{
		j = -1;
		while (++j < data->x_lines[i])
			if (is_sprite(data->map[i][j]))
				set_sprite_coordinates(data, &i_spt, i, j);
	}
}
