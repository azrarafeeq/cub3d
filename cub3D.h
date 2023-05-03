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

# define WIN_HEIGHT 800
# define WIN_WIDTH 1000
# define BLOCK_SIZE 64
# define NEXT_STEP 10

# define FRAME_SIZE 64
# define UP_ARROW 126
# define DOWN_ARROW 125
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define ESC 52

# define W 13
# define A 0
# define S 1
# define D 2

# define RED "\033[1;31m"
# define G "\033[1;32m"
# define Y "\033[1;33m"
# define B "\033[1;34m"
# define C "\033[0;36m"
# define P "\033[0;35m"
# define RESET "\033[0m"

# define HEX "0123456789ABCDEF"
# define DEC "0123456789"

# define FOV_ANGLE (60 * (M_PI / 180))
# define 

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

// typedef struct s_cub{
// 	void		*mlx;
// 	void		*win;
// 	int			win_width;
// 	int			win_length;
// 	long int	floor_color;
// 	long int	ceil_color;
// }				t_cub;

// struct Ray {
//     float rayAngle;
//     float wallHitX;
//     float wallHitY;
//     float distance;
//     int wasHitVertical;
//     int isRayFacingUp;
//     int isRayFacingDown;
//     int isRayFacingLeft;
//     int isRayFacingRight;
//     int wallHitContent;
// }

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
	int		detector_flag; // flag to detect errors..ets if more than 1
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

// key
void	key0_2(t_all *all, int keycode);

#endif