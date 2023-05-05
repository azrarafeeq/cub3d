/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 06:12:26 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/05 22:23:32 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**_2d_array_dup(char **arr, size_t start, size_t size)
{
	size_t	i;
	size_t	j;
	char	**ret;

	if (!size)
		return (NULL);
	i = start;
	j = 0;
	ret = (char **)malloc((size + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	while ((i < (start + size)) && arr[i])
		ret[j++] = ft_strdup(arr[i++]);
	ret[j] = NULL;
	return (ret);
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

void	ft_get_map(t_all *all, char *filename)
{
	int	fd;

	all->map_file = ft_strdup(filename);
	ft_map_extension(all);
	fd = open(all->map_file, O_RDONLY);
	ft_read(fd, all);
	close(fd);
	all->splmap = ft_split_all(all->mapl, all);
	ft_replace_element(all);
	all->textures = _2d_array_dup(all->splmap, 0, 4);
	all->colors = _2d_array_dup(all->splmap, 4, 2);
	all->map = _2d_array_dup(all->splmap, 6, ft_arr_len(all->splmap) - 6);
	ft_color_parse(all);
	ft_map_valid_char(all, -1, 0);
	if (all->compass_flag == 0)
		ft_error(all, 5);
	ft_check_walls(all);
	ft_check_space(all, -1, -1);
	ft_check_zero(all);
	ft_texture(all);
	ft_player_position(all);
}
