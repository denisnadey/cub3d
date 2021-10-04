/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 20:22:46 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/15 15:30:04 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	parse_res_2(char **str, t_setting *all, int *index)
{
	if (all->wnw->width == 0 && all->wnw->height == 0)
	{
		all->wnw->width = ft_atoi_long(*str);
		*index = check_number(*str, all, 'w');
		if (*index > 9)
			*str += *index;
		else
			*str += ft_nbrlen(all->wnw->width);
	}
	else if (all->wnw->width != 0 && all->wnw->height == 0)
	{
		all->wnw->height = ft_atoi_long(*str);
		*index = check_number(*str, all, 'h');
		if (*index > 9)
			*str += *index;
		else
			*str += ft_nbrlen(all->wnw->height);
		if (ft_atoi_long(*str) > 0)
			error_res();
	}
	else
		error_res();
}

int			parse_resolution(char *str, t_setting *all)
{
	int index;

	while (*str != '\0')
	{
		if (*str == 'R' || *str == ' ')
			str++;
		else if (nice_line_check(str, 2) || nice_line_check(str, 1))
			error_s(1, str);
		else
			parse_res_2(&str, all, &index);
	}
	checker_width(all, *str);
	all->zbuffer = ft_calloc(sizeof(double), all->wnw->width + 1);
	return (0);
}
