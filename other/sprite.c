/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:51:09 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/15 15:51:59 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_coordinates(t_setting *all)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (all->wnw->map[y])
	{
		x = 0;
		while (all->wnw->map[y][x])
		{
			if (all->wnw->map[y][x] == '2')
			{
				all->sprite[i].y = x + 0.5;
				all->sprite[i].x = y + 0.5;
				all->sprite[i].order = i;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	get_current_dstpr(t_setting *all, int mode)
{
	all->sprite[mode].dstpr = \
		sqrtf(powf((all->pos_x - all->sprite[mode].x), 2)\
		+ powf((all->pos_y - all->sprite[mode].y), 2));
}

void	get_dstprs(t_setting *all, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		get_current_dstpr(all, i);
		i++;
	}
}

void	sort_sprites(t_setting *all, int len)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (all->sprite[j].dstpr < all->sprite[j + 1].dstpr)
			{
				ft_swap_d(&all->sprite[j].x, &all->sprite[j + 1].x);
				ft_swap_d(&all->sprite[j].y, &all->sprite[j + 1].y);
				ft_swap_d(&all->sprite[j].dstpr, &all->sprite[j + 1].dstpr);
			}
			j++;
		}
		i++;
	}
}

void	main_sprites(t_setting *all)
{
	int count_sprites;

	count_sprites = len_two(all->wnw->map);
	all->sprite = ft_calloc(count_sprites + 1, sizeof(t_sprite));
	get_coordinates(all);
	get_dstprs(all, count_sprites);
	sort_sprites(all, count_sprites);
}
