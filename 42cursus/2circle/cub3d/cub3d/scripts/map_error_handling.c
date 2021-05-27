/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 08:32:31 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/28 06:39:42 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		valid_index(t_struct *data, int x, int y)
{
	if (y >= data->y_lines || y < 0)
		return (FALSE);
	if (x >= data->x_lines[y] || x < 0)
		return (FALSE);
	return (TRUE);
}

int		value_at(int i, int j, t_struct *data)
{
	if (valid_index(data, j, i))
		return (data->map[i][j]);
	return (' ');
}

int		check_element(t_struct *data, int i, int j)
{
	int x;
	int z;

	x = -1;
	while (x <= 1)
	{
		z = -1;
		while (z <= 1)
		{
			if (value_at(i + x, j + z, data) == ' ')
				return (FALSE);
			z++;
		}
		x++;
	}
	return (TRUE);
}

void	check_map(t_struct *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->y_lines)
	{
		j = -1;
		while (++j < data->x_lines[i])
		{
			if (!(data->map[i][j] == '1' || data->map[i][j] == ' ')
					&& !check_element(data, i, j))
				error("\e[0;31m map isn't surrounded by wall!\n");
		}
	}
}
