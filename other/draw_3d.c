/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:50:50 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/15 15:30:04 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_hit(t_setting *all, int *hit)
{
	if (all->sidedistx < all->sidedisty)
	{
		all->sidedistx += all->deltadistx;
		all->map_x += all->stepx;
		all->side = 0;
	}
	else
	{
		all->sidedisty += all->deltadisty;
		all->map_y += all->stepy;
		all->side = 1;
	}
	if (all->wnw->map[(int)all->map_x][(int)all->map_y] == '1')
		*hit = 1;
}

void	data_getter(t_setting *all, int x)
{
	all->cam_x = 2 * x / (double)all->wnw->width - 1;
	all->raydir_x = all->dir_x + all->plane_x * all->cam_x;
	all->raydir_y = all->dir_y + all->plane_y * all->cam_x;
	all->map_x = (int)all->pos_x;
	all->map_y = (int)all->pos_y;
	all->deltadistx = fabs(1 / all->raydir_x);
	all->deltadisty = fabs(1 / all->raydir_y);
}

void	sky_start_texx_getter(t_setting *all)
{
	all->sky_start = 0;
	all->sky_finish = all->wall_start;
	all->floor_start = all->wall_finish;
	all->floor_finish = all->wnw->height;
	if (all->side == 0 && all->map_x < all->pos_x)
		all->texx = (all->texx * all->tex[0].img_w) / 100;
	if (all->side == 0 && all->map_x > all->pos_x)
		all->texx = (all->texx * all->tex[1].img_w) / 100;
	if (all->side == 1 && all->map_y < all->pos_y)
		all->texx = (all->texx * all->tex[2].img_w) / 100;
	if (all->side == 1 && all->map_y > all->pos_y)
		all->texx = (all->texx * all->tex[3].img_w) / 100;
}

void	ft_if_else_lodev(t_setting *all)
{
	if (all->raydir_x < 0)
	{
		all->stepx = -1;
		all->sidedistx = (all->pos_x - all->map_x) * all->deltadistx;
	}
	else
	{
		all->stepx = 1;
		all->sidedistx = (all->map_x + 1.0 - all->pos_x) * all->deltadistx;
	}
	if (all->raydir_y < 0)
	{
		all->stepy = -1;
		all->sidedisty = (all->pos_y - all->map_y) * all->deltadisty;
	}
	else
	{
		all->stepy = 1;
		all->sidedisty = (all->map_y + 1.0 - all->pos_y) * all->deltadisty;
	}
}

void	drawing_tool(int x, int y, t_setting *all)
{
	while (y < all->wnw->height)
	{
		if (y >= all->sky_start && y < all->sky_finish)
			mlx_pxl_put(all->s_data, x, y, torgb(all->color->rgb_s_r,\
			all->color->rgb_s_g, all->color->rgb_s_b));
		if (y >= all->wall_start && y < all->wall_finish)
		{
			if (all->side == 0 && all->map_x < all->pos_x)
				texture_on_wall(all, x, y, 0);
			if (all->side == 0 && all->map_x > all->pos_x)
				texture_on_wall(all, x, y, 1);
			if (all->side == 1 && all->map_y < all->pos_y)
				texture_on_wall(all, x, y, 2);
			if (all->side == 1 && all->map_y > all->pos_y)
				texture_on_wall(all, x, y, 3);
		}
		if (y >= all->floor_start && y < all->floor_finish)
			mlx_pxl_put(all->s_data, x, y, torgb(all->color->rgb_f_r,\
				all->color->rgb_f_g, all->color->rgb_f_b));
		y++;
	}
}
