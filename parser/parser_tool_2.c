/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tool_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:50:55 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/18 23:38:48 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_closed_map(t_setting *all, int x, int y)
{
	if (!on_the_oferlflow_check(all, x, y) \
		&& !check_our_place_character(all, x, y, '\0'))
	{
		if (check_our_place_character(all, x, y, ' ') == 1)
			return (1);
		else
			return (0);
	}
	else
		return (1);
}

int		pt(t_setting *all, int x, int y, char c)
{
	int i;

	i = 0;
	if (c == '0' || c == 'N' || c == 'E' || c == 'W' || c == 'S' || c == '2')
		i = check_closed_map(all, x, y);
	return (i);
}

int		map_pos_checker2(t_setting *all, int x, int y)
{
	if (all->wnw->map[y][x] == 'N' || all->wnw->map[y][x] == 'S' || \
				all->wnw->map[y][x] == 'E' || all->wnw->map[y][x] == 'W')
		return (1);
	if (all->wnw->map[y][x] != 'N' && \
				all->wnw->map[y][x] != 'S' && all->wnw->map[y][x] != 'E' \
				&& all->wnw->map[y][x] != 'W' && all->wnw->map[y][x] != '1' && \
				all->wnw->map[y][x] != '0' && all->wnw->map[y][x] != '2' \
				&& all->wnw->map[y][x] != ' ')
		return (1);
	else
		return (0);
}

int		map_pos_checker(t_setting *all)
{
	int y;
	int x;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (all->wnw->map[y])
	{
		while (all->wnw->map[y][x])
		{
			i += map_pos_checker2(all, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	if (i > 1)
		return (1);
	return (0);
}

void	get_vector_num_part2(char c, t_setting *all)
{
	if (c == 'W')
	{
		all->dir_x = 1;
		all->dir_y = 0;
		all->plane_x = 0;
		all->plane_y = -0.66;
	}
	else if (c == 'E')
	{
		all->dir_x = -1;
		all->dir_y = 0;
		all->plane_x = 0;
		all->plane_y = 0.66;
	}
}
