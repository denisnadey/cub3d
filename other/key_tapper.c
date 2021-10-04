/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:49:52 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/15 15:30:04 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	r_to(t_setting *all)
{
	all->olddir_x = all->dir_x;
	all->dir_x = all->dir_x * cos(-M_PI_10) - all->dir_y * sin(-M_PI_10);
	all->dir_y = all->olddir_x * sin(-M_PI_10) + all->dir_y * cos(-M_PI_10);
	all->oldplane_x = all->plane_x;
	all->plane_x = all->plane_x * cos(-M_PI_10) \
		- all->plane_y * sin(-M_PI_10);
	all->plane_y = all->oldplane_x * sin(-M_PI_10) \
		+ all->plane_y * cos(-M_PI_10);
}

int		start_key(int key, t_setting *all)
{
	if (key == ESC)
		exit(0);
	(key == W) ? all->wasd->w = 1 : 0;
	(key == A) ? all->wasd->a = 1 : 0;
	(key == 1) ? all->wasd->s = 1 : 0;
	(key == D) ? all->wasd->d = 1 : 0;
	(key == LEFT) ? all->wasd->l = 1 : 0;
	(key == RIGHT) ? all->wasd->r = 1 : 0;
	return (0);
}

int		stop_key(int key, t_setting *all)
{
	if (key == ESC)
		exit(0);
	(key == W) ? all->wasd->w = 0 : 1;
	(key == A) ? all->wasd->a = 0 : 1;
	(key == 1) ? all->wasd->s = 0 : 1;
	(key == D) ? all->wasd->d = 0 : 1;
	(key == LEFT) ? all->wasd->l = 0 : 1;
	(key == RIGHT) ? all->wasd->r = 0 : 1;
	return (0);
}
