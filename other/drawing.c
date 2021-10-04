/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:50:19 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/15 15:30:04 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		fn_paint_map(double x, double y, t_setting *all, int color)
{
	double		i;
	double		j;
	double		scale;
	int			len;

	len = len_y_map(all->wnw->map);
	if (len > 100)
		scale = (all->wnw->width / 100) * 0.1;
	else
		scale = (all->wnw->width / 100) * 0.5;
	i = (y * scale);
	j = 0;
	while (i < (scale * y + scale))
	{
		j = (x * scale);
		while (j < (scale * x + scale))
		{
			mlx_pxl_put(all->s_data, j, i, color);
			j++;
		}
		i++;
	}
}

void		draw_screen(t_setting *all)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (all->wnw->map[y] && y < all->wnw->len_y_map)
	{
		x = 0;
		while (all->wnw->map[y][x])
		{
			if (all->wnw->map[y][x] == '1')
				fn_paint_map(x, y, all, 0x00000000);
			if (all->wnw->map[y][x] == '2')
				fn_paint_map(x, y, all, 0x00c9c9c9);
			if (pos_ask(all->wnw->map[y][x]))
				fn_paint_map(all->pos_y, all->pos_x, all, 0x0a68ff);
			x++;
		}
		y++;
	}
}

void		alloc_mem_texture(t_setting *all)
{
	all->tex[0].img = mlx_xpm_file_to_image(all->s_data->mlx, \
	all->color->ea_path_texture, &all->tex[0].img_w, &all->tex[0].img_h);
	all->tex[1].img = mlx_xpm_file_to_image(all->s_data->mlx, \
	all->color->we_path_texture, &all->tex[1].img_w, &all->tex[1].img_h);
	all->tex[2].img = mlx_xpm_file_to_image(all->s_data->mlx, \
	all->color->no_path_texture, &all->tex[2].img_w, &all->tex[2].img_h);
	all->tex[3].img = mlx_xpm_file_to_image(all->s_data->mlx, \
	all->color->so_path_texture, &all->tex[3].img_w, &all->tex[3].img_h);
	all->tex[4].img = mlx_xpm_file_to_image(all->s_data->mlx, \
	all->color->sprite_path, &all->tex[4].img_w, &all->tex[4].img_h);
	all->tex[0].addr = mlx_get_data_addr(all->tex[0].img, &all->tex[0].bppx,\
	&all->tex[0].line_length, &all->tex[0].endian);
	all->tex[1].addr = mlx_get_data_addr(all->tex[1].img, &all->tex[1].bppx,\
	&all->tex[1].line_length, &all->tex[1].endian);
	all->tex[2].addr = mlx_get_data_addr(all->tex[2].img, &all->tex[2].bppx,\
	&all->tex[2].line_length, &all->tex[2].endian);
	all->tex[3].addr = mlx_get_data_addr(all->tex[3].img, &all->tex[3].bppx,\
	&all->tex[3].line_length, &all->tex[3].endian);
	all->tex[4].addr = mlx_get_data_addr(all->tex[4].img, &all->tex[4].bppx,\
	&all->tex[4].line_length, &all->tex[4].endian);
}

void		my_mlx_tex_put(t_setting *all, int x, int y, int mode)
{
	char *dst;
	char *src;

	dst = all->s_data->addr + (y * all->s_data->line_length +\
		x * (all->s_data->bppx / 8));
	src = all->tex[mode].addr + ((int)all->texy * all->tex[mode].line_length\
		+ all->texx * (all->tex[mode].bppx / 8));
	if (mode == 4 && *(unsigned int*)src == 0x00000000)
		return ;
	*(unsigned int*)dst = *(unsigned int*)src;
}

void		texture_on_wall(t_setting *all, int x, int y, int mode)
{
	int start_y;

	if (mode == 4)
		start_y = all->fsp->draw_start_y;
	else
		start_y = all->wall_start;
	all->coff = (double)all->lineheight / (double)all->tex[mode].img_h;
	all->texy = (double)(y - start_y);
	all->texy = all->texy / all->coff;
	if (all->texy > all->tex[mode].img_h)
		all->texy = all->tex[mode].img_h - 1;
	if (y >= 0 && y < all->wnw->height)
		my_mlx_tex_put(all, x, y, mode);
}
