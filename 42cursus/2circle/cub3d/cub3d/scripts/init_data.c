/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 06:31:35 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/28 06:45:38 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_up_data(t_struct *data)
{
	data->m_height = data->y_lines * SQUARE_SIZE;
	data->bpp = 0;
	data->endian = 0;
	data->size_line = 1;
	data->mlx_ptr = NULL;
	data->img_ptr = NULL;
	data->win_ptr = NULL;
	data->img_data = NULL;
	data->move_step = 0;
	data->updated_player_x = 0;
	data->updated_player_y = 0;
	data->turn_direction = 0;
	data->walk_direction = 0;
	data->walk_speed = 125;
	data->turn_speed = 4 * (PI / 180);
	data->t = 1;
	data->left = 0;
	data->splsh.is_setup = 0;
	init_ray_cast_data(data);
}

void	init_ray_cast_data(t_struct *data)
{
	data->is_ray_facing_down = 0;
	data->is_ray_facing_up = 0;
	data->is_ray_facing_right = 0;
	data->is_ray_facing_left = 0;
	data->dx = 0;
	data->dy = 0;
	data->x_intercept = 0;
	data->y_intercept = 0;
	data->save_horiz_wall_hit_x = 0;
	data->save_horiz_wall_hit_y = 0;
	data->save_vert_wall_hit_x = 0;
	data->save_vert_wall_hit_y = 0;
	data->vert_wall_hit_content = FALSE;
	data->horz_hit_distance = 0;
	data->vert_hit_distance = 0;
	data->corrected_dsitance = 0;
	data->top_pixel = 0;
	data->bottom_pixel = 0;
	data->distance_to_projection_plane = 0;
	data->wall_height = 0;
	initialize_sprite(data);
}

void	set_up_player(t_struct *data)
{
	data->orientation = (unsigned char)data->map[data->i_player]
		[data->j_player];
	if (data->orientation == 'N')
		data->rotation_angle = radian((float)270);
	else if (data->orientation == 'W')
		data->rotation_angle = radian((float)180);
	else if (data->orientation == 'S')
		data->rotation_angle = radian((float)90);
	else if (data->orientation == 'E')
		data->rotation_angle = radian((float)0);
}

void	init_player(t_struct *data)
{
	data->x = (data->j_player + 0.5) * SQUARE_SIZE;
	data->y = (data->i_player + 0.5) * SQUARE_SIZE;
	set_up_player(data);
}

int		set_up_window(t_struct *data)
{
	if ((data->mlx_ptr = mlx_init()) == NULL)
		return (FALSE);
	if ((data->win_ptr = mlx_new_window(data->mlx_ptr,
					data->w_width, data->w_height, "cub3d")) == NULL)
		return (FALSE);
	if ((data->img_ptr = mlx_new_image(data->mlx_ptr,
					data->w_width, data->w_height)) == NULL)
		return (FALSE);
	if ((data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp,
					&data->size_line, &data->endian)) == NULL)
		return (FALSE);
	data->img_data_bmp = (int *)mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->size_line, &data->endian);
	return (TRUE);
}
