/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_and_check_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:50:55 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/18 22:08:26 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		checker_maps(t_setting *all)
{
	int res;

	res = 0;
	all->wnw->len_x_map = len_x_map(all->wnw->map);
	all->wnw->len_y_map = len_y_map(all->wnw->map);
	if (while_checker_maps(all))
		return (1);
	res += map_pos_checker(all);
	return (res);
}

void	zero_list(t_list *head)
{
	t_list *ptr;

	ptr = head;
	while (ptr != NULL)
	{
		free(ptr);
		ptr = ptr->next;
	}
}

void	ft_parse_map(int fd, char *line, t_setting *all)
{
	t_list	*head;
	char	*tmp;

	head = NULL;
	tmp = ft_strdup(line);
	ft_lstadd_back(&head, ft_lstnew(tmp));
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	all->wnw->map = make_map(&head, ft_lstsize(head));
	zero_list(head);
	close(fd);
	get_pos_player(all);
	if (!checker_maps(all))
		ft_printf("MAP OK\n");
	else
	{
		ft_printf("Error\n MAP INVALID\n");
		exit(0);
	}
}
