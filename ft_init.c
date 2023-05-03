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

void	extra_imgs(t_all *all)
{
	all->mlx->tex3 = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[2], &all->mlx->w, &all->mlx->h);
	all->mlx->text3 = (int *)mlx_get_data_addr(all->mlx->tex3,
			&all->mlx->b, &all->mlx->h, &all->mlx->w);
	all->mlx->tex4 = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[3], &all->mlx->w, &all->mlx->h);
	all->mlx->text4 = (int *)mlx_get_data_addr(all->mlx->tex4,
			&all->mlx->b, &all->mlx->h, &all->mlx->w);
	all->mlx->tex5 = mlx_xpm_file_to_image(all->mlx->mlx, \
		"Imgs/gun.xpm", &all->mlx->w, &all->mlx->h);
	all->mlx->tex6 = mlx_xpm_file_to_image(all->mlx->mlx, \
		"Imgs/gunshoot.xpm", &all->mlx->w, &all->mlx->h);
}

void	draw_sprites(t_all *all)
{
	if (all->flag == 0)
		mlx_put_image_to_window(all->mlx->mlx,
			all->mlx->mlx_win, all->mlx->tex5, all->size->\
				win_x / 2, all->size->win_y / 2);
	if (all->flag == 1)
		mlx_put_image_to_window(all->mlx->mlx,
			all->mlx->mlx_win, all->mlx->tex6, all->\
				size->win_x / 2, all->size->win_y / 2);
}

