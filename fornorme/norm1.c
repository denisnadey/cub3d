/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 20:22:46 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/16 12:20:03 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	for_digit(int len, int index, char *str)
{
	while (index < len)
	{
		if (ft_isdigit(str[index]))
			break ;
		index++;
	}
	return (index);
}

int			check_number(char *str, t_setting *all, char c)
{
	int count;
	int index;
	int len;

	len = ft_strlen(str);
	count = 0;
	index = 0;
	index = for_digit(len, index, str);
	while (index < len)
	{
		if (ft_isdigit(str[index]))
			count++;
		else
			return (count);
		if (count > 9)
		{
			if (c == 'w')
				checker_width(all, 'w');
			else
				checker_width(all, 'h');
		}
		index++;
	}
	return (count);
}

void		alloc_struct(t_setting *all)
{
	all->s_data = ft_calloc(sizeof(t_data), 1);
	all->plr = ft_calloc(sizeof(t_plr), 1);
	all->wnw = ft_calloc(sizeof(t_win_setting), 1);
	all->color = ft_calloc(sizeof(t_color_texture), 1);
	all->fsp = ft_calloc(sizeof(t_forsprite), 1);
	all->wasd = ft_calloc(sizeof(t_wasd), 1);
}
