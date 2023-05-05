/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:34:41 by aalhmoud          #+#    #+#             */
/*   Updated: 2023/05/05 06:24:23 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_arr_len(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

void	extra_imgs(t_all *all)
{
	all->mlx->tex3 = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[2], &all->mlx->w, &all->mlx->h);
	all->mlx->text3 = (int *)mlx_get_data_addr(all->mlx->tex3,
			&all->mlx->b, &all->mlx->h, &all->mlx->w);
	all->mlx->tex4 = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[3], &all->mlx->w, &all->mlx->h);
	all->mlx->text4 = (int *)mlx_get_data_addr(all->mlx->tex4,
			&all->mlx->b, &all->mlx->h, &all->mlx->w);
}

void	extracheck(t_all *all)
{
	if (all->ray->side == 0)
		all->ray->perpwalldist = (all->ray->sidedistx
				- all->ray->deltadistx);
	else
		all->ray->perpwalldist = (all->ray->sidedisty
				- all->ray->deltadisty);
	all->mlx->lineheight = (int)(WIN_HEIGHT / all->ray->perpwalldist);
	all->mlx->drawstart = -all->mlx->lineheight / 2
		+ ((WIN_HEIGHT / 2) + all->ray->updown);
	if (all->mlx->drawstart < 0)
		all->mlx->drawstart = 0;
	all->mlx->drawend = all->mlx->lineheight / 2
		+ ((WIN_HEIGHT / 2) + all->ray->updown);
}

size_t	ft_wordcount(char *str)
{
	size_t	nb;
	size_t	i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == '\n')
			i++;
		if (str[i] && str[i] != '\n')
			nb++;
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (nb);
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
