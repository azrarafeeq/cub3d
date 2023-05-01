/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bressenham.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:38:20 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/01 21:06:12 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	bressenham(int x1, int y1, char flag, t_cub **cub, int minusy, int minusx)
{
	t_coords	c1;
	t_coords	c2;
	int			ints[3];

	initialize_x_y(&c1, x1, y1, 'r');
	initialize_x_y(&c2, x1, y1, flag);
	ints[0] = (int)c2.x;
	ints[1] = (int)c2.y;
	if (x1 >= (*cub)->map->width)
		ints[2] = (*cub)->map->map_2d[y1][x1 - 1];
	else if (y1 >= (*cub)->map->height)
		ints[2] = (*cub)->map->map_2d[y1 - 1][x1];
	else if (minusy)
		ints[2] = ((*cub)->map->map_2d[y1 - 1][x1]);
	else if (minusx)
		ints[2] = ((*cub)->map->map_2d[y1][x1 - 1]);
	else
		ints[2] = (*cub)->map->map_2d[y1][x1];
	// zoom(&c1, cub);
	// zoom(&c2, cub);
	c1.x *= (*cub)->zoom;
	c1.y *= (*cub)->zoom;
	c2.x *= (*cub)->zoom;
	c2.y *= (*cub)->zoom;
	if (minusy)
	{
		c1.y += ((y1 - 1) * 10);
		c2.y += ((y1 - 1) * 10);
		c1.x += (x1 * 10);
		c2.x += (x1 * 10);
	}
	else if (minusx)
	{
		c1.y += (y1 * 10);
		c2.y += (y1 * 10);
		c1.x += ((x1 - 1) * 10);
		c2.x += ((x1 - 1) * 10);
	}
	else
	{
		c1.y += (y1 * 10);
		c2.y += (y1 * 10);
		c1.x += (x1 * 10);
		c2.x += (x1 * 10);
	}
	(*cub)->b_alg = allocate_balg(&c1.x, &c1.y, &c2.x, &c2.y);
	//printf("(*cub)->b_alg->delta_x = %f\n", (*cub)->b_alg->delta_x);
	while (++(*cub)->b_alg->i < (*cub)->b_alg->delta_x)
	{
		if (ints[2] == 0)
			my_mlx_pixel_put(cub, c1.x, c1.y, 0xff0000);
		else if (ints[2] == 2)
			my_mlx_pixel_put(cub, c1.x, c1.y, 0x688b);
		else
			my_mlx_pixel_put(cub, c1.x, c1.y, 0xf8f8ff);
		bressenham_part_2((*cub)->b_alg, &c1.x, &c1.y);
	}
	free((*cub)->b_alg);
}

void	bressenham_part_2(t_balg *b_alg, double *x, double *y)
{
	while (b_alg->diff >= 0)
	{
		b_alg->diff = b_alg->diff - 2 * b_alg->delta_x;
		if (b_alg->swap)
			*x += b_alg->step_1;
		else
			*y += b_alg->step_2;
	}
	b_alg->diff = b_alg->diff + 2 * b_alg->delta_y;
	if (b_alg->swap)
		*y += b_alg->step_2;
	else
		*x += b_alg->step_1;
}

void	initialize_x_y(t_coords *c, int x1, int y1, char flag)
{
	c->x = x1;
	c->y = y1;
	if (flag == 'a')
		c->x = x1 + 1;
	else if (flag == 'z')
		c->y = y1 + 1;
}

int	swap_content(double *int1, double *int2)
{
	double	temp;

	if (*int2 > *int1)
	{
		temp = *int1;
		*int1 = *int2;
		*int2 = temp;
		return (1);
	}
	else
		return (0);
}

int	get_sign(double num)
{
	if (num < 0)
		return (-1);
	else
		return (1);
}
