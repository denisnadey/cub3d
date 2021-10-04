/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:33:08 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/10 18:35:09 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_swap(int *n1, int *n2)
{
	int nb;

	nb = *n1;
	*n1 = *n2;
	*n2 = nb;
}

void	ft_swap_d(double *n1, double *n2)
{
	double nb;

	nb = *n1;
	*n1 = *n2;
	*n2 = nb;
}

int		len_two(char **map)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '2')
				i++;
			x++;
		}
		y++;
	}
	return (i);
}
