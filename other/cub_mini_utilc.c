/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mini_utilc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:50:40 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/15 15:30:04 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		mlx_pxl_put(t_data *all, int x, int y, int color)
{
	char	*dst;

	dst = all->addr + (y * all->line_length + x * (all->bppx / 8));
	*(unsigned int*)dst = color;
}

int			my_mlx_pixel_output(t_setting *all, int x, int y, int i)
{
	char	*dst;
	int		color;

	dst = all->tex[i].addr + (y * all->tex[i].line_length\
	+ x * (all->tex[i].bppx / 8));
	color = *(unsigned int*)dst;
	return (color);
}

int			pos_ask(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

int			ft_nbrlen(int nbr)
{
	int i;

	i = 1;
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}
