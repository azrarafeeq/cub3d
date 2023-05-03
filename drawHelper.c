/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawHelper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:29:34 by isaad             #+#    #+#             */
/*   Updated: 2022/11/11 07:54:47 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	initdir(t_all *all)
{
	if (all->size->raydirx < 0)
	{
		all->size->stepx = -1;
		all->size->sidedistx = (all->size->posx - \
		all->size->mapx) * all->size->deltadistx;
	}
	else
	{
		all->size->stepx = 1;
		all->size->sidedistx = (all->size->mapx + 1.0 - \
		all->size->posx) * all->size->deltadistx;
	}
	if (all->size->raydiry < 0)
	{
		all->size->stepy = -1;
		all->size->sidedisty = (all->size->posy - \
		all->size->mapy) * all->size->deltadisty;
	}
	else
	{
		all->size->stepy = 1;
		all->size->sidedisty = (all->size->mapy + 1.0 - \
		all->size->posy) * all->size->deltadisty;
	}
}

void	getwallhit(t_all *all, char **map)
{
	while (all->size->hit == 0)
	{
		if (all->size->sidedistx < all->size->sidedisty)
		{
			all->size->sidedistx += all->size->deltadistx;
			all->size->mapx += all->size->stepx;
			all->size->side = 0;
		}
		else
		{
			all->size->sidedisty += all->size->deltadisty;
			all->size->mapy += all->size->stepy;
			all->size->side = 1;
		}
		if (map[all->size->mapx][all->size->mapy] != '0' &&
				map[all->size->mapx][all->size->mapy] != 'P')
			all->size->hit = 1;
	}
}

void	extracheck(t_all *all)
{
	if (all->size->side == 0)
		all->size->perpwalldist = (all->size->sidedistx
				- all->size->deltadistx);
	else
		all->size->perpwalldist = (all->size->sidedisty
				- all->size->deltadisty);
	all->mlx->lineheight = (int)(all->size->win_y / all->size->perpwalldist);
	all->mlx->drawstart = -all->mlx->lineheight / 2
		+ ((all->size->win_y / 2) + all->size->updown);
	if (all->mlx->drawstart < 0)
		all->mlx->drawstart = 0;
	all->mlx->drawend = all->mlx->lineheight / 2
		+ ((all->size->win_y / 2) + all->size->updown);
}

void	getdrawpos(t_all *all, char **map, int *ii)
{
	extracheck(all);
	if (all->mlx->drawend >= all->size->win_y)
		all->mlx->drawend = all->size->win_y - 1;
	if (all->size->side == 0 && map[(int)all->size->mapx]
		[(int)all->size->mapy] == '1')
	{
		all->size->wallx = all->size->posy + all
			->size->perpwalldist * all->size->raydiry;
		if (all->size->raydirx > 0)
			*ii = 2;
		else
			*ii = 1;
	}
	else
	{
		all->size->wallx = all->size->posx + all
			->size->perpwalldist * all->size->raydirx;
		if (all->size->raydiry > 0)
			*ii = 3;
		else
			*ii = 4;
	}
}
