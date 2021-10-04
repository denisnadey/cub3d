/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:51:04 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/15 15:30:04 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_data_bmp(t_setting *all, int fd)
{
	int		i;
	char	*img;

	i = all->wnw->height;
	img = all->s_data->addr;
	while (--i)
		img += all->s_data->line_length;
	while (i < all->wnw->height)
	{
		write(fd, img, all->wnw->width * 4);
		img -= all->s_data->line_length;
		i++;
	}
}

void	get_bmp_setting(t_setting *all, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = all->wnw->width;
	header[4] = (unsigned char)(n);
	header[5] = (unsigned char)(n >> 8);
	header[6] = (unsigned char)(n >> 16);
	header[7] = (unsigned char)(n >> 24);
	n = all->wnw->height;
	header[8] = (unsigned char)(n);
	header[9] = (unsigned char)(n >> 8);
	header[10] = (unsigned char)(n >> 16);
	header[11] = (unsigned char)(n >> 24);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	get_file(t_setting *all, int fd)
{
	int				n;
	int				i;
	unsigned char	header[14];

	n = all->wnw->width * all->wnw->height * 4 + 54;
	i = 0;
	while (i < 14)
		header[i++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	header[2] = (unsigned char)(n);
	header[3] = (unsigned char)(n >> 8);
	header[4] = (unsigned char)(n >> 16);
	header[5] = (unsigned char)(n >> 24);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

void	ft_bitmap(t_setting *all)
{
	int		fd;

	fd = 0;
	if (all->save == 1)
	{
		fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		if (fd < 0)
			printf("FD NOT OPEN, SCREENSHOT dont`be created");
		get_file(all, fd);
		get_bmp_setting(all, fd);
		get_data_bmp(all, fd);
		close(fd);
		exit(0);
	}
}
