/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:50:24 by mdenys            #+#    #+#             */
/*   Updated: 2021/02/18 22:08:26 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		raycaster(t_setting *all)
{
	int count_sprites;

	count_sprites = len_two(all->wnw->map);
	get_coordinates(all);
	get_dstprs(all, count_sprites);
	sort_sprites(all, count_sprites);
	render_with_texture(all);
	draw_screen(all);
	ft_bitmap(all);
	mlx_clear_window(all->s_data->mlx, all->s_data->mlx_win);
	mlx_put_image_to_window(all->s_data->mlx, all->s_data->mlx_win, \
	all->s_data->img, 0, 0);
	return (0);
}

void	raycaster_start(t_setting *all)
{
	all->s_data->mlx = mlx_init();
	all->s_data->mlx_win = mlx_new_window(all->s_data->mlx, \
		all->wnw->width, all->wnw->height, "cub3d");
	all->s_data->img = mlx_new_image(all->s_data->mlx, \
		all->wnw->width, all->wnw->height);
	all->s_data->addr = mlx_get_data_addr(all->s_data->img, \
		&all->s_data->bppx, &all->s_data->line_length, &all->s_data->endian);
	main_sprites(all);
	alloc_mem_texture(all);
	mlx_hook(all->s_data->mlx_win, 3, 0, stop_key, all);
	mlx_hook(all->s_data->mlx_win, 2, 0, start_key, all);
	mlx_hook(all->s_data->mlx_win, 17, 0, ft_exit, all);
	mlx_loop_hook(all->s_data->mlx, raycaster, all);
	mlx_loop(all->s_data->mlx);
}

void	formain(t_setting *all, char *argv1, char *argv2, int argc)
{
	if ((all->save == 0 && argc == 2 && (open(argv1, O_RDONLY) == -1)) || \
		(all->save == 0 && (argc == 2 || argc == 3) && \
			!ft_strnstr(argv1, ".cub", ft_strlen(argv1))))
	{
		ft_printf("Error\n NEED FILE .CUB\n");
		exit(0);
	}
	else if (argc == 3 && !ft_strncmp("--save", argv2, 7))
		all->save = 1;
	else
	{
		if (argc == 3)
		{
			ft_printf("Error\n I don`t know this flag\n");
			exit(0);
		}
		else if (argc == 0 || argc > 3 || argc == 1)
		{
			ft_printf("Error\n please write valid parametres for start\n");
			exit(0);
		}
	}
}

int		main(int argc, char **argv)
{
	int			fd;
	t_setting	*all;

	all = ft_calloc(sizeof(t_setting), 1);
	alloc_struct(all);
	zero_struct(all);
	formain(all, argv[1], argv[2], argc);
	if (argc == 2 || argc == 3)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_printf("Error\n THIS FILE NOT BE READ OR BAD FILE");
			exit(0);
		}
		else if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
			run_cub3d(fd, all);
		else
			formain(all, argv[1], argv[2], argc);
	}
}
