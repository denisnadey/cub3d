/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 20:22:46 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/18 22:08:26 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dublicate_er(void)
{
	ft_printf("Error\n DUBLICATE FLAG!!!\n");
	exit(0);
}

int		check_flag_set(char *str, int index)
{
	int i;

	i = 0;
	if (str[index] == 'R')
		i += str[index] == 'R' && str[index + 1] == ' ' ? 0 : 1;
	if (str[index] == 'S' && str[index + 1] == ' ')
		i += str[index] == 'S' && str[index + 1] == ' ' ? 0 : 1;
	if (str[index] == 'C')
		i += str[index] == 'C' && str[index + 1] == ' ' ? 0 : 1;
	if (str[index] == 'F')
		i += str[index] == 'F' && str[index + 1] == ' ' ? 0 : 1;
	if (str[index] == 'W')
		i += str[index] == 'W' && str[index + 1] == 'E' \
			&& str[index + 2] == ' ' ? 0 : 1;
	if (str[index] == 'N')
		i += str[index] == 'N' && str[index + 1] == 'O' \
			&& str[index + 2] == ' ' ? 0 : 1;
	if (str[index] == 'E')
		i += str[index] == 'E' && str[index + 1] == 'A' \
			&& str[index + 2] == ' ' ? 0 : 1;
	if (str[index] == 'S' && str[index + 1] == 'O')
		i += str[index] == 'S' && str[index + 1] == 'O' \
			&& str[index + 2] == ' ' ? 0 : 1;
	i = i > 0 ? 1 : 0;
	return (i);
}

int		check_haystack(char *str, int len)
{
	int i;

	i = 0;
	while (str[i] && i < len)
	{
		if (ft_isalpha(str[i]) && !ft_isdigit(str[i]) && str[i] != ' ')
		{
			ft_printf("Error\n this setting line has symbols: %c \
				\n-------|%s|------\n", str[i], str);
			exit(0);
		}
		i++;
	}
	return (0);
}

int		check_lineforres_res2(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) && !ft_isdigit(str[i]) && str[i] != ' ')
		{
			ft_printf("Error\n this setting line has symbols: %c \
				\n-------|%s|------\n", str[i], str);
			exit(0);
		}
		i++;
	}
	return (0);
}

int		nice_line_check(char *str, int mode)
{
	if (mode == 1)
	{
		return (check_lineforres_res(str));
	}
	else if (mode == 2)
	{
		return (check_lineforres_res2(str));
	}
	else if (mode == 3)
	{
		return (check_lineforres_res(str));
	}
	return (0);
}
