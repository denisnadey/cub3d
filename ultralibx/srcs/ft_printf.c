/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:46:57 by mdenys            #+#    #+#             */
/*   Updated: 2021/01/11 18:33:52 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd_count(t_printf *list, char c, int fd)
{
	write(fd, &c, 1);
	list->count += 1;
}

int		ft_printf(const char *format, ...)
{
	int		i;
	char	*ptr;
	va_list	name;

	i = 0;
	va_start(name, format);
	ptr = (char *)format;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			i += ft_parser(&ptr, &name);
		}
		else
		{
			ft_putchar_fd(*ptr, 1);
			i++;
			ptr++;
		}
	}
	va_end(name);
	return (i);
}
