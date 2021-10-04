/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:40:43 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/18 22:08:26 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			rgbget2(t_setting *all, char *str, int i)
{
	if (str[i] == 'C')
	{
		check_flager(str, i);
		if (*str == ' ')
		{
			while (*str == ' ')
				str++;
			str++;
		}
		else
			str++;
		nice_line_check(str, 1);
		nice_line_check(str, 2);
		get_sky_rgb(str, all);
		return (1);
	}
	return (0);
}

int			rgbget(t_setting *all, char *str, int i)
{
	if (str[i] == 'F')
	{
		check_flager(str, i);
		if (*str == ' ')
		{
			while (*str == ' ')
				str++;
			str++;
		}
		else
			str++;
		nice_line_check(str, 1);
		nice_line_check(str, 2);
		get_floor_rgb(str, all);
		return (1);
	}
	else
		return (rgbget2(all, str, i));
	return (0);
}

void		check_line2(int i, char *line)
{
	ft_printf("Error\n I don`t know this flag [%c]\n", line[i]);
	exit(0);
}

int			check_line(int fd, char *line, t_setting *all)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (check_dublicate(all, line[i], line, i) || alien_flag(line[i]))
			check_line2(i, line);
		if (line[i] == 'R' && line[i + 1] == ' ')
		{
			parse_resolution(line, all);
			break ;
		}
		else if (nswe_(all, line, i))
			break ;
		else if (rgbget(all, line, i))
			break ;
		else if (line[i] == '1')
		{
			ft_parse_map(fd, line, all);
			return (0);
		}
		else
			i++;
	}
	return (1);
}
