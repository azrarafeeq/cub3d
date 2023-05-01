/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:51:24 by arafeeq           #+#    #+#             */
/*   Updated: 2023/04/30 20:23:35 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	t_cub	*cub;
	int i = 0;
	int j = 0;

	//parse
	cub = malloc(sizeof(t_cub));
	cub->map = malloc(sizeof(t_map));
	get_map(cub->map, argv[1]);
	printf("map height = %d\n", cub->map->height);
	while (i < cub->map->height)
	{
		while (j < cub->map->width)
		{
			printf("%d ", cub->map->map_2d[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	cub->zoom = 64;
	cub->win_length = 1000;
	cub->win_width = 800;
	cub->i = malloc(sizeof(t_image));
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, cub->win_length, cub->win_width, "Cub3D");
	cub->i->i = mlx_new_image(cub->mlx, cub->win_length, cub->win_width);
	cub->i->addr = mlx_get_data_addr(cub->i->i, &cub->i->bpp, &cub->i->l_len, &cub->i->e);
	draw(&cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->i->i, 0, 0);
	mlx_loop(cub->mlx);

	//----FREE----
	// free(cub->i);
	// free(cub);
	return(0);
}

t_balg	*allocate_balg(double *x, double *y, double *x2, double *y2)
{
	t_balg	*b_alg;

	b_alg = malloc(sizeof(t_balg));
	b_alg->delta_x = fabs(*x2 - *x);
	b_alg->delta_y = fabs(*y2 - *y);
	b_alg->step_1 = get_sign(*x2 - *x);
	b_alg->step_2 = get_sign(*y2 - *y);
	b_alg->swap = swap_content(&b_alg->delta_x, &b_alg->delta_y);
	b_alg->diff = 2 * b_alg->delta_y - b_alg->delta_x;
	b_alg->i = -1;
	return (b_alg);
}
