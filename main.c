/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:51:24 by arafeeq           #+#    #+#             */
/*   Updated: 2023/04/30 15:00:12 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	//t_cub	*cub;
	t_map	*map;
	int i = 0;
	int j = 0;

	//parse
	map = malloc(sizeof(t_map));
	get_map(map, argv[1]);
	printf("map height = %d\n", map->height);
	while (i < map->height)
	{
		while (j < map->width)
		{
			printf("%d ", map->map_2d[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	// cub = malloc(sizeof(t_cub));
	// cub->i = malloc(sizeof(t_image));
	// cub->mlx = mlx_init();
	// cub->win = mlx_new_window(cub->mlx, 1000, 800, "Cub3D");
	// cub->i->i = mlx_new_image(cub->mlx, 1000, 800);
	// cub->i->addr = mlx_get_data_addr(cub->i->i, &cub->i->bpp, &cub->i->l_len, &cub->i->e);
	// mlx_put_image_to_window(cub->mlx, cub->win, cub->i->i, 0, 0);
	// mlx_loop(cub->mlx);

	//----FREE----
	// free(cub->i);
	// free(cub);
	return(0);
}

// int main(int argc, char **argv)
// {
// 	printf("argc = %d\n", argc);
// 	printf("op = %s\n" ,argv[2]);
// 	return (0);
// }