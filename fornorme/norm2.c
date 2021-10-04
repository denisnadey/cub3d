/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 20:22:46 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/15 15:30:04 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	floor_rgb(t_setting *all, int comma, char **line)
{
	if (all->color->rgb_f_r == -1 && comma == 0)
	{
		all->color->rgb_f_r = ft_atoi(*line);
		*line += ft_nbrlen(all->color->rgb_f_r);
		return (1);
	}
	if (all->color->rgb_f_g == -1 && comma == 1)
	{
		all->color->rgb_f_g = ft_atoi(*line);
		*line += ft_nbrlen(all->color->rgb_f_g);
		return (1);
	}
	if (all->color->rgb_f_b == -1 && comma == 2)
	{
		all->color->rgb_f_b = ft_atoi(*line);
		*line += ft_nbrlen(all->color->rgb_f_b);
		return (1);
	}
	return (0);
}

void		get_floor_rgb(char *line, t_setting *all)
{
	int comma;

	comma = 0;
	count_comma(line);
	while (*line)
	{
		if (*line == ',')
		{
			comma += *line == ',' ? 1 : 0;
			line++;
		}
		if (*line == 'F' || *line == 'C' || *line == ' ')
			line++;
		else if (floor_rgb(all, comma, &line))
			;
		else
			error_rgb();
	}
}

static int	sky_rgb(t_setting *all, int comma, char **line)
{
	if (all->color->rgb_s_r == -1 && comma == 0)
	{
		all->color->rgb_s_r = ft_atoi(*line);
		*line += ft_nbrlen(all->color->rgb_s_r);
		return (1);
	}
	if (all->color->rgb_s_g == -1 && comma == 1)
	{
		all->color->rgb_s_g = ft_atoi(*line);
		*line += ft_nbrlen(all->color->rgb_s_g);
		return (1);
	}
	if (all->color->rgb_s_b == -1 && comma == 2)
	{
		all->color->rgb_s_b = ft_atoi(*line);
		*line += ft_nbrlen(all->color->rgb_s_b);
		return (1);
	}
	return (0);
}

void		get_sky_rgb(char *line, t_setting *all)
{
	int comma;

	comma = 0;
	count_comma(line);
	while (*line)
	{
		if (*line == ',')
		{
			comma += *line == ',' ? 1 : 0;
			line++;
		}
		if (*line == 'F' || *line == 'C' || *line == ' ')
			line++;
		else if (sky_rgb(all, comma, &line))
			;
		else
			error_rgb();
	}
}

int			struct_setting_parser(int fd, t_setting *all)
{
	char	*line;
	int		b;

	b = 1;
	while (get_next_line(fd, &line) == 1 && b == 1)
	{
		b = check_line(fd, line, all);
		free(line);
	}
	line = NULL;
	return (0);
}
