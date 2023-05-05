/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:34:41 by aalhmoud          #+#    #+#             */
/*   Updated: 2023/05/05 04:10:44 by arafeeq          ###   ########.fr       */
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

size_t	ft_wordcount(char *str)
{
	size_t	nb;
	size_t	i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == '\n')
			i++;
		if (str[i] && str[i] != '\n')
			nb++;
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (nb);
}

char	**ft_split_all(char *str, t_all *all)
{
	char	**ret;
	size_t	wordc;
	size_t	i;
	size_t	x;

	wordc = ft_wordcount(str);
	ret = (char **)malloc((wordc + 1) * sizeof(char *));
	if (!ret)
		ft_error(all, 4);
	i = 0;
	while (i < wordc)
	{
		while (*str && *str == '\n')
			str++;
		x = 0;
		while (str[x] && str[x] != '\n')
			x++;
		ret[i] = (char *)malloc(x + 1);
		x = 0;
		while (*str && *str != '\n')
			ret[i][x++] = *str++;
		ret[i++][x] = 0;
	}
	ret[i] = NULL;
	return (ret);
}

int	ft_find_index(t_all *all, char **arr, char *s, size_t size)
{
	int	i;

	i = 0;
	if (!arr)
		ft_error(all, 5);
	while (arr[i] && i < 6)
	{
		if (!ft_strncmp(arr[i], s, size))
			return (i);
		i++;
	}
	ft_error(all, 5);
	return (i);
}
