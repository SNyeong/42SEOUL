/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 05:38:41 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/28 06:49:54 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		texture_from_file(t_struct *data)
{
	int w;
	int h;

	data->xpm_ptr1 = mlx_xpm_file_to_image(data->mlx_ptr, data->no, &w, &h);
	data->xpm_ptr2 = mlx_xpm_file_to_image(data->mlx_ptr, data->so, &w, &h);
	data->xpm_ptr3 = mlx_xpm_file_to_image(data->mlx_ptr, data->we, &w, &h);
	data->xpm_ptr4 = mlx_xpm_file_to_image(data->mlx_ptr, data->ea, &w, &h);
	data->sprite_xpm = mlx_xpm_file_to_image(data->mlx_ptr, data->sp, &w, &h);
	if (is_not_valid_xpm(data))
		error("\e[0;31m Error : wrong texture path!\n");
	data->img_tex1 = (int *)mlx_get_data_addr(data->xpm_ptr1,
			&data->bpp_text, &data->size_line_text, &data->endian_text);
	data->img_tex2 = (int *)mlx_get_data_addr(data->xpm_ptr2,
			&data->bpp_text, &data->size_line_text, &data->endian_text);
	data->img_tex3 = (int *)mlx_get_data_addr(data->xpm_ptr3,
			&data->bpp_text, &data->size_line_text, &data->endian_text);
	data->img_tex4 = (int *)mlx_get_data_addr(data->xpm_ptr4,
			&data->bpp_text, &data->size_line_text, &data->endian_text);
	data->sprite_tex_data = (int *)mlx_get_data_addr(data->sprite_xpm,
			&data->bpp_text, &data->size_line_text, &data->endian_text);
}

void		calculate_wall_projection(t_struct *data)
{
	data->corrected_dsitance = g_rays[data->i_wall_index].distance *
		cosf(g_rays[data->i_wall_index].ray_angle - data->rotation_angle);
	data->distance_to_projection_plane = ((float)data->w_width / 2)
		/ tanf(radian(FOV_ANGLE) / 2);
	data->wall_height = (SQUARE_SIZE / data->corrected_dsitance) *
		data->distance_to_projection_plane;
	data->top_pixel = ((float)data->w_height / 2) - (data->wall_height / 2);
	data->top_pixel = data->top_pixel < 0 ? 0 : data->top_pixel;
	data->bottom_pixel = ((float)data->w_height / 2) + (data->wall_height / 2);
	data->bottom_pixel = data->bottom_pixel > (float)data->w_height
		? (float)data->w_height
		: data->bottom_pixel;
}

void		ft_ljodran(t_struct *data, int y)
{
	int *which_text;
	int index;

	data->txt_offset_y = (int)calculate_y_offset(data, y);
	which_text = which_texture(data);
	index = normalize_index(get_color_index(data));
	ft_draw(data, data->i_wall_index, y, (int)which_text[index]);
}

void		render_walls(t_struct *data)
{
	int		ceilling;
	int		floor;
	float	y;

	data->i_wall_index = 0;
	if (data->save)
		texture_from_file(data);
	while (data->i_wall_index++ < data->w_width - 1)
	{
		ceilling = 0;
		y = data->top_pixel;
		data->txt_offset_x = calculate_x_offset(data);
		calculate_wall_projection(data);
		draw_ceilling(data, ceilling);
		draw_walls(data, y);
		floor = (int)data->bottom_pixel;
		draw_floor(data, floor);
	}
	set_up_sprite(data);
}

int			calculate_x_offset(const t_struct *data)
{
	return ((g_rays[data->i_wall_index].was_hit_vertical)
			? ((int)g_rays[data->i_wall_index].wall_h_y % SQUARE_SIZE)
			: ((int)g_rays[data->i_wall_index].wall_h_x % SQUARE_SIZE));
}
