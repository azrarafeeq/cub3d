/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:34:49 by isaad             #+#    #+#             */
/*   Updated: 2022/11/13 18:05:30 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	drawall(t_all *all, int **buffer)
{
	int	i;
	int	j;
	int	*texture;

	i = 0;
	j = 0;
	editbuffer(all, &buffer);
	all->mlx->img = mlx_new_image(all->mlx->mlx,
			all->size->win_x, all->size->win_y);
	texture = (int *)mlx_get_data_addr(all->mlx->img, &all->mlx->b,
			&all->mlx->w, &all->mlx->h);
	while (j < all->size->win_y)
	{
		i = 0;
		while (i < all->size->win_x)
		{
			texture[j * all->size->win_x + i] = buffer[j][i];
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(all->mlx->mlx,
		all->mlx->mlx_win, all->mlx->img, 0, 0);
	draw_sprites(all);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
}

void	filldown(t_all *all, int y, int x)
{
	while (y < all->size->win_y)
	{
		if (all->mlx->drawend < 0 || all->mlx->drawend < all->mlx->drawstart)
			break ;
		all->mlx->buffer[y][x] = all->mlx->fcolor;
		y++;
	}
}

void	fill_the_void(t_all *all, int y, int x)
{
	while (y < all->mlx->drawstart)
	{
		if (all->mlx->drawstart < 0 || all->mlx->drawstart > all->mlx->drawend)
			break ;
		all->mlx->buffer[y][x] = all->mlx->ccolor;
		y++;
	}
	y = all->mlx->drawend;
	filldown(all, y, x);
	y = 0;
	while (y < all->size->win_y)
	{
		if (all->mlx->buffer[y][x] == 0 && all->size->updown > 0 && \
		(y < all->mlx->drawstart || y > all->mlx->drawend))
			all->mlx->buffer[y][x] = all->mlx->ccolor;
		if (all->mlx->buffer[y][x] == 0 && all->size->updown < 0 && \
		(y < all->mlx->drawstart || y > all->mlx->drawend))
			all->mlx->buffer[y][x] = all->mlx->fcolor;
		y++;
	}
}

void	gettexture(t_all *all, int ii)
{
	if (ii == 1)
		all->size->color = mlx_get_color_value(all->mlx->mlx, all->mlx->text
			[(64 * all->mlx->texy) + all->mlx->texx]);
	else if (ii == 2)
		all->size->color = mlx_get_color_value(all->mlx->mlx, all->mlx
				->text2[(64 * all->mlx->texy) + all->mlx->texx]);
	else if (ii == 3)
		all->size->color = mlx_get_color_value(all->mlx->mlx, all->mlx
				->text3[(64 * all->mlx->texy) + all->mlx->texx]);
	else if (ii == 4)
		all->size->color = mlx_get_color_value(all->mlx->mlx, all->mlx
				->text4[(64 * all->mlx->texy) + all->mlx->texx]);
}
