/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 18:07:43 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/28 06:39:06 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		skip_number(const char *str)
{
	int i;

	i = 0;
	if (str[i] == ',' || str[i] == ' ')
		i++;
	while ((str[i] >= 48 && str[i] <= 57) && (str[i] != ' ' || str[i] != ','))
		i++;
	return (i);
}

void	error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

int		is_valid_color(const t_struct *data, int id)
{
	return (data->sprite_tex_data[id] != data->sprite_tex_data[0]);
}

int		int_len(int x)
{
	int len;

	len = 1;
	while (x / 10)
	{
		x /= 10;
		++len;
	}
	return (len);
}
