/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:56:52 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/05 04:10:57 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	all_struct_init(t_all *all, t_mlx *mlx, t_ray *ray, t_player *player)
{
	ft_bzero(mlx, sizeof(t_mlx));
	ft_bzero(ray, sizeof(t_ray));
	ft_bzero(all, sizeof(t_player));
	ft_bzero(all, sizeof(t_all));
	player->posx = 3;
	player->posy = 27;
	all->pl = player;
	direction(player);
	all->mlx = mlx;
	all->ray = ray;
}

void	direction(t_player *player)
{
	where_0(player);
	if (player->compass == 1)
	{
		player->dirx = 0;
		player->diry = 1;
		player->plnx = 0.66;
		player->plny = 0;
	}
	else if (player->compass == 2)
	{
		player->dirx = 1;
		player->diry = 0;
		player->plnx = 0;
		player->plny = -0.66;
	}
	else if (player->compass == 3)
	{
		player->dirx = 0;
		player->diry = -1;
		player->plnx = -0.66;
		player->plny = 0;
	}
}

void	where_0(t_player *player)
{
	if (player->compass == 0)
	{
		player->dirx = -1;
		player->diry = 0;
		player->plnx = 0;
		player->plny = 0.66;
	}
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

void	initdrawing(t_all *all, int x)
{
	all->ray->camerax = 2 * x / (double)WIN_WIDTH - 1;
	all->ray->raydirx = all->pl->dirx + all->pl->plnx * all->ray->camerax;
	all->ray->raydiry = all->pl->diry + all->pl->plny * all->ray->camerax;
	all->ray->mapx = (int)all->pl->posx;
	all->ray->mapy = (int)all->pl->posy;
	if (all->ray->raydirx == 0)
		all->ray->deltadistx = 1e30;
	else
		all->ray->deltadistx = fabs(1 / all->ray->raydirx);
	if (all->ray->raydiry == 0)
		all->ray->deltadisty = 1e30;
	else
		all->ray->deltadisty = fabs(1 / all->ray->raydiry);
	all->ray->hit = 0;
}
