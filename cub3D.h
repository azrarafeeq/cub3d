/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:23:16 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/01 20:57:50 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_coords {
	double	x;
	double	y;
}				t_coords;

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
	int		win_width;
	int		win_length;
	int		zoom;
	t_map	*map;
	t_balg	*b_alg;
	t_image	*i;
}				t_cub;

void	get_map(t_map *map, char *filename);
void	map_height(char *filename, t_map *map);
void	map_width(char *line, t_map *map);
void	read_map(t_map *map, int fd);

t_balg	*allocate_balg(double *x, double *y, double *x2, double *y2);

void	bressenham(int x1, int y1, char flag, t_cub **cub, int minusy, int minusx);
void	bressenham_part_2(t_balg *b_alg, double *x, double *y);
void	initialize_x_y(t_coords *c, int x1, int y1, char flag);
int		swap_content(double *int1, double *int2);
int		get_sign(double num);

void	draw(t_cub **cub);
void	zoom(t_coords *c, t_cub **cub);
void	my_mlx_pixel_put(t_cub **cub, int x, int y, int color);

void	free_char_array(char **array);
void	free_int_array(int **int_array, int size);

#endif