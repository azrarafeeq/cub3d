/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhmoud <aalhmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:34:41 by aalhmoud          #+#    #+#             */
/*   Updated: 2023/05/01 22:35:41 by aalhmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

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
