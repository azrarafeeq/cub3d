/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MKcmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:26:23 by isaad             #+#    #+#             */
/*   Updated: 2022/11/13 18:05:39 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

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

int	mouse(int x, int y, t_all *all)
{
	static int	xx;
	static int	yy;

	if (y > yy && (y < all->size->win_y && y > 0) && \
	(x < all->size->win_x && x > 0))
		if ((all->size->updown * -1) < all->size->win_y)
			all->size->updown -= 7;
	if (y < yy && (y < all->size->win_y && y > 0) && \
	(x < all->size->win_x && x > 0))
		if (all->size->updown < all->size->win_y)
			all->size->updown += 7;
	if (x > xx && (x < all->size->win_x && x > 0) && \
	(y < all->size->win_y && y > 0))
		key124_123(all, 124);
	if (x < xx && x > 0 && (y < all->size->win_y && y > 0) && \
	(x < all->size->win_x && x > 0))
		key124_123(all, 123);
	xx = x;
	yy = y;
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (keycode == 1 && all->flag == 0 && y > 0)
	{
		all->flag = 1;
		ray_cast(all, all->map);
	}
	else if (y > 0)
	{
		all->flag = 0;
		ray_cast(all, all->map);
	}
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
