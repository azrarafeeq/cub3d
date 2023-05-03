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
	if (keycode == W)
		key13(all);
	if (keycode == S)
		key1(all);
	if (keycode == A)
		key0(all);
	if (keycode == D)
		key2(all);
	if (keycode == UP_ARROW)
		keyup(all);
	if (keycode == DOWN_ARROW)
		keydown(all);
	if (keycode == RIGHT_ARROW)
		key124(all);
	if (keycode == LEFT_ARROW)
		key123(all);
	return (0);
}

int	mouse(int x, int y, t_all *all)
{
	static int	xx;
	static int	yy;

	if (y > yy && (y < all->size->win_y && y > 0) && \
	(x < all->size->win_x && x > 0))
		keydown(all);
	if (y < yy && (y < all->size->win_y && y > 0) && \
	(x < all->size->win_x && x > 0))
		keyup(all);
	if (x > xx && (x < all->size->win_x && x > 0) && \
	(y < all->size->win_y && y > 0))
		key124(all);
	if (x < xx && x > 0 && (y < all->size->win_y && y > 0) && \
	(x < all->size->win_x && x > 0))
		key123(all);
	xx = x;
	yy = y;
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
