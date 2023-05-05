/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:34:41 by aalhmoud          #+#    #+#             */
/*   Updated: 2023/05/05 04:11:13 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_read(int fd, t_all *all)
{
	char	*mapline;
	char	*line;

	mapline = ft_strdup("");
	mapline[0] = 0;
	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error: Map is Empty\n", 21);
		close(fd);
		ft_error(all, 3);
		exit(0);
	}
	while (line)
	{
		mapline = ft_strjoin(mapline, line);
		line = get_next_line(fd);
	}
	all->mapl = mapline;
}

void	ft_get_map(t_all *all, char *filename)
{
	int	fd;

	all->map_file = ft_strdup(filename);
	ft_map_extension(all);
	fd = open(all->map_file, O_RDONLY);
	ft_read(fd, all);
	close(fd);
	all->splmap = ft_split_all(all->mapl, all);
	ft_config_sort(all);
	all->textures = ft_2d_dup(all->splmap, 0, 4);
	all->colors = ft_2d_dup(all->splmap, 4, 2);
	all->map = ft_2d_dup(all->splmap, 6, ft_arr_len(all->splmap) - 6);
	ft_color_parse(all);
	ft_map_valid_char(all, -1, 0);
	if (all->detector_flag == 0)
		ft_error(all, 5);
	ft_check_walls(all);
	ft_check_space(all, -1, -1);
	ft_check_zero(all);
	ft_texture(all);
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
	all->pl->posx = (double)y + 0.5;
	all->pl->posy = (double)x + 0.5;
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
	t_mlx		mlx;
	t_ray		ray;
	t_player	player;

	if (argc != 2)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("Invalid amount of arguments\n", 2);
		ft_putstr_fd(RESET, 2);
		exit(0);
	}
	all_struct_init(&all, &mlx, &ray, &player);
	ft_get_map(&all, argv[1]);
	all.mlx->mlx = mlx_init();
	all.mlx->mlx_win = mlx_new_window(all.mlx->mlx,
			WIN_WIDTH, WIN_HEIGHT, "cub3d");
	initimgs(&all);
	ray_cast(&all, all.map);
	mlx_hook(all.mlx->mlx_win, 2, 1L << 0, key, &all);
	mlx_hook(all.mlx->mlx_win, 17, 1L << 5, ft_destroy_free, &all);
	mlx_loop(all.mlx->mlx);
}
