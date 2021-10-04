/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainpart3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:37:48 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/18 22:08:26 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	run_cub3d(int fd, t_setting *all)
{
	struct_setting_parser(fd, all);
	checker_core(all);
	close(fd);
	raycaster_start(all);
	exit(0);
}

void	main_else2(int argc, t_setting *all)
{
	if (all->save == 0 && argc == 2)
		ft_printf("Error\n NEED FILE .CUB");
	else if (argc == 3)
		ft_printf("Error\n unknown flag");
	exit(0);
}

int		alien_flag(char c)
{
	if (c >= 65 && c <= 90)
	{
		if (c == 'R')
			return (0);
		if (c == 'S')
			return (0);
		if (c == 'C')
			return (0);
		if (c == 'F')
			return (0);
		if (c == 'W')
			return (0);
		if (c == 'N')
			return (0);
		if (c == 'E')
			return (0);
		else
			return (1);
	}
	else
		return (0);
}
