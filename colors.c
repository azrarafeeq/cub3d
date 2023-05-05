/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:34:41 by aalhmoud          #+#    #+#             */
/*   Updated: 2023/05/05 03:28:32 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_color_chars_init_checker(t_all *all)
{
	if (all->colors[0][0] != 'F' || all->colors[1][0] != 'C'
		|| all->colors[0][1] != ' ' || all->colors[1][1] != ' ')
		ft_error(all, 6);
}

void	ft_color_chars_checker(t_all *all, size_t i, size_t a, int comma)
{
	ft_color_chars_init_checker(all);
	while (a < 2)
	{
		comma = 0;
		i = 2;
		while (all->colors[a][i] == ' ')
			i++;
		while (all->colors[a][i])
		{
			if (!ft_isdigit(all->colors[a][i]))
				ft_error(all, 6);
			if (ft_atoi_index(all, all->colors[a], i, 6) > 255
				|| ft_atoi_index(all, all->colors[a], i, 6) < 0)
				ft_error(all, 6);
			while (all->colors[a][i] && ft_isdigit(all->colors[a][i]))
				i++;
			if (all->colors[a][i] && all->colors[a][i] == ',')
				comma++;
			if (all->colors[a][i] &&
				(all->colors[a][i] != ',' || !ft_isdigit(all->colors[a][++i])))
				ft_error(all, 6);
		}
		if (++a && comma != 2)
			ft_error(all, 6);
	}
}

char	*ft_rgb_to_hex(t_all *all, char *rgb, size_t i)
{
	char	*color;
	int		tmp;

	color = ft_strdup("");
	tmp = 255;
	while (rgb[i] == ' ')
		i++;
	while (rgb[i])
	{
		tmp = ft_atoi_index(all, rgb, i, 6);
		color = ft_strjoin(color, ft_convert_base(ft_itoa(tmp), DEC, HEX));
		while (rgb[i] && ft_isdigit(rgb[i]))
			i++;
		if (rgb[i] && rgb[i] == ',')
			i++;
	}
	return (color);
}

void	ft_putnbr_base(int nbr, int nbase, char *num_base, char *base)
{
	if (nbr >= nbase)
	{
		ft_putnbr_base((nbr / nbase), nbase, num_base, base);
	}
	ft_char(num_base, base[nbr % nbase]);
}

char	*ft_put_nbr(int nbr, char *base, int sign, int i)
{
	int		nbase;
	int		pbase;
	char	*num;

	nbase = ft_strlen(base);
	pbase = ft_lnbr(nbr, nbase);
	if (sign % 2 != 0 && nbr != 0)
	{
		num = malloc((pbase + 2) * sizeof(char));
		if (!num)
			return (0);
		while (++i < pbase + 2)
			num[i] = '\0';
		num[0] = '-';
	}
	else
	{
		num = malloc((pbase + 1) * sizeof(char));
		if (!num)
			return (0);
		while (++i < pbase + 1)
			num[i] = '\0';
	}
	ft_putnbr_base(nbr, nbase, num, base);
	return (num);
}
