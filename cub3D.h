/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:23:16 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/05 02:32:49 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_HEIGHT 800
# define WIN_WIDTH 1000

# define UP_ARROW 126
# define DOWN_ARROW 125
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define ESC 53

# define W 13
# define A 0
# define S 1
# define D 2

# define RED "\033[1;31m"
# define RESET "\033[0m"

# define HEX "0123456789ABCDEF"
# define DEC "0123456789"

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

// typedef struct s_player
// {
// 	int	pos;
// }				t_ray;

typedef struct s_ray
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
}			t_ray;

typedef struct s_mlx
{
	void		*mlx;
	int			texx;
	int			texy;
	void		*tex;
	int			*text;
	void		*tex2;
	int			*text2;
	void		*tex3;
	int			*text3;
	void		*tex4;
	int			*text4;
	long int	ccolor;
	long int	fcolor;
	int			drawend;
	void		*mlx_win;
	int			**buffer;
	int			drawstart;
	int			lineheight;
	void		*img;
	int			b;
	int			h;
	int			w;
}			t_mlx;

typedef struct s_all
{
	t_ray	*ray; // struct conains everything related to casting rays
	t_mlx	*mlx;
	char	*map_file; // map got from user as argument
	char	*mapl; // the whole map in one string after reading with read()
	char	**splmap; // mapl splitted with "\n"
	char	**textures; // stores the texture from the splitted map
	char	**colors; // stores the colours from the splitted map
	char	**map; // stores the map from th esplitted map
	int		exit; // code to exit
	int		detector_flag; // flag to detect errors..exits if more than 1
}			t_all;

// INITIALIZE STRUCT

void	all_struct_init(t_all *all, t_mlx *mlx, t_ray *size);
void	direction(t_ray *size);
void	where_0(t_ray *size);

// GET MAP

void	ft_get_map(t_all *all, char *filename);
void	ft_map_extension(t_all *all);
void	ft_read(int fd, t_all *all);
char	**ft_split_all(char *str, t_all *all);
void	ft_config_sort(t_all *all);
char	**ft_2d_dup(char **arr, size_t start, size_t size);
size_t	ft_arr_len(char **arr);
void	ft_color_parse(t_all *all);
void	ft_map_valid_char(t_all *all, int i, size_t nl);
void	ft_check_walls(t_all *all);
void	ft_check_space(t_all *all, int i, int a);
void	ft_check_zero(t_all *all);
int		check_wall_collision(t_all *all, char c);
void	check_pos(char c, t_all *all);
void	ft_texture(t_all *all);
void	ft_player_position(t_all *all);
int		ft_find_index(t_all *all, char **arr, char *s, size_t size);

// RAYCAST

char	*ft_line_replace(char *old, char *new);
void	initimgs(t_all *all);
int		ray_cast(t_all *all, char **map);
void	clearbuffer(t_all *all);
void	initdrawing(t_all *all, int x);
void	initdir(t_all *all);
void	getwallhit(t_all *all, char **map);
void	getdrawpos(t_all *all, char **map, int *ii);
void	extracheck(t_all *all);
void	getandfillwalls(t_all *all, int y, int x, int ii);
size_t	ft_atoi_index(t_all *all, const char *str, size_t i, int error);

// KEYS

void	key13_1(t_all *all, int keycode);
void	key0_2(t_all *all, int keycode);
void	key124_123(t_all *all, int keycode);
int		key(int keycode, t_all *all);
void	editbuffer(t_all *all, int ***buffer);
int		ft_quit(t_all *all);

// COLOURS

size_t	ft_atoi_index(t_all *all, const char *str, size_t i, int error);
char	*ft_put_nbr(int nbr, char *base, int sign, int i);
void	ft_putnbr_base(int nbr, int nbase, char *num_base, char *base);
char	*ft_rgb_to_hex(t_all *all, char *rgb, size_t i);
void	ft_color_chars_checker(t_all *all, size_t i, size_t a, int comma);
void	ft_color_chars_init_checker(t_all *all);

// BASE

int		ft_lnbr(int nbr, int base_lenght);
char	*ft_char(char *dest, char src);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

// ERROR

int		ft_quit(t_all *all);
void	ft_error(t_all *all, int error);
void	ft_free_all(t_all *all);
void	ft_free_arr(char **arr);

void	extra_imgs(t_all *all);
void	drawall(t_all *all, int **buffer);
void	fill_the_void(t_all *all, int y, int x);
void	filldown(t_all *all, int y, int x);
void	gettexture(t_all *all, int ii);

#endif