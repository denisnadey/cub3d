/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tool_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:27:07 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/15 15:30:29 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_vector_num(char c, t_setting *all)
{
	if (c == 'N')
	{
		all->dir_x = 0;
		all->dir_y = -1;
		all->plane_x = -0.66;
		all->plane_y = 0;
	}
	else if (c == 'S')
	{
		all->dir_x = 0;
		all->dir_y = 1;
		all->plane_x = 0.66;
		all->plane_y = 0;
	}
	get_vector_num_part2(c, all);
}

void	get_pos_player(t_setting *all)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (all->wnw->map[y])
	{
		while (all->wnw->map[y][x])
		{
			if (all->wnw->map[y][x] == 'N' || all->wnw->map[y][x] == 'S' \
				|| all->wnw->map[y][x] == 'E' || all->wnw->map[y][x] == 'W')
			{
				all->pos_y = x + 0.5;
				all->pos_x = y + 0.5;
				get_vector_num(all->wnw->map[y][x], all);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int		check_last_wp(t_win_setting *all, int len, int y)
{
	if (all->map[y][0] == ' ' || all->map[y][0] == '\0')
	{
		if (all->map[y][0] == '\0' && ft_strchr(all->map[y - 1], '1'))
			return (1);
		if (y < len)
		{
			if (all->map[y][0] == '\0' && all->map[y + 1] != NULL)
				return (1);
		}
	}
	return (0);
}

int		for_checker_map_if(t_setting *all, int x, int y)
{
	if (all->wnw->map[y][x] != '1' && \
		(pt(all, x, y, all->wnw->map[y][x])) && all->wnw->map[y][x] == '0')
		return (1);
	else if (all->wnw->map[y][x] != '1' && \
		(pt(all, x, y, all->wnw->map[y][x])) && all->wnw->map[y][x] == 'N')
		return (1);
	else if (all->wnw->map[y][x] != '1' && \
		(pt(all, x, y, all->wnw->map[y][x])) && all->wnw->map[y][x] == 'S')
		return (1);
	else if (all->wnw->map[y][x] != '1' && \
		(pt(all, x, y, all->wnw->map[y][x])) && all->wnw->map[y][x] == 'E')
		return (1);
	else if (all->wnw->map[y][x] != '1' && \
		(pt(all, x, y, all->wnw->map[y][x])) && all->wnw->map[y][x] == 'W')
		return (1);
	else if (all->wnw->map[y][x] != '1' && \
		(pt(all, x, y, all->wnw->map[y][x])) && all->wnw->map[y][x] == '2')
		return (1);
	else
		return (0);
}

int		while_checker_maps(t_setting *all)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < all->wnw->len_y_map)
	{
		if (check_last_wp(all->wnw, all->wnw->len_y_map, y))
			return (1);
		nice_line_check(all->wnw->map[y], 1);
		while (all->wnw->map[y][x])
		{
			if (all->wnw->map[y][x] == '1' || all->wnw->map[y][x] == ' ')
				x++;
			else if (for_checker_map_if(all, x, y))
				return (1);
			else
				x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
