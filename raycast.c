/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:23:16 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/05 03:50:35 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	getandfillwalls(t_all *all, int y, int x, int ii)
{
	all->ray->wallx = (double)all->ray->wallx - (int)all->ray->wallx;
	all->mlx->texx = (int)(all->ray->wallx * (double)64);
	if (all->ray->side == 0 && all->ray->raydirx > 0)
		all->mlx->texx = 64 - all->mlx->texx - 1;
	if (all->ray->side == 1 && all->ray->raydiry < 0)
		all->mlx->texx = 64 - all->mlx->texx - 1;
	all->ray->step = 1.0 * 64 / all->mlx->lineheight;
	all->ray->texpos = (all->mlx->drawstart - ((WIN_HEIGHT / 2)
				+ all->ray->updown) + all->mlx->lineheight / 2)
		* all->ray->step;
	y = all->mlx->drawstart;
	while (y < all->mlx->drawend)
	{
		all->mlx->texy = (int)all->ray->texpos & (64 - 1);
		all->ray->texpos += all->ray->step;
		gettexture(all, ii);
		all->mlx->buffer[y][x] = all->ray->color;
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
	all->mlx->buffer = malloc(sizeof(int *) * WIN_HEIGHT);
	while (xx < WIN_HEIGHT)
	{
		all->mlx->buffer[xx] = malloc(sizeof(int) * WIN_WIDTH);
		xx++;
	}
}

void	clearbuffer(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
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
	while (x < WIN_WIDTH)
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
	all->pl->movespeed = 0.12;
	all->pl->rt_s = 0.055;
	return (0);
}
