/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:34:41 by aalhmoud          #+#    #+#             */
/*   Updated: 2023/05/02 22:31:05 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map_valid_structure(t_all *all, int *i, size_t *nl)
{
	while (all->mapl[++(*i)] && *nl < 7)
	{
		if (all->mapl[*i] == '\n')
			*i = *i + 1;
		else if (all->mapl[*i] != '\n')
		{
			*nl = *nl + 1;
			while (all->mapl[*i] != '\n')
				*i = *i + 1;
		}
	}
}

void	ft_map_valid_char(t_all *all, int i, size_t nl)
{
	ft_map_valid_structure(all, &i, &nl);
	while (all->mapl[i])
	{
		if (all->mapl[i] == '1' || all->mapl[i] == '0' || all->mapl[i] == 'N'
			|| all->mapl[i] == 'S' || all->mapl[i] == 'E' || all->mapl[i] == 'W'
			|| all->mapl[i] == ' ' || all->mapl[i] == '\n')
		{
			check_pos(all->mapl[i], all);
			if (all->mapl[i] == '\n'
				&& all->mapl[i + 1] == '\n' && all->mapl[i + 2])
				ft_error(all, 8);
		}
		else
			ft_error(all, 7);
		i++;
	}
}

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

