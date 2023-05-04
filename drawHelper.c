/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawHelper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:23:16 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/05 02:25:11 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initdir(t_all *all)
{
	if (all->ray->raydirx < 0)
	{
		all->ray->stepx = -1;
		all->ray->sidedistx = (all->ray->posx - \
		all->ray->mapx) * all->ray->deltadistx;
	}
	else
	{
		all->ray->stepx = 1;
		all->ray->sidedistx = (all->ray->mapx + 1.0 - \
		all->ray->posx) * all->ray->deltadistx;
	}
	if (all->ray->raydiry < 0)
	{
		all->ray->stepy = -1;
		all->ray->sidedisty = (all->ray->posy - \
		all->ray->mapy) * all->ray->deltadisty;
	}
	else
	{
		all->ray->stepy = 1;
		all->ray->sidedisty = (all->ray->mapy + 1.0 - \
		all->ray->posy) * all->ray->deltadisty;
	}
}

void	getwallhit(t_all *all, char **map)
{
	while (all->ray->hit == 0)
	{
		if (all->ray->sidedistx < all->ray->sidedisty)
		{
			all->ray->sidedistx += all->ray->deltadistx;
			all->ray->mapx += all->ray->stepx;
			all->ray->side = 0;
		}
		else
		{
			all->ray->sidedisty += all->ray->deltadisty;
			all->ray->mapy += all->ray->stepy;
			all->ray->side = 1;
		}
		if (map[all->ray->mapx][all->ray->mapy] != '0' &&
				map[all->ray->mapx][all->ray->mapy] != 'P')
			all->ray->hit = 1;
	}
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

void	getdrawpos(t_all *all, char **map, int *ii)
{
	extracheck(all);
	if (all->mlx->drawend >= WIN_HEIGHT)
		all->mlx->drawend = WIN_HEIGHT - 1;
	if (all->ray->side == 0 && map[(int)all->ray->mapx]
		[(int)all->ray->mapy] == '1')
	{
		all->ray->wallx = all->ray->posy + all
			->ray->perpwalldist * all->ray->raydiry;
		if (all->ray->raydirx > 0)
			*ii = 2;
		else
			*ii = 1;
	}
	else
	{
		all->ray->wallx = all->ray->posx + all
			->ray->perpwalldist * all->ray->raydirx;
		if (all->ray->raydiry > 0)
			*ii = 3;
		else
			*ii = 4;
	}
}
