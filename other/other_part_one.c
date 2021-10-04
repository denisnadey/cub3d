/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_part_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:10:47 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/18 22:08:26 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*make_dir_char(int tmp)
{
	char *tmp_char;

	tmp_char = ft_itoa(tmp);
	return (tmp_char);
}

int		check_file_ext(char *str)
{
	if (ft_strnstr(str, ".cub", ft_strlen(str)) == 0)
	{
		ft_printf("Error\n NEED CUB FILE 👽👽👽👽\n");
		return (1);
	}
	else
		return (0);
}
