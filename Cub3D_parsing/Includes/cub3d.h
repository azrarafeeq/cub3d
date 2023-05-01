/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhmoud <aalhmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:34:41 by aalhmoud          #+#    #+#             */
/*   Updated: 2023/05/01 23:26:15 by aalhmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*--------  Libraries --------*/
# include <math.h>
# include <time.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>
# include "../mlx/mlx.h"
/*--------  Libraries --------*/

/*---------  Colors ---------*/
# define R "\033[1;31m"
# define G "\033[1;32m"
# define Y "\033[1;33m"
# define B "\033[1;34m"
# define C "\033[0;36m"
# define P "\033[0;35m"
# define RESET "\033[0m"
/*---------  Colors ---------*/

/*---------  Vars ---------*/
# define HEX "0123456789ABCDEF"
# define DEC "0123456789"
/*---------  Vars ---------*/

/*--------- Structs ---------*/
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
	void		*tex5;
	void		*tex6;
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
	t_size	*size;
	t_mlx	*mlx;
	char	*map_file;
	char	*mapl;
	char	**splmap;
	char	**textures;
	char	**colors;
	char	**map;
	int		exit;
	int		detector_flag;
	int		flag;
}			t_all;
/*--------- Structs ---------*/

/*--------- Functions ---------*/
void	key0(t_all *all);
void	key1(t_all *all);
void	key2(t_all *all);
void	keyup(t_all *all);
void	key13(t_all *all);
void	key123(t_all *all);
void	key124(t_all *all);
void	initdir(t_all *all);
void	keydown(t_all *all);
void	initimgs(t_all *all);
void	where_0(t_size *size);
void	extra_imgs(t_all *all);
void	direction(t_size *size);
void	draw_sprites(t_all *all);
int		key(int keycode, t_all *all);
void	size_init_half(t_size *size);
int		nkey(int keycode, t_all *all);
void	gettexture(t_all *all, int ii);
void	initdrawing(t_all *all, int x);
int		mouse(int x, int y, t_all *all);
void	drawall(t_all *all, int **buffer);
int		print_plz(t_all *all, char **map);
void	filldown(t_all *all, int y, int x);
void	null_maker(t_all *all, t_mlx *mlx);
void	getwallhit(t_all *all, char **map);
int		check_wall_collisions_x(t_all *all);
void	editbuffer(t_all *all, int ***buffer);
void	mlx_main_loop(t_all *all, char **map);
void	fill_the_void(t_all *all, int y, int x);
void	getdrawpos(t_all *all, char **map, int *ii);
int		mouse_hook(int keycode, int x, int y, t_all *all);
void	mlx_struct_init(t_mlx *mlx, t_size *size, t_all *all);

/*--------- Parsing Functions ---------*/

size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *str);
size_t	ft_delimiter(char c);
size_t	ft_wordcount(char *str);
char	**ft_split(char *str, t_all *all);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_arr_dup(char **arr, size_t start, size_t size);
size_t	ft_arr_len(char **arr);
void	ft_arr_print(char **arr);
void	ft_free_arr(char **arr);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	ft_read(int fd, t_all *all);
void	ft_map_checker(t_all *all);
void	ft_map_extension(t_all *all);
size_t	ft_atoi_index(t_all *all, const char *str, size_t i, int error);
char	*ft_itoa(int n);
void	ft_color_chars_init_checker(t_all *all);
void	ft_color_chars_checker(t_all *all, size_t i, size_t a, int comma);
char	*ft_rgb_to_hex(t_all *all, char *rgb, size_t i);
void	ft_color_parse(t_all *all);
void	ft_map_valid_char(t_all *all, int i, size_t nl);
void	ft_map_valid_structure(t_all *all, int *i, size_t *nl);
void	ft_check_walls(t_all *all);
void	ft_check_space(t_all *all, int i, int a);
void	ft_check_zero(t_all *all);
void	ft_replace_texture(t_all *all, char *direction, int a);
void	ft_texture(t_all *all);
void	ft_player_position(t_all *all);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_put_nbr(int nbr, char *base, int sign, int i);
void	ft_putnbr_base(int nbr, int nbase, char *num_base, char *base);
char	*ft_char(char *dest, char src);
int		ft_lnbr(int nbr, int base_lenght);
int		ft_inbase(char c, char *base);
void	check_pos(char c, t_all *all);
int		ft_checker(char *base);

void	ft_error(t_all *all, int error);
int		ft_quit(t_all *all);
void	ft_free_all(t_all *all);

void	ft_bzero(void *s, unsigned long n);

char	*ft_line_replace(char *old, char *new);
int		ft_find_index(t_all *all, char **arr, char *s, size_t size);
void	ft_config_sort(t_all *all);

#endif
