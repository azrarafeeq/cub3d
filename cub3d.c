/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:34:41 by aalhmoud          #+#    #+#             */
/*   Updated: 2023/05/02 22:45:52 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_read(int fd, t_all *all)
{
	char	*buffer;
	char	*mapline;
	int		rd;

	rd = 1;
	mapline = ft_strdup("");
	buffer = malloc(2);
	mapline[0] = 0;
	buffer[1] = 0;
	while (rd == 1)
	{
		rd = read(fd, &buffer[0], 1);
		if (rd == -1)
		{
			free(buffer);
			free(mapline);
			ft_error(all, 3);
		}
		mapline = ft_strjoin(mapline, buffer);
	}
	free(buffer);
	all->mapl = mapline;
}

void	ft_map_checker(t_all *all)
{
	int	fd;

	ft_map_extension(all);
	fd = open(all->map_file, O_RDONLY);
	ft_read(fd, all);
	close(fd);
	all->splmap = ft_split_all(all->mapl, all);
	ft_config_sort(all);
	all->textures = ft_arr_dup(all->splmap, 0, 4);
	all->colors = ft_arr_dup(all->splmap, 4, 2);
	all->map = ft_arr_dup(all->splmap, 6, ft_arr_len(all->splmap) - 6);
	ft_color_parse(all);
	ft_map_valid_char(all, -1, 0);
	if (all->detector_flag == 0)
		ft_error(all, 5);
	ft_check_walls(all);
	ft_check_space(all, -1, -1);
	ft_check_zero(all);
	//ft_texture(all);
	ft_player_position(all);
}

void	ft_player_position(t_all *all)
{
	int	x;
	int	y;
	int	flag;

	y = -1;
	flag = 0;
	while (all->map[++y])
	{
		x = -1;
		while (all->map[y][++x])
		{
			if (all->map[y][x] == 'E' || all->map[y][x] == 'S'
				|| all->map[y][x] == 'W' || all->map[y][x] == 'N')
			{
				all->map[y][x] = 'P';
				flag = 1;
				break ;
			}
		}
		if (flag)
			break ;
	}
	all->size->posx = (double)y + 0.5;
	all->size->posy = (double)x + 0.5;
}

void	ft_map_extension(t_all *all)
{
	size_t	i;

	i = 0;
	if (all->map_file[0] == '.' || ft_strlen(all->map_file) < 5)
		ft_error(all, 2);
	while (all->map_file[i])
		i++;
	i--;
	if (!(all->map_file[i] == 'b' && all->map_file[i - 1] == 'u'
			&& all->map_file[i - 2] == 'c' && all->map_file[i - 3] == '.'))
		ft_error(all, 2);
}

int	main(int argc, char **argv)
{
	t_all		all;
	t_cub		cub;
	t_size		size;
	t_player	player;

	(void)argc;
	(void)argv;
	all_struct_init(&all, &cub, &size);
	player_init(&all, &player);
	if (argc == 2)
	{
		all.map_file = ft_strdup(argv[1]);
		ft_map_checker(&all);
		//draw
		//mlx_main_loop(&all, all.map);
		mlx_put_image_to_window(all.cub->mlx, all.cub->win, all.cub->i->i, 0, 0);
		mlx_loop(all.cub->mlx);
	}
	else
		ft_error(&all, 1);
}
