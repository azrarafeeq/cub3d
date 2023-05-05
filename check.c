/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:29:08 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/05 03:36:59 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_pos(char c, t_all *all)
{
	if (c == 'N')
		all->pl->compass = 0;
	if (c == 'E')
		all->pl->compass = 1;
	if (c == 'S')
		all->pl->compass = 2;
	if (c == 'W')
		all->pl->compass = 3;
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
	{
		direction(all->pl);
		all->detector_flag++;
	}
	if (all->detector_flag > 1)
		ft_error(all, 5);
}

void	ft_check_walls(t_all *all)
{
	int	i;

	i = -1;
	while (all->map[++i])
		if ((all->map[i][0] != '1' && all->map[i][0] != ' ')
			|| (all->map[i][ft_strlen(all->map[i]) - 1] != '1'
			&& all->map[i][ft_strlen(all->map[i]) - 1] != ' '))
			ft_error(all, 8);
	i = -1;
	while (++i < (int)ft_strlen(all->map[0]))
		if (all->map[0][i] != '1' && all->map[0][i] != ' ')
			ft_error(all, 8);
	i = -1;
	while (++i < (int)ft_strlen(all->map[ft_arr_len(all->map) - 1]))
		if (all->map[ft_arr_len(all->map) - 1][i] != '1'
		&& all->map[ft_arr_len(all->map) - 1][i] != ' ')
			ft_error(all, 8);
}

void	ft_check_space(t_all *all, int i, int a)
{
	while (all->map[++a])
	{
		i = -1;
		while (all->map[a][++i])
		{
			if (all->map[a][i] == ' ')
			{
				if (all->map[a][i + 1] && (all->map[a][i + 1] != '1'
					&& all->map[a][i + 1] != ' '))
					ft_error(all, 9);
				if (i != 0 && all->map[a][i - 1] && (all->map[a][i - 1] != '1'
					&& all->map[a][i - 1] != ' '))
					ft_error(all, 9);
				if (all->map[a + 1] && all->map[a + 1][i]
					&& (all->map[a + 1][i] != '1' && all->map[a + 1][i] != ' '))
					ft_error(all, 9);
				if (a != 0 && all->map[a - 1] && all->map[a - 1][i]
				&& (all->map[a - 1][i] != '1' && all->map[a - 1][i] != ' '))
					ft_error(all, 9);
			}
		}
	}
}

void	ft_check_zero(t_all *all)
{
	int	i;
	int	a;

	a = -1;
	while (all->map[++a])
	{
		i = -1;
		while (all->map[a][++i])
		{
			if (all->map[a][i] == '0')
			{
				if (!all->map[a][i + 1] || (all->map[a][i + 1] == ' '))
					ft_error(all, 8);
				if (i != 0 && (!all->map[a][i - 1]
					|| all->map[a][i - 1] == ' '))
					ft_error(all, 8);
				if (all->map[a + 1] && (!all->map[a + 1][i]
					|| all->map[a + 1][i] == ' '))
					ft_error(all, 8);
				if (a != 0 && all->map[a - 1] && (!all->map[a - 1][i]
					|| (all->map[a - 1][i] == ' ')))
					ft_error(all, 8);
			}
		}
	}
}

int	check_wall_collision(t_all *all, char c)
{
	double	checker;
	int		flag;

	flag = 0;
	checker = 0.1;
	while (checker <= all->pl->movespeed)
	{
		if (c == 'y')
		{
			if (all->map[(int)(all->pl->posx)][(int)
				(all->pl->posy + all->pl->diry * checker)] == '1')
				return (0);
		}
		else if (c == 'x')
			if (all->map[(int)(all->pl->posx + all->pl->dirx
					* all->pl->movespeed)][(int)(all->pl->posy)] == '1')
				return (0);
		checker += 0.1;
		if (checker > all->pl->movespeed && !flag)
		{
			checker = all->pl->movespeed;
			flag = 1;
		}
	}
	return (1);
}
