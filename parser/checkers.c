/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:31:48 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/15 15:30:04 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		check_dubl_nswe_(t_setting *all, char c, char *str, int i)
{
	if (c == 'N' && str[i + 1] == 'O')
	{
		if (all->color->no_path_texture != NULL)
			dublicate_er();
	}
	if (c == 'S' && str[i + 1] == 'O')
	{
		if (all->color->so_path_texture != NULL)
			dublicate_er();
	}
	if (c == 'W' && str[i + 1] == 'E')
	{
		if (all->color->we_path_texture != NULL)
			dublicate_er();
	}
	if (c == 'S' && str[i + 1] == ' ')
	{
		if (all->color->sprite_path != NULL)
			dublicate_er();
	}
	if (c == 'E' && str[i + 1] == 'A')
	{
		if (all->color->ea_path_texture != NULL)
			dublicate_er();
	}
}

int				check_dublicate(t_setting *all, char c, char *str, int i)
{
	if (!alien_flag(c))
	{
		if (!check_flag_set(str, i))
		{
			if (c == 'R' && str[i + 1] == ' ')
			{
				if (all->wnw->width != 0)
					dublicate_er();
				if (all->wnw->height != 0)
					dublicate_er();
			}
			check_dubl_nswe_(all, c, str, i);
			if (c == 'C' && str[i + 1] == ' ')
			{
				if (all->color->rgb_s_r != -1)
					dublicate_er();
			}
			if (c == 'F' && str[i + 1] == ' ')
			{
				if (all->color->rgb_f_r != -1)
					dublicate_er();
			}
		}
	}
	return (0);
}
