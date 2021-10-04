/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 20:22:46 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/18 22:08:26 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		checker_rgb_struct(int r, int g, int b)
{
	int res;

	res = 0;
	if ((r > 255 || r == -1) || (g > 255 || g == -1) || (b > 255 || b == -1))
		res = 1;
	if ((r < 0) || (g < 0) || (b < 0))
		res = 1;
	if (res == 1)
	{
		ft_printf("Error\n \033[1;31m");
		ft_printf("Error\n THIS RGB`s NOT VALID\n");
		ft_printf("Error\n \033[1;0m");
		return (res);
	}
	return (res);
}

int		checker_path(char *str)
{
	int fd;

	fd = 0;
	if ((fd = open((const char *)str, O_RDONLY)) == -1)
	{
		close(fd);
		return (1);
	}
	else
	{
		close(fd);
		return (0);
	}
}

int		checker_paths(t_color_texture *txt)
{
	int i;

	i = 0;
	if (checker_path(txt->no_path_texture))
		i++;
	if (checker_path(txt->so_path_texture))
		i++;
	if (checker_path(txt->ea_path_texture))
		i++;
	if (checker_path(txt->we_path_texture))
		i++;
	if (checker_path(txt->sprite_path))
		i++;
	return (i);
}

void	checker_width(t_setting *all, char c)
{
	mlx_get_size_wide(&all->wnw->realwidth, &all->wnw->realheight);
	if (c == 'w')
		all->wnw->width = all->wnw->realwidth;
	else if (c == 'h')
		all->wnw->height = all->wnw->realheight;
	else
	{
		if (all->wnw->width <= 0 || all->wnw->height <= 0)
		{
			ft_printf("Error\n RES <= 0 this is ERROR\n");
			exit(0);
		}
		if (all->wnw->realwidth < all->wnw->width)
			all->wnw->width = all->wnw->realwidth;
		else if (all->wnw->realheight < all->wnw->height)
			all->wnw->height = all->wnw->realheight;
	}
}

int		checker_core(t_setting *all)
{
	t_color_texture	*color;
	int				i;

	i = 0;
	color = all->color;
	if (all->wnw->map == NULL)
	{
		ft_printf("Error\n MAP INVALID\n");
		exit(0);
	}
	if (checker_paths(all->color))
	{
		ft_printf("Error\n paths INVALID\n");
		exit(0);
	}
	if (!checker_rgb_struct(color->rgb_s_r, color->rgb_s_g, color->rgb_s_b) &&\
		!checker_rgb_struct(color->rgb_f_r, color->rgb_f_g, color->rgb_f_b))
		i++;
	else
	{
		ft_printf("Error\n COLOR INVALID\n");
		exit(0);
	}
	checker_width(all, '0');
	return (i);
}
