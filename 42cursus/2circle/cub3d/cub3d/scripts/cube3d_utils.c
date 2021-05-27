/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:30:23 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/28 06:40:00 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		is_not_valid_element(t_struct *data, const char *buff)
{
	return (buff[data->pos] != '1' && buff[data->pos] != '0'
		&& buff[data->pos] != '2' && buff[data->pos] != 'N'
		&& buff[data->pos] != 'W' && buff[data->pos] != 'E'
		&& buff[data->pos] != 'S' && buff[data->pos] != ' ');
}

int		is_player(t_struct *data, const char *buff)
{
	return (buff[data->pos] == 'N' || buff[data->pos] == 'W'
		|| buff[data->pos] == 'E' || buff[data->pos] == 'S');
}

int		is_sprite(char c)
{
	return (c == '2');
}

int		if_wall(float x, float y, t_struct *data)
{
	int map_index_x;
	int map_index_y;

	map_index_x = calculate_index(x);
	map_index_y = calculate_index(y);
	if (!valid_index(data, map_index_x, map_index_y))
		return (TRUE);
	if (((int)y < 0 || (int)y > data->m_height)
			|| (map_index_y > data->y_lines))
		return (TRUE);
	return (data->map[map_index_y][map_index_x] == ' '
			|| data->map[map_index_y][map_index_x] == '1');
}
