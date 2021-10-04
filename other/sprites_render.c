/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:51:13 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/15 15:30:04 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_sprt(t_setting *all)
{
	int y;

	y = 0;
	while (all->fsp->stripe < all->fsp->drawendx)
	{
		y = all->fsp->draw_start_y;
		all->texx = (int)((all->fsp->stripe - (-all->fsp->spritewidth\
			/ 2 + all->fsp->sprtscren_x)) * \
			all->tex[4].img_w / all->fsp->spritewidth);
		if (all->fsp->transform_y > 0 && all->fsp->stripe >= 0 &&
			all->fsp->stripe < all->wnw->width && \
			all->fsp->transform_y < all->zbuffer[all->fsp->stripe])
		{
			while (y < all->fsp->drawend_y)
			{
				all->lineheight = all->fsp->drawend_y -\
					all->fsp->draw_start_y;
				texture_on_wall(all, all->fsp->stripe, y, 4);
				y++;
			}
		}
		all->fsp->stripe++;
	}
}

void	calc_tool_sprite(t_setting *all)
{
	int h;

	h = all->wnw->height;
	all->fsp->spriteheight = abs((int)\
		(h / (all->fsp->transform_y))) / 1;
	all->fsp->movescrn = (int)(0.0 / all->fsp->transform_y);
	all->fsp->draw_start_y = -all->fsp->\
		spriteheight / 2 + h / 2 + all->fsp->movescrn;
	if (all->fsp->draw_start_y < 0)
		all->fsp->draw_start_y = 0;
	all->fsp->drawend_y = all->fsp->spriteheight / 2\
		+ h / 2 + all->fsp->movescrn;
	all->fsp->spritewidth = abs((int)(all->wnw->width \
		/ (all->fsp->transform_y))) / 1;
	if (all->fsp->spritewidth >= all->wnw->width)
		all->fsp->spritewidth = all->wnw->width - 1;
	all->fsp->draw_start_x = -all->fsp->spritewidth \
		/ 2 + all->fsp->sprtscren_x;
	all->fsp->drawendx = all->fsp->spritewidth \
		/ 2 + all->fsp->sprtscren_x;
	all->fsp->stripe = all->fsp->draw_start_x;
}

void	sprt_tocam(t_setting *all, int j)
{
	all->fsp->sprite_x = \
		all->sprite[all->sprite[j].order].x - all->pos_x;
	all->fsp->sprite_y = \
		all->sprite[all->sprite[j].order].y - all->pos_y;
	all->fsp->inv_det = 1.0 / \
		(all->plane_x * all->dir_y - all->dir_x * all->plane_y);
	all->fsp->transform_x = \
		all->fsp->inv_det * (all->dir_y * \
			all->fsp->sprite_x - all->dir_x * all->fsp->sprite_y);
	all->fsp->transform_y = all->fsp->inv_det \
		* (-all->plane_y * all->fsp->sprite_x + \
			all->plane_x * all->fsp->sprite_y);
	all->fsp->sprtscren_x = (int)((all->wnw->width / 2)\
		* (1 + all->fsp->transform_x / all->fsp->transform_y));
}
