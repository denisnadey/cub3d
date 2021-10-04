/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:31:09 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/18 22:08:26 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_res(void)
{
	ft_printf("Error\n INVALID RES\n");
	exit(0);
}

char	*parse_path(char *line)
{
	check_lineforres_res(line);
	while (*line)
	{
		if (ft_isalpha(*line))
			error_path();
		if (*line == ' ')
			line++;
		if (*line == '.' || *line == '/')
			break ;
	}
	return (line);
}

void	error_rgb(void)
{
	ft_printf("Error\n RGB NOT VALID\n");
	exit(0);
}
