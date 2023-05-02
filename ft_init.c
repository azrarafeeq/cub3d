/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:56:52 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/02 22:29:52 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_init(t_all *all, t_player *player)
{
	player->x = 1000 / 2; //for now
	player->y = 800 / 2; // for now
	player->width = 1;
	player->height = 1;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotation_angle = M_PI / 2;
	player->walk_speed = 100;
	player->turn_speed = 45 * (M_PI / 180);
	all->player = player;
}

void	all_struct_init(t_all *all, t_cub *cub, t_size *size)
{
	ft_bzero(cub, sizeof(t_cub));
	ft_bzero(size, sizeof(t_size));
	ft_bzero(all, sizeof(t_all));
	cub->win_length = 1000;
	cub->win_width = 800;
	cub->i = malloc(sizeof(t_image));
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx,
			cub->win_length, cub->win_width, "Cub3d");
	cub->i->i = mlx_new_image(cub->mlx,
			cub->win_length, cub->win_width);
	cub->i->addr = mlx_get_data_addr(cub->i->i,
			&cub->i->bpp, &cub->i->l_len, &cub->i->e);
	size->posx = 3;
	size->posy = 27;
	direction(size);
	size->win_x = 960;
	size->win_y = 540;
	all->cub = cub;
	all->size = size;
}

void	direction(t_size *size)
{
	where_0(size);
	if (size->where == 1)
	{
		size->dirx = 0;
		size->diry = 1;
		size->planex = 0.66;
		size->planey = 0;
	}
	else if (size->where == 2)
	{
		size->dirx = 1;
		size->diry = 0;
		size->planex = 0;
		size->planey = -0.66;
	}
	else if (size->where == 3)
	{
		size->dirx = 0;
		size->diry = -1;
		size->planex = -0.66;
		size->planey = 0;
	}
}

void	where_0(t_size *size)
{
	if (size->where == 0)
	{
		size->dirx = -1;
		size->diry = 0;
		size->planex = 0;
		size->planey = 0.66;
	}
}