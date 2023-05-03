/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:26:33 by isaad             #+#    #+#             */
/*   Updated: 2022/11/11 03:48:11 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	check_wall_collisions_y(t_all *all)
{
	double	checker;
	int		flag;

	flag = 0;
	checker = 0.1;
	while (checker <= all->size->movespeed)
	{
		if (all->map[(int)
				(all->size->posx)][(int)
			(all->size->posy + all->size->diry * checker)] == '1')
			return (0);
		checker += 0.1;
		if (checker > all->size->movespeed && !flag)
		{
			checker = all->size->movespeed;
			flag = 1;
		}
	}
	return (1);
}

void	key13(t_all *all)
{
	if (check_wall_collisions_x(all))
		all->size->posx += all->size->dirx * all->size->movespeed;
	if (check_wall_collisions_y(all))
		all->size->posy += all->size->diry * all->size->movespeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key0(t_all *all)
{
	if (all->map[(int)
			(all->size->posx - all->size->diry * all->size->movespeed)]
		[(int)(all->size->posy)] != '1')
		all->size->posx -= all->size->diry * all->size->movespeed;
	if (all->map[(int)(all->size->posx)]
		[(int)(all->size->posy
			+ all->size->dirx * all->size->movespeed)] != '1')
			all->size->posy += all->size->dirx * all->size->movespeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key1(t_all *all)
{
	if (all->map[(int)(all->size->posx - all->size->dirx
			* all->size->movespeed)][(int)(all->size->posy)] != '1')
				all->size->posx -= all->size->dirx * all->size->movespeed;
	if (all->map[(int)(all->size->posx)]
		[(int)(all->size->posy - all->size->diry
			* all->size->movespeed)] != '1')
			all->size->posy -= all->size->diry * all->size->movespeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key2(t_all *all)
{
	if (all->map[(int)(all->size->posx + all->size->diry
			* all->size->movespeed)][(int)(all->size->posy)] != '1')
				all->size->posx += all->size->diry * all->size->movespeed;
	if (all->map[(int)(all->size->posx)]
		[(int)(all->size->posy - all->size->dirx
			* all->size->movespeed)] != '1')
			all->size->posy -= all->size->dirx * all->size->movespeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}
