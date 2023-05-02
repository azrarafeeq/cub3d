/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:23:16 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/02 22:44:02 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define FRAME_SIZE 64
# define UP_ARROW 125
# define DOWN_ARROW 126
# define RIGHT_ARROW 124
# define LEFT_ARROW 123

# define W 13
# define A 2
# define S 1
# define D 0

# define R "\033[1;31m"
# define G "\033[1;32m"
# define Y "\033[1;33m"
# define B "\033[1;34m"
# define C "\033[0;36m"
# define P "\033[0;35m"
# define RESET "\033[0m"

# define HEX "0123456789ABCDEF"
# define DEC "0123456789"

# define FOV_ANGLE (60 * (PI / 180))

# include <math.h>
# include <time.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>

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
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_length;
	long int	floor_color;
	long int	ceil_color;
	//int		zoom;
	t_balg		*b_alg;
	t_image		*i;
}				t_cub;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction; // -1 for left, +1 for right
	int		walk_direction; // -1 for back, +1 for front
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
}				t_player;

typedef struct s_size
{
	int		hit;
	int		side;
	int		mapx;
	int		mapy;
	double	dirx;
	double	diry;
	double	posx;
	double	posy;
	double	step;
	double	wallx;
	int		where;
	int		win_x;
	int		win_y;
	int		stepx;
	int		stepy;
	int		color;
	double	planex;
	double	planey;
	double	texpos;
	int		updown;
	int		drawend;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	rotspeed;
	double	movespeed;
	int		drawstart;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	int		lineheight;
	double	deltadisty;
	double	perpwalldist;
}			t_size;

// typedef struct s_mlx
// {
// 	void		*mlx;
// 	int			texx;
// 	int			texy;
// 	void		*tex;
// 	int			*text;
// 	void		*tex2;
// 	int			*text2;
// 	void		*tex3;
// 	int			*text3;
// 	void		*tex4;
// 	int			*text4;
// 	void		*tex5;
// 	void		*tex6;
// 	long int	ccolor;
// 	long int	fcolor;
// 	int			drawend;
// 	void		*mlx_win;
// 	int			**buffer;
// 	int			drawstart;
// 	int			lineheight;
// 	void		*img;
// 	int			b;
// 	int			h;
// 	int			w;
// }			t_mlx;

typedef struct s_all
{
	t_size	*size; // struct conains everything related to casting rays
	t_player *player;
	//t_mlx	*mlx;
	t_cub	*cub;
	char	*map_file; // map got from user as argument
	char	*mapl; // the whole map in one string after reading with read()
	char	**splmap; // mapl splitted with "\n"
	char	**textures; // stores the texture from the splitted map
	char	**colors; // stores the colours from the splitted map
	char	**map; // stores the map from th esplitted map
	int		exit; // code to exit
	int		detector_flag; // flag to detect errors...exits when it is set to 0
	//int		flag; --??
}			t_all;

// parsing

void	ft_replace_texture(t_all *all, char *direction, int a);
size_t	ft_atoi_index(t_all *all, const char *str, size_t i, int error);
char	*ft_rgb_to_hex(t_all *all, char *rgb, size_t i);
void	ft_texture(t_all *all);
void	ft_config_sort(t_all *all);
char	*ft_line_replace(char *old, char *new);
void	ft_color_chars_checker(t_all *all, size_t i, size_t a, int comma);
int		ft_find_index(t_all *all, char **arr, char *s, size_t size);
void	ft_color_parse(t_all *all);
void	where_0(t_size *size);
void	check_w(char c, t_all *all);
void	check_pos(char c, t_all *all);
void	direction(t_size *size);
void	all_struct_init(t_all *all, t_cub *cub, t_size *size);
void	player_init(t_all *all, t_player *player);
void	check_pos(char c, t_all *all);
void	ft_error(t_all *all, int error);
size_t	ft_arr_len(char **arr);
char	**ft_split_all(char *str, t_all *all);
char	*ft_put_nbr(int nbr, char *base, int sign, int i);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
size_t	ft_atoi_index(t_all *all, const char *str, size_t i, int error);
int		ft_lnbr(int nbr, int base_lenght);
char	*ft_char(char *dest, char src);
void	ft_free_arr(char **arr);
void	ft_free_all(t_all *all);
void	ft_map_valid_char(t_all *all, int i, size_t nl);
void	ft_map_extension(t_all *all);
void	ft_config_sort(t_all *all);
char	**ft_arr_dup(char **arr, size_t start, size_t size);
void	ft_color_parse(t_all *all);
void	ft_check_walls(t_all *all);
void	ft_check_space(t_all *all, int i, int a);
void	ft_check_zero(t_all *all);
void	ft_player_position(t_all *all);
void	mlx_main_loop(t_all *all, char **map);
void	ft_texture(t_all *all);

// parsing end

void	move_player(float deltaTime, t_player *player);

// void	get_map(t_map *map, char *filename);
// void	map_height(char *filename, t_map *map);
// void	map_width(char *line, t_map *map);
// void	read_map(t_map *map, int fd);

// t_balg	*allocate_balg(double *x, double *y, double *x2, double *y2);

// void	bressenham(int x1, int y1, char flag, t_cub **cub, int minusy, int minusx);
// void	bressenham_part_2(t_balg *b_alg, double *x, double *y);
// void	initialize_x_y(t_coords *c, int x1, int y1, char flag);
// int		swap_content(double *int1, double *int2);
// int		get_sign(double num);

// void	draw(t_cub **cub);
// void	zoom(t_coords *c, t_cub **cub);
// void	my_mlx_pixel_put(t_cub **cub, int x, int y, int color);

// void	free_char_array(char **array);
// void	free_int_array(int **int_array, int size);

#endif