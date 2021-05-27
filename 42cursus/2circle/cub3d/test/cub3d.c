/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:48:57 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/26 09:36:30 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw(t_all *s)
{
	t_ray	ray;
	t_hit	hit;

	ray.x = 0;
	ray.y = 0;
	ray.i = 0;
	ray.v = 0;
	ray.w = 0;
	hit.x = 0;
	hit.y = 0;
	hit.d = 0;
	s->ray = ray;
	s->hit = hit;
	ft_screen(s);
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	free(s->img.ptr);
	free(s->img.adr);
}

void	ft_cub3d(t_all s, char *cub, int save)
{
	t_pos	pos;
	t_dir	dir;

	pos.x = 0;
	pos.y = 0;
	dir.x = 0;
	dir.y = 0;
	s.pos = pos;
	s.dir = dir;
	s.mlx.ptr = mlx_init();
	if (ft_parse(&s, cub) == -1)
		ft_close(&s, 0);
	if (save == 1)
		ft_bitmap(&s);
	s.win.ptr = mlx_new_window(s.mlx.ptr, s.win.x, s.win.y, "cub3D");
	ft_draw(&s);
	mlx_hook(s.win.ptr, 2, 0, ft_key, &s);
	mlx_hook(s.win.ptr, 17, 0, ft_close, &s);
	mlx_loop(s.mlx.ptr);
}

void	ft_init_1(t_all s, char *cub, int save)
{
	t_map	map;
	t_tex	tex;
	t_spr	*spr;
	t_stk	*stk;

	map.tab = NULL;
	tex.n = NULL;
	tex.s = NULL;
	tex.e = NULL;
	tex.w = NULL;
	tex.i = NULL;
	spr = NULL;
	stk = NULL;
	map.x = 0;
	map.y = 0;
	map.spr = 0;
	tex.c = NONE;
	tex.f = NONE;
	s.map = map;
	s.tex = tex;
	s.spr = spr;
	s.stk = stk;
	ft_cub3d(s, cub, save);
}

void	ft_init_0(char *cub, int save)
{
	t_all	s;
	t_mlx	mlx;
	t_win	win;
	t_img	img;
	t_err	err;

	mlx.ptr = NULL;
	win.ptr = NULL;
	img.ptr = NULL;
	img.adr = NULL;
	win.x = 0;
	win.y = 0;
	img.fsh = 0;
	err.n = 0;
	err.m = 0;
	err.p = 0;
	s.mlx = mlx;
	s.win = win;
	s.img = img;
	s.err = err;
	ft_init_1(s, cub, save);
}

int		main(int c, char **v)
{
	if (c == 3 && ft_check_file(v[1], "cub") && ft_check_save(v[2], "--save"))
		ft_init_0(v[1], 1);
	else if (c == 2 && ft_check_file(v[1], "cub"))
		ft_init_0(v[1], 0);
	else
		write(2, "Error : Invalid arguments\n", 26);
	return (0);
}
