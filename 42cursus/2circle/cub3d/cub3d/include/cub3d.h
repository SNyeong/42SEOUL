/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:56:35 by moboustt          #+#    #+#             */
/*   Updated: 2021/05/28 06:49:59 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libs/OpenGL/mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define PI 3.14159265359F

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define TRUE 1
# define FALSE 0

# define SQUARE_SIZE 1000
# define TEX_WIDTH SQUARE_SIZE
# define TEX_HEIGHT SQUARE_SIZE
# define SPRITE_SIZE 64

# define FOV_ANGLE 60

# define MAX_INT 2147483647

typedef struct			s_splash
{
	int					*spl_xpm;
	int					w;
	int					h;
	float				vratio;
	float				hratio;
	int					*img_data;
	int					bpp;
	int					sl;
	int					end;
	int					is_setup;
}						t_splash;

typedef struct			s_rgb
{
	int					r;
	int					g;
	int					b;
}						t_rgb;

typedef struct			s_bitmap
{
	unsigned int		bit_per_pxl;
	int					width_in_pxl;
	unsigned int		info_header_size;
	unsigned int		image_size;
	unsigned int		bf_off_bits;
	unsigned int		file_size;
	unsigned int		biplanes;
	unsigned char		*buf;
	int					fd;
	int					row;
	int					col;
}						t_bitmap;

typedef struct			s_sprite
{
	float				x;
	float				y;
	float				x_off;
	float				y_off;
	float				size;
	float				dis;
}						t_sprite;

typedef struct			s_ray
{
	float				ray_angle;
	float				wall_h_x;
	float				wall_h_y;
	float				distance;
	int					is_ray_facing_up;
	int					is_ray_facing_down;
	int					is_ray_facing_right;
	int					is_ray_facing_left;
	int					was_hit_vertical;
}						t_ray;

t_ray					*g_rays;

typedef struct			s_struct
{
	float				left;
	int					t;
	int					orientation;
	int					bpp;
	int					size_line;
	int					endian;
	int					bpp_text;
	int					size_line_text;
	int					endian_text;
	int					*img_tex1;
	int					*img_tex2;
	int					*img_tex3;
	int					*img_tex4;
	void				*xpm_ptr1;
	void				*xpm_ptr2;
	void				*xpm_ptr3;
	void				*xpm_ptr4;
	void				*mlx_ptr;
	void				*img_ptr;
	void				*win_ptr;
	int					*img_data_bmp;
	char				*img_data;
	float				move_step;
	float				updated_player_x;
	float				updated_player_y;
	float				x;
	float				y;
	int					turn_direction;
	int					walk_direction;
	float				rotation_angle;
	float				walk_speed;
	float				turn_speed;

	float				dx;
	float				dy;
	float				ray_angle;
	float				x_intercept;
	float				y_intercept;
	float				save_horiz_wall_hit_x;
	float				save_horiz_wall_hit_y;
	float				save_vert_wall_hit_x;
	float				save_vert_wall_hit_y;
	int					vert_wall_hit_content;
	float				horz_hit_distance;
	float				vert_hit_distance;
	int					is_ray_facing_down;
	int					is_ray_facing_up;
	int					is_ray_facing_right;
	int					is_ray_facing_left;

	float				corrected_dsitance;
	float				top_pixel;
	float				bottom_pixel;
	float				distance_to_projection_plane;
	float				wall_height;
	int					i_wall_index;
	int					txt_offset_x;
	int					txt_offset_y;

	float				vert_touch_x;
	float				vert_touch_y;
	float				horiz_touch_x;
	float				horiz_touch_y;
	int					m_height;

	float				x_horz_to_check;
	float				y_horz_to_check;
	float				x_vert_to_check;
	float				y_vert_to_check;

	void				*sprite_xpm;
	int					*sprite_tex_data;

	int					y_lines;
	int					*x_lines;
	int					pos;
	int					get_to_map;
	int					w_width;
	int					w_height;
	int					f_red;
	int					f_green;
	int					f_blue;
	int					c_red;
	int					c_green;
	int					c_blue;
	char				no[150];
	char				so[150];
	char				we[150];
	char				ea[150];
	char				sp[150];
	int					found_r;
	int					found_f;
	int					found_c;
	int					found_no;
	int					found_so;
	int					found_ea;
	int					found_we;
	int					found_sp;
	char				**map;
	int					i_player;
	int					j_player;
	int					is_multi_player;
	int					count_spt;
	int					save;
	t_sprite			*sprite;
	t_bitmap			bitmap;
	t_splash			splsh;

}						t_struct;

int						set_up_window(t_struct *data);
unsigned int			create_rgb(int r, int g, int b);
void					set_up_data(t_struct *data);
void					init_ray_cast_data(t_struct *data);
int						initialize_window(t_struct *data);
int						move_player(t_struct *data);
void					ft_draw(t_struct *data, int x, int y, int color);
int						if_wall(float x, float y, t_struct *data);
float					limit_angle(float angle);
float					distance_between_points(float x1, float y1,
		float x2, float y2);
void					horizontal_ray_intersection(float ray_angle,
		t_struct *data,
		int *found_horiz_wall_hit);
void					vertical_ray_intersection(float ray_angle,
		t_struct *data,
		int *found_vert_wall_hit);
void					cast_single_ray(int ray_id, float ray_angle,
		t_struct *data);
void					fill_out_ray(int ray_id, t_struct *data);
void					cast_rays(t_struct *data);
int						update(t_struct *data);
int						ft_close(void *param);
int						key_pressed(int keycode, t_struct *data);
int						key_released(int keycode, t_struct *data);
void					texture_from_file(t_struct *data);
void					render_walls(t_struct *data);
int						parse(t_struct *data, char *av);
void					initialize_file_struct(t_struct *data);
int						read_cub(t_struct *data, char *buff);
void					fill_out_map(t_struct *data, char *buff);
int						line_length(const char *line);
int						check_textures_f_c_s_availibility(char *buff, int last);
int						count_lines(const char *buff);

void					get_resolution_values(t_struct *data, char *buff);
void					get_floor_values(t_struct *data, char *buff);
void					get_ceilling_values(t_struct *data, char *buff);
void					get_texture_path(t_struct *data, const char *buff,
		int *found, char *txt);
void					get_north_texture_path(t_struct *data,
		const char *buff);
void					get_south_texture_path(t_struct *data,
		const char *buff);
void					get_western_texture_path(t_struct *data,
		const char *buff);
void					get_easter_texture_path(t_struct *data,
		const char *buff);
void					get_sprite_path(t_struct *data, char *buff);
int						skip_number(const char *str);
int						read_map(t_struct *data, char *buff);
void					initialize_sprite(t_struct *data);
void					set_up_sprite(t_struct *data);
void					draw_sprites(t_struct *data, float x_off, float y_off,
		int index);
void					init_player(t_struct *data);
void					set_up_player(t_struct *data);
int						is_sprite(char c);
int						is_player(t_struct *data, const char *buff);
int						calculate_index(float value);
int						is_not_valid_element(t_struct *data, const char *buff);
int						valid_index(t_struct *data, int x, int y);
int						screen(t_struct *data);
void					capture_window_data(t_struct *data, int x);
void					set_up_bmp_header(t_struct *data,
		unsigned char *header);
int						destruct(t_struct *data);
void					error(char *str);
t_rgb					*color_converter(int hex_value);
float					calculate_y_offset(const t_struct *data, int y);
int						calculate_x_offset(const t_struct *data);
void					draw_ceilling(t_struct *data, int ceilling);
void					draw_floor(t_struct *data, int floor);
void					draw_walls(t_struct *data, float y);
int						*which_texture(const t_struct *data);
void					ft_ljodran(t_struct *data, int y);
int						normalize_index(int index);
int						get_color_index(t_struct *data);
void					set_sprite_coordinates(t_struct *data, int *i_spt,
		int i, int j);
void					set_sprite_distance(t_struct *data, int *i);
float					calc_sprite_y_offset(t_struct *data, int i_spt);
float					calc_sprite_x_offset(t_struct *data, int i_spt,
		float spt_angle);
void					swap(t_struct *data, int j);
void					bubble_sort(t_struct *data);
int						get_color_id(int i, int j, int size);
void					normalize_sprite_angle(t_struct *data,
		float *spt_angle);
void					normalize_sprite_size(t_struct *data, int *i_spt);
int						is_not_valid_xpm(t_struct *data);
int						value_at(int i, int j, t_struct *data);
int						check_element(t_struct *data, int i, int j);
void					check_map(t_struct *data);
int						is_valid_texture(t_struct *data, const char *buff);
int						is_negative(int v);
int						is_valid_color(const t_struct *data, int id);
int						not_valid_x_offset(const t_struct *data,
		float x_off, size_t i);
int						not_valid_distance(const t_struct *data, float x_off,
		int index, size_t i);
int						not_valid_y_offset(const t_struct *data,
		float y_off, size_t j);
void					render_ui_bar(t_struct *data);
void					render_splash_screen(t_struct *data,
		char *splash_screen);
int						int_len(int x);
void					check_after_given_infos(t_struct *data,
		const char *buff);
void					not_valid_element(const t_struct *data,
		const char *buff);
int						ft_check_file(char *arg, char *str);
int						ft_check_save(char *arg, char *str);
float					degree(float radian);
float					radian(float degree);

#endif
