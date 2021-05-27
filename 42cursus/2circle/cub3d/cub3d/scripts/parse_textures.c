/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 09:34:00 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/28 06:39:28 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_texture_path(t_struct *data, const char *buff,
		int *found, char *txt)
{
	int i;

	i = 0;
	if (*found)
		error("\e[0;31m duplicate texture symbol\n");
	data->pos += 2;
	if (!is_valid_texture(data, buff))
		error("\e[0;31m Invalid texture path!\n");
	while (buff[(data->pos)] != '\n')
	{
		txt[i] = buff[(data->pos)];
		i++;
		(data->pos)++;
	}
	data->get_to_map += 1;
	*found = 1;
}

void	get_sprite_path(t_struct *data, char *buff)
{
	int i;

	i = 0;
	if (data->found_sp)
		error("\e[0;31m duplicate sprite texture symbol\n");
	data->pos += 1;
	if (!is_valid_texture(data, buff))
		error("\e[0;31m Invalid texture path!\n");
	while (buff[(data->pos)] != '\n')
	{
		data->sp[i] = buff[data->pos];
		i++;
		data->pos++;
	}
	data->get_to_map += 1;
	data->found_sp = 1;
}
