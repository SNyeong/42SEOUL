/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 05:52:02 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/28 06:58:32 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		update(t_struct *data)
{
	cast_rays(data);
	render_walls(data);
	if (data->save)
	{
		screen(data);
		destruct(data);
	}
	move_player(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_ptr, 0, 0);
	return (FALSE);
}

int		initialize_window(t_struct *data)
{
	set_up_data(data);
	if (!(set_up_window(data)))
		return (FALSE);
	texture_from_file(data);
	mlx_hook(data->win_ptr, 2, 0, key_pressed, data);
	mlx_hook(data->win_ptr, 3, 0, key_released, data);
	mlx_hook(data->win_ptr, 17, 0, destruct, data);
	mlx_loop_hook(data->mlx_ptr, update, data);
	mlx_loop(data->mlx_ptr);
	return (TRUE);
}

int		ft_init(char *av, int save)
{
	t_struct	*data;

	data = malloc(sizeof(t_struct));
	data->save = save;
	initialize_file_struct(data);
	if (!parse(data, av))
		return (1);
	g_rays = (t_ray *)malloc(sizeof(t_ray) * data->w_width);
	if (!initialize_window(data))
		return (TRUE);
	free(data);
	return (FALSE);
}

int		main(int ac, char **av)
{
	if (ac == 3 && ft_check_file(av[1], "cub") &&
		ft_check_save(av[2], "--save"))
		ft_init(av[1], 1);
	else if (ac == 2 && ft_check_file(av[1], "cub"))
		ft_init(av[1], 0);
	else
		error("\e[0;31mError : Invalid arguments\n");
	return (0);
}
