/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:26:43 by isaad             #+#    #+#             */
/*   Updated: 2022/11/11 07:23:11 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	check_wall_collisions_x(t_all *all)
{
	double	checker;
	int		flag;

	flag = 0;
	checker = 0.1;
	while (checker <= all->size->movespeed)
	{
		if (all->map[(int)
				(all->size->posx + all->size->dirx * all->size->movespeed)]
			[(int)(all->size->posy)] == '1')
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

void	keyup(t_all *all)
{
	if (all->size->updown < all->size->win_y)
	{
		all->size->updown += 7;
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		print_plz(all, all->map);
	}
}

void	keydown(t_all *all)
{
	if ((all->size->updown * -1) < all->size->win_y)
	{
		all->size->updown -= 7;
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		print_plz(all, all->map);
	}
}

void	key123(t_all *all)
{
	double	olddirx;
	double	oldplanex;

	olddirx = all->size->dirx;
	oldplanex = all->size->planex;
	all->size->dirx = all->size->dirx * cos(all->size->rotspeed) - \
	all->size->diry * sin(all->size->rotspeed);
	all->size->diry = olddirx * sin(all->size->rotspeed)
		+ all->size->diry * cos(all->size->rotspeed);
	all->size->planex = all->size->planex * cos(all->size->rotspeed)
		- all->size->planey * sin(all->size->rotspeed);
	all->size->planey = oldplanex * sin(all->size->rotspeed)
		+ all->size->planey * cos(all->size->rotspeed);
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key124(t_all *all)
{
	double	olddirx;
	double	oldplanex;

	olddirx = all->size->dirx;
	oldplanex = all->size->planex;
	all->size->dirx = all->size->dirx * cos(-all->size->rotspeed) - \
	all->size->diry * sin(-all->size->rotspeed);
	all->size->diry = olddirx * sin(-all->size->rotspeed)
		+ all->size->diry * cos(-all->size->rotspeed);
	all->size->planex = all->size->planex * cos(-all->size->rotspeed) - \
	all->size->planey * sin(-all->size->rotspeed);
	all->size->planey = oldplanex * sin(-all->size->rotspeed) + \
	all->size->planey * cos(-all->size->rotspeed);
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}
