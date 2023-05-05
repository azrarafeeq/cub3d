/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:23:16 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/05 06:08:16 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key13_1(t_all *all, int keycode)
{
	if (keycode == 13)
	{
		if (check_wall_collision(all, 'x'))
			all->pl->posx += all->pl->dirx * all->pl->movespeed;
		if (check_wall_collision(all, 'y'))
			all->pl->posy += all->pl->diry * all->pl->movespeed;
	}
	else if (keycode == 1)
	{
		if (all->map[(int)(all->pl->posx - all->pl->dirx
				* all->pl->movespeed)][(int)(all->pl->posy)] != '1')
			all->pl->posx -= all->pl->dirx * all->pl->movespeed;
		if (all->map[(int)(all->pl->posx)][(int)(all->pl->posy
			- all->pl->diry * all->pl->movespeed)] != '1')
			all->pl->posy -= all->pl->diry * all->pl->movespeed;
	}
}

void	key0_2(t_all *all, int keycode)
{
	if (keycode == A)
	{
		if (all->map[(int)(all->pl->posx - all->pl->diry
				* all->pl->movespeed)][(int)(all->pl->posy)] != '1')
			all->pl->posx -= all->pl->diry * all->pl->movespeed;
		if (all->map[(int)(all->pl->posx)][(int)(all->pl->posy
				+ all->pl->dirx * all->pl->movespeed)] != '1')
			all->pl->posy += all->pl->dirx * all->pl->movespeed;
	}
	else if (keycode == D)
	{
		if (all->map[(int)(all->pl->posx + all->pl->diry
				* all->pl->movespeed)][(int)(all->pl->posy)] != '1')
			all->pl->posx += all->pl->diry * all->pl->movespeed;
		if (all->map[(int)(all->pl->posx)][(int)(all->pl->posy
				- all->pl->dirx * all->pl->movespeed)] != '1')
			all->pl->posy -= all->pl->dirx * all->pl->movespeed;
	}
}

void	key124_123(t_all *a, int keycode)
{
	double	odx;
	double	opx;

	if (keycode == 124)
	{
		odx = a->pl->dirx;
		opx = a->pl->plnx;
		a->pl->dirx = a->pl->dirx * cos(-a->pl->rt_s)
			- a->pl->diry * sin(-a->pl->rt_s);
		a->pl->diry = odx * sin(-a->pl->rt_s) + a->pl->diry * cos(-a->pl->rt_s);
		a->pl->plnx = a->pl->plnx * cos(-a->pl->rt_s)
			- a->pl->plny * sin(-a->pl->rt_s);
		a->pl->plny = opx * sin(-a->pl->rt_s) + a->pl->plny * cos(-a->pl->rt_s);
	}
	else if (keycode == 123)
	{
		odx = a->pl->dirx;
		opx = a->pl->plnx;
		a->pl->dirx = a->pl->dirx * cos(a->pl->rt_s)
			- a->pl->diry * sin(a->pl->rt_s);
		a->pl->diry = odx * sin(a->pl->rt_s) + a->pl->diry * cos(a->pl->rt_s);
		a->pl->plnx = a->pl->plnx * cos(a->pl->rt_s)
			- a->pl->plny * sin(a->pl->rt_s);
		a->pl->plny = opx * sin(a->pl->rt_s) + a->pl->plny * cos(a->pl->rt_s);
	}
}

int	key(int keycode, t_all *all)
{
	if (keycode == ESC)
		ft_destroy_free(all);
	if (keycode == W || keycode == S)
		key13_1(all, keycode);
	if (keycode == A || keycode == D)
		key0_2(all, keycode);
	if (keycode == UP_ARROW)
		if (all->ray->updown < WIN_HEIGHT)
			all->ray->updown += 7;
	if (keycode == DOWN_ARROW)
		if ((all->ray->updown * -1) < WIN_HEIGHT)
			all->ray->updown -= 7;
	if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW)
		key124_123(all, keycode);
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	ray_cast(all, all->map);
	return (0);
}
