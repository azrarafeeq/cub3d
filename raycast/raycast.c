/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:23:16 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/02 22:44:02 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	getandfillwalls(t_all *all, int y, int x, int ii)
{
	all->size->wallx = (double)all->size->wallx - (int)all->size->wallx;
	all->mlx->texx = (int)(all->size->wallx * (double)64);
	if (all->size->side == 0 && all->size->raydirx > 0)
		all->mlx->texx = 64 - all->mlx->texx - 1;
	if (all->size->side == 1 && all->size->raydiry < 0)
		all->mlx->texx = 64 - all->mlx->texx - 1;
	all->size->step = 1.0 * 64 / all->mlx->lineheight;
	all->size->texpos = (all->mlx->drawstart - ((all->size->win_y / 2)
				+ all->size->updown) + all->mlx->lineheight / 2)
		* all->size->step;
	y = all->mlx->drawstart;
	while (y < all->mlx->drawend)
	{
		all->mlx->texy = (int)all->size->texpos & (64 - 1);
		all->size->texpos += all->size->step;
		gettexture(all, ii);
		all->mlx->buffer[y][x] = all->size->color;
		y++;
	}
}

void	initimgs(t_all *all)
{
	int	xx;

	xx = 0;
	all->mlx->tex = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[0], &all->mlx->w, &all->mlx->h);
	all->mlx->text = (int *)mlx_get_data_addr(all->mlx
			->tex, &all->mlx->b, &all->mlx->h, &all->mlx->w);
	all->mlx->tex2 = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[1], &all->mlx->w, &all->mlx->h);
	all->mlx->text2 = (int *)mlx_get_data_addr(all->mlx
			->tex2, &all->mlx->b, &all->mlx->h, &all->mlx->w);
	extra_imgs(all);
	all->mlx->buffer = malloc(sizeof(int *) * all->size->win_y);
	while (xx < all->size->win_y)
	{
		all->mlx->buffer[xx] = malloc(sizeof(int) * all->size->win_x);
		xx++;
	}
}

void	clearbuffer(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < all->size->win_y)
	{
		j = 0;
		while (j < all->size->win_x)
		{
			all->mlx->buffer[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	ray_cast(t_all *all, char **map)
{
	int	ii;
	int	x;
	int	y;

	ii = 0;
	x = 0;
	y = 0;
	clearbuffer(all);
	while (x < all->size->win_x)
	{
		initdrawing(all, x);
		initdir(all);
		getwallhit(all, map);
		getdrawpos(all, map, &ii);
		getandfillwalls(all, y, x, ii);
		fill_the_void(all, y, x);
		x++;
	}
	drawall(all, all->mlx->buffer);
	all->size->movespeed = 0.12;
	all->size->rotspeed = 0.055;
	return (0);
}
