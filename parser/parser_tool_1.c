/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tool_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:50:55 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/15 15:30:04 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**make_map(t_list **head, int size)
{
	char	**map;
	t_list	*tmp;
	int		i;

	map = ft_calloc(size + 1, sizeof(char *));
	i = -1;
	tmp = *head;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (map);
}

int		len_y_map(char **map)
{
	int len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}

int		len_x_map(char **map)
{
	int len_current;
	int max_value;
	int i;

	len_current = 0;
	i = 0;
	max_value = 0;
	while (map[i])
	{
		len_current = ft_strlen(map[i]);
		if (len_current > max_value)
			max_value = len_current;
		i++;
	}
	return (max_value);
}

int		check_our_place_character(t_setting *all, int x, int y, char c)
{
	int ok;

	ok = 0;
	ok += all->wnw->map[y][x - 1] != c ? 0 : 1;
	ok += all->wnw->map[y][x + 1] != c ? 0 : 1;
	ok += all->wnw->map[y - 1][x] != c ? 0 : 1;
	ok += all->wnw->map[y + 1][x] != c ? 0 : 1;
	ok += all->wnw->map[y + 1][x + 1] != c ? 0 : 1;
	ok += all->wnw->map[y + 1][x - 1] != c ? 0 : 1;
	ok += all->wnw->map[y - 1][x + 1] != c ? 0 : 1;
	ok += all->wnw->map[y - 1][x - 1] != c ? 0 : 1;
	if (ok > 0)
		return (1);
	else
		return (0);
}

int		on_the_oferlflow_check(t_setting *all, int x, int y)
{
	int len_next_line;
	int qilvo_line;
	int current_len_line;
	int ok;

	len_next_line = 0;
	qilvo_line = all->wnw->len_y_map;
	current_len_line = ft_strlen(all->wnw->map[y]);
	if (y + 1 != qilvo_line)
		len_next_line = ft_strlen(all->wnw->map[y + 1]);
	else
		return (12);
	ok = 1;
	if ((x < current_len_line && x > 0) && \
		(y < qilvo_line && y > 0) && x < len_next_line)
		ok = 0;
	if (x == current_len_line - 1)
		ok = 1;
	return (ok);
}
