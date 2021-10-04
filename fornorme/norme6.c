/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 20:22:46 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/18 23:20:33 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_s(int mode, char *str)
{
	if (mode == 1)
	{
		ft_printf("Error\n this setting line has symbols: \n \
		/-------|%s|------\n", str);
		exit(0);
	}
}

void	error_path(void)
{
	ft_printf("Error\n ERROR PATH\n");
	exit(0);
}

int		check_lineforres_res(char *str)
{
	if (ft_strchr(str, 9))
	{
		ft_printf("Error\n this setting line has tab: \n\
		/-------|%s|------\n", str);
		exit(0);
	}
	return (0);
}

void	count_comma(char *str)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == ',')
			x++;
		i++;
	}
	if (x > 2)
	{
		ft_printf("Error\n COMMA > 2\n");
		exit(0);
	}
	else if (x < 2)
	{
		ft_printf("Error\n COMMA < 2\n");
		exit(0);
	}
}
