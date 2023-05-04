/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:23:16 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/05 02:22:41 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key13_1(t_all *all, int keycode)
{
	if (keycode == 13)
	{
		if (check_wall_collision(all, 'x'))
		all->ray->posx += all->ray->dirx * all->ray->movespeed;
		if (check_wall_collision(all, 'y'))
			all->ray->posy += all->ray->diry * all->ray->movespeed;
	}
	else if (keycode == 1)
	{
		if (all->map[(int)(all->ray->posx - all->ray->dirx
			* all->ray->movespeed)][(int)(all->ray->posy)] != '1')
				all->ray->posx -= all->ray->dirx * all->ray->movespeed;
		if (all->map[(int)(all->ray->posx)]
			[(int)(all->ray->posy - all->ray->diry
				* all->ray->movespeed)] != '1')
				all->ray->posy -= all->ray->diry * all->ray->movespeed;
	}
}

void	key0_2(t_all *all, int keycode)
{
	if (keycode == A)
	{
		if (all->map[(int)
			(all->ray->posx - all->ray->diry * all->ray->movespeed)]
		[(int)(all->ray->posy)] != '1')
		all->ray->posx -= all->ray->diry * all->ray->movespeed;
		if (all->map[(int)(all->ray->posx)]
			[(int)(all->ray->posy
				+ all->ray->dirx * all->ray->movespeed)] != '1')
				all->ray->posy += all->ray->dirx * all->ray->movespeed;
	}
	else if (keycode == D)
	{
		if (all->map[(int)(all->ray->posx + all->ray->diry
			* all->ray->movespeed)][(int)(all->ray->posy)] != '1')
				all->ray->posx += all->ray->diry * all->ray->movespeed;
		if (all->map[(int)(all->ray->posx)]
			[(int)(all->ray->posy - all->ray->dirx
				* all->ray->movespeed)] != '1')
				all->ray->posy -= all->ray->dirx * all->ray->movespeed;
	}
}

void	key124_123(t_all *all, int keycode)
{
	double	olddirx;
	double	oldplanex;

	if (keycode == 124)
	{
		olddirx = all->ray->dirx;
		oldplanex = all->ray->planex;
		all->ray->dirx = all->ray->dirx * cos(-all->ray->rotspeed) - \
		all->ray->diry * sin(-all->ray->rotspeed);
		all->ray->diry = olddirx * sin(-all->ray->rotspeed)
			+ all->ray->diry * cos(-all->ray->rotspeed);
		all->ray->planex = all->ray->planex * cos(-all->ray->rotspeed) - \
		all->ray->planey * sin(-all->ray->rotspeed);
		all->ray->planey = oldplanex * sin(-all->ray->rotspeed) + \
		all->ray->planey * cos(-all->ray->rotspeed);
	}
	else if (keycode == 123)
	{
		olddirx = all->ray->dirx;
		oldplanex = all->ray->planex;
		all->ray->dirx = all->ray->dirx * cos(all->ray->rotspeed) - \
		all->ray->diry * sin(all->ray->rotspeed);
		all->ray->diry = olddirx * sin(all->ray->rotspeed)
			+ all->ray->diry * cos(all->ray->rotspeed);
		all->ray->planex = all->ray->planex * cos(all->ray->rotspeed)
			- all->ray->planey * sin(all->ray->rotspeed);
		all->ray->planey = oldplanex * sin(all->ray->rotspeed)
			+ all->ray->planey * cos(all->ray->rotspeed);
	}
}

int	key(int keycode, t_all *all)
{
	if (keycode == ESC)
		ft_quit(all);
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

void	editbuffer(t_all *all, int ***buffer)
{
	int	i;

	i = 2;
	while (++i < 13)
		(*buffer)[WIN_HEIGHT / 2 - i][WIN_WIDTH / 2] = 0xFF0000;
	i = 2;
	while (++i < 13)
		(*buffer)[WIN_HEIGHT / 2 + i][WIN_WIDTH / 2] = 0xFF0000;
	i = 2;
	while (++i < 13)
		(*buffer)[WIN_HEIGHT / 2][WIN_WIDTH / 2 - i] = 0xFF0000;
	i = 2;
	while (++i < 13)
		(*buffer)[WIN_HEIGHT / 2][WIN_WIDTH / 2 + i] = 0xFF0000;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
}
