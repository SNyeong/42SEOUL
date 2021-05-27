/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 07:34:43 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/28 06:39:22 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int				move_player(t_struct *data)
{
	int x;
	int y;

	data->rotation_angle += (float)data->turn_direction * data->turn_speed;
	data->move_step = (float)data->walk_direction * data->walk_speed;
	data->updated_player_x = data->x + cosf(data->rotation_angle + data->left)
		* data->move_step;
	data->updated_player_y = data->y + sinf(data->rotation_angle + data->left)
		* data->move_step;
	x = calculate_index(data->updated_player_x);
	y = calculate_index(data->updated_player_y);
	if (!valid_index(data, x, y))
		return (FALSE);
	if (!if_wall(data->updated_player_x, data->updated_player_y, data)
			&& !is_sprite(data->map[y][x]))
	{
		data->x = data->updated_player_x;
		data->y = data->updated_player_y;
	}
	return (TRUE);
}

void			ft_draw(t_struct *data, int x, int y, int color)
{
	char *dst;

	data->img_data_bmp[y * data->w_width + x] = (unsigned int)color;
	dst = data->img_data + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

t_rgb			*color_converter(int hex_value)
{
	t_rgb *rgb_color;

	rgb_color = malloc(sizeof(t_rgb));
	rgb_color->r = (hex_value / pow(2, 16));
	rgb_color->g = (hex_value / pow(2, 8));
	rgb_color->b = (hex_value);
	return (rgb_color);
}

unsigned int	create_rgb(int r, int g, int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}
