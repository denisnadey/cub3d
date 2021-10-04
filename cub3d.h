/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:50:45 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/16 12:19:51 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "ultralibx/ft_printf.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# define SCALE 10
# define ESC 53
# define W 13
# define A 0
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define SPEED 15
# define ROTATESPEED 0.05
# define M_PI_10 0.08
# define SCORE 0.2
# define UDIV 1;
# define VDIV 1;
# define VMOVE 0.0;

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				texture;
	double			dstpr;
	int				order;
}					t_sprite;

typedef struct		s_forsprite
{
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprtscren_x;
	int				movescrn;
	int				spriteheight;
	int				spritewidth;
	int				draw_start_y;
	int				draw_start_x;
	int				drawend_y;
	int				drawendx;
	int				stripe;
	double			sprite_x;
	double			sprite_y;
}					t_forsprite;

typedef struct		s_data
{
	void			*img;
	char			*addr;
	void			*mlx;
	void			*mlx_win;
	int				bppx;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_plr
{
	double			x;
	double			y;
	double			dir;
	double			start;
	double			end;
}					t_plr;

typedef struct		s_color_texture
{
	char			*no_path_texture;
	char			*so_path_texture;
	char			*we_path_texture;
	char			*ea_path_texture;
	char			*sprite_path;
	int				rgb_f_r;
	int				rgb_f_g;
	int				rgb_f_b;
	int				rgb_s_r;
	int				rgb_s_g;
	int				rgb_s_b;
}					t_color_texture;

typedef struct		s_window_setting
{
	int				width;
	int				height;
	int				realwidth;
	int				realheight;
	char			**map;
	int				len_y_map;
	int				len_x_map;
}					t_win_setting;

typedef struct		s_tex
{
	void			*img;
	char			*addr;
	int				bppx;
	int				img_h;
	int				img_w;
	int				endian;
	int				line_length;
	double			draw_start_y;
}					t_tex;

typedef struct		s_wasd
{
	unsigned		w:1;
	unsigned		a:1;
	unsigned		s:1;
	unsigned		d:1;
	unsigned		l:1;
	unsigned		r:1;
}					t_wasd;

typedef struct		s_setting
{
	double			pos_x;
	double			pos_y;
	double			olddir_x;
	double			olddir_y;
	double			oldplane_x;
	double			oldplane_y;
	double			dir_x;
	double			dir_y;
	double			cam_x;
	double			raydir_x;
	double			raydir_y;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				side;
	double			sky_start;
	double			sky_finish;
	int				lineheight;
	double			wall_start;
	double			wall_finish;
	double			floor_start;
	double			floor_finish;
	int				pos_vector;
	double			plane_x;
	double			plane_y;
	int				texx;
	double			texy;
	double			wallx;
	double			coff;
	double			*zbuffer;
	unsigned int	save;
	int				map_x;
	int				map_y;
	t_color_texture	*color;
	t_win_setting	*wnw;
	t_data			*s_data;
	t_plr			*plr;
	t_tex			tex[5];
	t_sprite		*sprite;
	t_forsprite		*fsp;
	t_wasd			*wasd;
}					t_setting;

void				render_sprt(t_setting *all);
int					struct_setting_parser(int fd, t_setting *all);
void				mlx_pxl_put(t_data *all, int x, int y, int color);
void				zero_struct(t_setting *all);
void				ft_parse_map(int fd, char *line, t_setting *all);
void				draw_screen(t_setting *all);
void				fn_paint_map(double x, double y, t_setting *all, \
					int color);
void				count_comma(char *str);
int					len_y_map(char **map);
int					len_x_map(char **map);
int					pos_ask(char c);
void				w_to(t_setting *all);
void				a_to(t_setting *all);
void				d_to(t_setting *all);
void				s_to(t_setting *all);
void				l_to(t_setting *all);
void				r_to(t_setting *all);
int					check_file_ext(char *str);
char				*make_dir_char(int tmp);
int					test_struct(t_setting *all);
unsigned long		torgb(int r, int g, int b);
void				get_vector_num(char c, t_setting *all);
void				alloc_mem_texture(t_setting *all);
int					my_mlx_pixel_output(t_setting *all, int x, int y, int i);
void				my_mlx_tex_put(t_setting *all, int x, int y, int mode);
void				texture_on_wall(t_setting *all, int x, int y, int mode);
int					checker_core(t_setting *all);
void				main_sprites(t_setting *all);
int					len_two(char **map);
void				calc_tool_sprite(t_setting *all);
void				sprt_tocam(t_setting *all, int j);
void				ft_bitmap(t_setting *all);
void				while_inviniti(void);
int					start_key(int key, t_setting *all);
int					stop_key(int key, t_setting *all);
void				drawing_tool(int x, int y, t_setting *all);
void				ft_if_else_lodev(t_setting *all);
void				sky_start_texx_getter(t_setting *all);
void				data_getter(t_setting *all, int x);
void				get_hit(t_setting *all, int *hit);
char				**make_map(t_list **head, int size);
int					check_our_place_character(t_setting *all, \
					int x, int y, char c);
int					on_the_oferlflow_check(t_setting *all, int x,\
					int y);
int					check_closed_map(t_setting *all, int x, int y);
int					pt(t_setting *all, int x, int y, char c);
int					map_pos_checker2(t_setting *all, int x, int y);
int					map_pos_checker(t_setting *all);
void				get_vector_num_part2(char c, t_setting *all);
void				get_vector_num(char c, t_setting *all);
void				get_pos_player(t_setting *all);
int					check_last_wp(t_win_setting *all, int len, int y);
int					for_checker_map_if(t_setting *all, int x, int y);
int					while_checker_maps(t_setting *all);
int					checker_maps(t_setting *all);
void				zero_list(t_list *head);
void				ft_parse_map(int fd, char *line, t_setting *all);
void				render_with_texture(t_setting *all);
int					parse_resolution(char *str, t_setting *all);
char				*parse_path(char *line);
void				get_sky_rgb(char *line, t_setting *all);
void				get_floor_rgb(char *line, t_setting *all);
int					check_line(int fd, char *line, t_setting *all);
void				ft_swap_d(double *n1, double *n2);
void				ft_swap(int *n1, int *n2);
int					ft_nbrlen(int nbr);
void				run_cub3d(int fd, t_setting *all);
void				main_else2(int argc, t_setting *all);
void				raycaster_start(t_setting *all);
int					nice_line_check(char *str, int mode);
void				error_s(int mode, char *str);
int					check_flag_set(char *str, int index);
int					check_lineforres_res(char *str);
int					check_haystack(char *str, int len);
int					check_number(char *str, t_setting *all, char c);
int					alien_flag(char c);
int					check_dublicate(t_setting *all, char c, char *str, int i);
void				get_coordinates(t_setting *all);
void				get_current_dstpr(t_setting *all, int mode);
void				get_dstprs(t_setting *all, int len);
void				sort_sprites(t_setting *all, int len);
void				error_path(void);
void				error_rgb(void);
void				error_res(void);
int					checker_path(char *str);
int					checker_rgb_struct(int r, int g, int b);
int					checker_paths(t_color_texture *txt);
void				checker_width(t_setting *all, char c);
void				dublicate_er(void);
int					nswe__poin(char *str, char **deno, int i);
int					nswe_(t_setting *all, char *str, int i);
void				check_flager(char *str, int i);
int					ft_exit(int key, t_setting *all);
void				alloc_struct(t_setting *all);
#endif
