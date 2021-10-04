/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 20:22:46 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/18 22:08:26 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			func_norme(t_setting *all, char **str, int i, void *ptr)
{
	all->wnw->height = all->wnw->height;
	nice_line_check(*str, 1);
	check_haystack(*str, i);
	*str += i + 3;
	return (nswe__poin(*str, ptr, i));
}

int			nswe_(t_setting *all, char *str, int i)
{
	if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		return (func_norme(all, &str, i, &all->color->no_path_texture));
	else if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		return (func_norme(all, &str, i, &all->color->so_path_texture));
	else if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		return (func_norme(all, &str, i, &all->color->we_path_texture));
	else if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		return (func_norme(all, &str, i, &all->color->ea_path_texture));
	else if (str[i] == 'S' && str[i + 1] == ' ')
	{
		nice_line_check(str, 1);
		check_haystack(str, i);
		str += i + 2;
		return (nswe__poin(str, &all->color->sprite_path, i));
	}
	return (0);
}

int			nswe__poin(char *str, char **deno, int i)
{
	if (check_flag_set(str, i))
	{
		ft_printf("Error\n this flag incorrect set \n-------|%s|------\n", str);
		exit(0);
	}
	*deno = ft_strdup(parse_path(str));
	return (1);
}

void		check_flager(char *str, int i)
{
	if (check_flag_set(str, i))
	{
		ft_printf("Error\n this flag incorrect set \n-------|%s|------\n", str);
		exit(0);
	}
}

int			ft_exit(int key, t_setting *all)
{
	all->wnw->height = all->wnw->height;
	exit(key);
}
