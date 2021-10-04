/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:32:32 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/15 15:30:04 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	zero_struct(t_setting *all)
{
	all->color->rgb_f_r = -1;
	all->color->rgb_f_g = -1;
	all->color->rgb_f_b = -1;
	all->color->rgb_s_r = -1;
	all->color->rgb_s_g = -1;
	all->color->rgb_s_b = -1;
}
