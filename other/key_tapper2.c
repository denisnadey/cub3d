/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tapper2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:45:55 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/15 15:30:04 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	w_to(t_setting *all)
{
	if ((all->wnw->map[(int)(all->pos_x + all->dir_x * \
		SCORE)][(int)all->pos_y]) != '1')
		all->pos_x += all->dir_x * SCORE;
	if ((all->wnw->map[(int)all->pos_x][(int)(\
		all->pos_y + all->dir_y * SCORE)]) != '1')
		all->pos_y += all->dir_y * SCORE;
}

void	s_to(t_setting *all)
{
	if ((all->wnw->map[(int)(all->pos_x - all->dir_x * \
		SCORE)][(int)all->pos_y]) != '1')
		all->pos_x -= all->dir_x * SCORE;
	if ((all->wnw->map[(int)all->pos_x][(int)(all->pos_y - \
		all->dir_y * SCORE)]) != '1')
		all->pos_y -= all->dir_y * SCORE;
}

void	a_to(t_setting *all)
{
	if ((all->wnw->map[(int)(all->pos_x - all->plane_x * \
		SCORE)][(int)all->pos_y]) != '1')
		all->pos_x -= all->plane_x * SCORE;
	if ((all->wnw->map[(int)all->pos_x][(int)(all->pos_y - \
		all->plane_y * SCORE)]) != '1')
		all->pos_y -= all->plane_y * SCORE;
}

void	d_to(t_setting *all)
{
	if ((all->wnw->map[(int)(all->pos_x + all->plane_x * \
		SCORE)][(int)all->pos_y]) != '1')
		all->pos_x += all->plane_x * SCORE;
	if ((all->wnw->map[(int)all->pos_x][(int)(all->pos_y + \
		all->plane_y * SCORE)]) != '1')
		all->pos_y += all->plane_y * SCORE;
}

void	l_to(t_setting *all)
{
	all->olddir_x = all->dir_x;
	all->dir_x = all->dir_x * cos(M_PI_10) - all->dir_y * sin(M_PI_10);
	all->dir_y = all->olddir_x * sin(M_PI_10) + all->dir_y * cos(M_PI_10);
	all->oldplane_x = all->plane_x;
	all->plane_x = all->plane_x * cos(M_PI_10) - all->plane_y * sin(M_PI_10);
	all->plane_y = all->oldplane_x * \
		sin(M_PI_10) + all->plane_y * cos(M_PI_10);
}
