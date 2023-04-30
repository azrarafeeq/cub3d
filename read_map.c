/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:34:25 by arafeeq           #+#    #+#             */
/*   Updated: 2023/04/30 15:00:01 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_map(t_map *map, char *filename)
{
	int	fd;

	map_height(filename, map);
	map->map_2d = malloc(sizeof(int *) * map->height);
	fd = open(filename, O_RDONLY);
	read_map(map, fd);
	close(fd);
}

void	map_height(char *filename, t_map *map)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error: Map is Empty\n", 21);
		close(fd);
		exit(0);
	}
	map_width(line, map);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	map->height = height;
	close(fd);
}

void	map_width(char *line, t_map *map)
{
	int		words;
	char	**line_split;

	words = 0;
	line_split = ft_split(line, ' ');
	while (line_split[words])
		words++;
	map->width = words;
	free_char_array(line_split);
}

void	read_map(t_map *map, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**split;

	i = -1;
	line = get_next_line(fd);
	while (line && ++i != map->height)
	{
		j = -1;
		split = ft_split(line, ' ');
		map->map_2d[i] = (int *) malloc(sizeof(int) * map->width);
		while (split[++j] && j != map->width)
			map->map_2d[i][j] = ft_atoi(split[j]);
		free_char_array(split);
		free(line);
		line = get_next_line(fd);
	}
}
