/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:26:33 by isaad             #+#    #+#             */
/*   Updated: 2022/11/11 03:48:11 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	key13_1(t_all *all, int keycode)
{
	if (keycode == 13)
	{
		if (check_wall_collision(all, 'x'))
		all->size->posx += all->size->dirx * all->size->movespeed;
		if (check_wall_collisions(all, 'y'))
			all->size->posy += all->size->diry * all->size->movespeed;
	}
	else if (keycode == 1)
	{
		if (all->map[(int)(all->size->posx - all->size->dirx
			* all->size->movespeed)][(int)(all->size->posy)] != '1')
				all->size->posx -= all->size->dirx * all->size->movespeed;
		if (all->map[(int)(all->size->posx)]
			[(int)(all->size->posy - all->size->diry
				* all->size->movespeed)] != '1')
				all->size->posy -= all->size->diry * all->size->movespeed;
	}
	
}

void	key0_2(t_all *all, int keycode)
{
	if (key_code == A)
	{
		if (all->map[(int)
			(all->size->posx - all->size->diry * all->size->movespeed)]
		[(int)(all->size->posy)] != '1')
		all->size->posx -= all->size->diry * all->size->movespeed;
		if (all->map[(int)(all->size->posx)]
			[(int)(all->size->posy
				+ all->size->dirx * all->size->movespeed)] != '1')
				all->size->posy += all->size->dirx * all->size->movespeed;
	}
	else if (key_code == D)
	{
		if (all->map[(int)(all->size->posx + all->size->diry
			* all->size->movespeed)][(int)(all->size->posy)] != '1')
				all->size->posx += all->size->diry * all->size->movespeed;
		if (all->map[(int)(all->size->posx)]
			[(int)(all->size->posy - all->size->dirx
				* all->size->movespeed)] != '1')
				all->size->posy -= all->size->dirx * all->size->movespeed;
	}
}

void	key124_123(t_all *all)
{
	double	olddirx;
	double	oldplanex;

	if (keycode == 124)
	{
		olddirx = all->size->dirx;
		oldplanex = all->size->planex;
		all->size->dirx = all->size->dirx * cos(-all->size->rotspeed) - \
		all->size->diry * sin(-all->size->rotspeed);
		all->size->diry = olddirx * sin(-all->size->rotspeed)
			+ all->size->diry * cos(-all->size->rotspeed);
		all->size->planex = all->size->planex * cos(-all->size->rotspeed) - \
		all->size->planey * sin(-all->size->rotspeed);
		all->size->planey = oldplanex * sin(-all->size->rotspeed) + \
		all->size->planey * cos(-all->size->rotspeed);
	}
	else if (keycode == 123)
	{
		olddirx = all->size->dirx;
		oldplanex = all->size->planex;
		all->size->dirx = all->size->dirx * cos(all->size->rotspeed) - \
		all->size->diry * sin(all->size->rotspeed);
		all->size->diry = olddirx * sin(all->size->rotspeed)
			+ all->size->diry * cos(all->size->rotspeed);
		all->size->planex = all->size->planex * cos(all->size->rotspeed)
			- all->size->planey * sin(all->size->rotspeed);
		all->size->planey = oldplanex * sin(all->size->rotspeed)
			+ all->size->planey * cos(all->size->rotspeed);
	}
}
