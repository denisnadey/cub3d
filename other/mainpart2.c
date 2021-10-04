/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainpart2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:45:55 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/15 15:48:46 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	while_inviniti(void)
{
	while (1)
		;
}

void	ft_mover(t_setting *all)
{
	if (all->wasd->w == 1)
		w_to(all);
	if (all->wasd->s == 1)
		s_to(all);
	if (all->wasd->a == 1)
		a_to(all);
	if (all->wasd->d == 1)
		d_to(all);
	if (all->wasd->l == 1)
		l_to(all);
	if (all->wasd->r == 1)
		r_to(all);
}

void	for_render_w_t(t_setting *all)
{
	if (all->side == 0)
		all->perpwalldist = (all->map_x - all->pos_x + \
			(1 - all->stepx) / 2) / all->raydir_x;
	else
		all->perpwalldist = (all->map_y - all->pos_y + \
			(1 - all->stepy) / 2) / all->raydir_y;
	if (all->side == 0)
		all->wallx = all->pos_y + all->perpwalldist * all->raydir_y;
	else
		all->wallx = all->pos_x + all->perpwalldist * all->raydir_x;
	all->texx = all->wallx * 100;
	all->texx = all->texx % 100;
	all->lineheight = (int)(all->wnw->height / all->perpwalldist);
	all->coff = 0;
	all->wall_start = -all->lineheight / 2 + all->wnw->height / 2;
	all->wall_finish = all->lineheight / 2 + all->wnw->height / 2;
}

void	for_render_w_t2(t_setting *all)
{
	int x;
	int y;
	int hit;

	x = 0;
	y = 0;
	hit = 0;
	while (x <= all->wnw->width - 1)
	{
		data_getter(all, x);
		ft_if_else_lodev(all);
		hit = 0;
		while (hit == 0)
			get_hit(all, &hit);
		for_render_w_t(all);
		y = 0;
		sky_start_texx_getter(all);
		drawing_tool(x, y, all);
		all->zbuffer[x] = all->perpwalldist;
		x++;
	}
}

void	render_with_texture(t_setting *all)
{
	int j;
	int len_sprite;

	j = 0;
	len_sprite = len_two(all->wnw->map);
	ft_mover(all);
	for_render_w_t2(all);
	while (j < len_sprite)
	{
		sprt_tocam(all, j);
		calc_tool_sprite(all);
		render_sprt(all);
		j++;
	}
}
