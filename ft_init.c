/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:56:52 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/02 22:29:52 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	all_struct_init(t_all *all, t_cub *cub, t_size *size)
{
	ft_bzero(cub, sizeof(t_mlx));
	ft_bzero(size, sizeof(t_size));
	ft_bzero(all, sizeof(t_all));
	size->posx = 3;
	size->posy = 27;
	direction(size);
	size->win_x = 960;
	size->win_y = 540;
	all->mlx = mlx;
	all->size = size;
}

void	direction(t_size *size)
{
	where_0(size);
	if (size->where == 1)
	{
		size->dirx = 0;
		size->diry = 1;
		size->planex = 0.66;
		size->planey = 0;
	}
	else if (size->where == 2)
	{
		size->dirx = 1;
		size->diry = 0;
		size->planex = 0;
		size->planey = -0.66;
	}
	else if (size->where == 3)
	{
		size->dirx = 0;
		size->diry = -1;
		size->planex = -0.66;
		size->planey = 0;
	}
}

void	where_0(t_size *size)
{
	if (size->where == 0)
	{
		size->dirx = -1;
		size->diry = 0;
		size->planex = 0;
		size->planey = 0.66;
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
	all->size->camerax = 2 * x / (double)all->size->win_x - 1;
	all->size->raydirx = all->size->dirx + all
		->size->planex * all->size->camerax;
	all->size->raydiry = all->size->diry + all->size
		->planey * all->size->camerax;
	all->size->mapx = (int)all->size->posx;
	all->size->mapy = (int)all->size->posy;
	if (all->size->raydirx == 0)
		all->size->deltadistx = 1e30;
	else
		all->size->deltadistx = fabs(1 / all->size->raydirx);
	if (all->size->raydiry == 0)
		all->size->deltadisty = 1e30;
	else
		all->size->deltadisty = fabs(1 / all->size->raydiry);
	all->size->hit = 0;
}

