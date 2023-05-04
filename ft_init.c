/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:56:52 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/05 02:25:35 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	all_struct_init(t_all *all, t_mlx *mlx, t_ray *size)
{
	ft_bzero(mlx, sizeof(t_mlx));
	ft_bzero(size, sizeof(t_ray));
	ft_bzero(all, sizeof(t_all));
	size->posx = 3;
	size->posy = 27;
	direction(size);
	all->mlx = mlx;
	all->ray = size;
}

void	direction(t_ray *size)
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

void	where_0(t_ray *size)
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
	all->ray->camerax = 2 * x / (double)WIN_WIDTH - 1;
	all->ray->raydirx = all->ray->dirx + all->ray->planex * all->ray->camerax;
	all->ray->raydiry = all->ray->diry + all->ray->planey * all->ray->camerax;
	all->ray->mapx = (int)all->ray->posx;
	all->ray->mapy = (int)all->ray->posy;
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

