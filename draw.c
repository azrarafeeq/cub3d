/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:29:26 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/01 21:10:56 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_cub **cub, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x < (*cub)->win_width && y < (*cub)->win_length))
	{
		dst = (*cub)->i->addr + (y * (*cub)->i->l_len + x
				* ((*cub)->i->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	zoom(t_coords *c, t_cub **cub)
{
	c->x *= (*cub)->zoom;
	c->y *= (*cub)->zoom;
}

void	draw(t_cub **cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	(void)cub;
	while (y < (*cub)->map->height)
	{
		while (x < (*cub)->map->width)
		{
			bressenham(x, y, 'a', cub, 0, 0); //vertical lines
			bressenham(x, y + 1, 'a', cub, 1, 0);
			bressenham(x, y, 'z', cub, 0, 0); //horizontal lines
			bressenham(x + 1, y, 'z', cub, 0, 1);
			x++;
		}
		x = 0;
		y++;
	}
}
