/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:23:16 by arafeeq           #+#    #+#             */
/*   Updated: 2023/04/30 14:46:31 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_image {
	void	*i;
	char	*addr;
	int		bpp;
	int		l_len;
	int		e;
}				t_image;

typedef struct s_map {
	int		height;
	int		width;
	int		**map_2d;
}				t_map;

typedef struct s_balg {
	double	delta_x;
	double	delta_y;
	int		step_1;
	int		step_2;
	double	diff;
	int		swap;
	int		i;
}				t_balg;

typedef struct s_cub{
	void	*mlx;
	void	*win;
	t_image	*i;
}				t_cub;

void	get_map(t_map *map, char *filename);
void	map_height(char *filename, t_map *map);
void	map_width(char *line, t_map *map);
void	read_map(t_map *map, int fd);

void	free_char_array(char **array);
void	free_int_array(int **int_array, int size);

#endif