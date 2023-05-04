/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:23:16 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/02 22:44:02 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	key(int keycode, t_all *all)
{
	if (keycode == ESC)
		ft_quit(all);
	if (keycode == W || keycode == S)
		key13_1(all, keycode);
	if (keycode == A || keycode == D)
		key0_2(all, keycode);
	if (keycode == UP_ARROW)
		if (all->size->updown < all->size->win_y)
			all->size->updown += 7;
	if (keycode == DOWN_ARROW)
		if ((all->size->updown * -1) < all->size->win_y)
			all->size->updown -= 7;
	if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW)
		key124_123(all, key_code);
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	ray_cast(all, all->map);
	return (0);
}

void	editbuffer(t_all *all, int ***buffer)
{
	int	i;

	i = 2;
	while (++i < 13)
		(*buffer)[all->size->win_y / 2 - i][all->size->win_x / 2] = 0xFF0000;
	i = 2;
	while (++i < 13)
		(*buffer)[all->size->win_y / 2 + i][all->size->win_x / 2] = 0xFF0000;
	i = 2;
	while (++i < 13)
		(*buffer)[all->size->win_y / 2][all->size->win_x / 2 - i] = 0xFF0000;
	i = 2;
	while (++i < 13)
		(*buffer)[all->size->win_y / 2][all->size->win_x / 2 + i] = 0xFF0000;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
}
