/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:34:41 by aalhmoud          #+#    #+#             */
/*   Updated: 2023/05/05 04:48:13 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_lnbr(int nbr, int base_lenght)
{
	int	x;
	int	pbase;

	if (nbr == 0)
		return (1);
	x = 1;
	pbase = 1;
	while (x <= nbr)
	{
		x = x * base_lenght;
		pbase++;
	}
	return (pbase - 1);
}

char	*ft_char(char *dest, char src)
{
	unsigned int	i;

	i = 0;
	while (dest[i])
		i++;
	dest[i++] = src;
	dest[i] = '\0';
	return (dest);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	i;
	int	j;
	int	fnb;
	int	sign;

	i = 0;
	fnb = 0;
	sign = 0;
	while (nbr[i] && (nbr[i] == ' ' || nbr[i] == '\f'
			|| nbr[i] == '\n' || nbr[i] == '\t' || nbr[i] == '\v'))
		i++;
	while (nbr[i] && (nbr[i] == '+' || nbr[i] == '-'))
		if (nbr[i++] == '-')
			sign++;
	while (nbr[i] && ft_strchr(base_from, nbr[i]))
	{
		j = 0;
		while (base_from[j])
			if (base_from[j++] == nbr[i])
				fnb = fnb * ft_strlen(base_from) + j - 1;
		i++;
	}
	return (ft_put_nbr(fnb, base_to, sign, -1));
}

size_t	ft_atoi_index(t_all *all, const char *str, size_t i, int error)
{
	size_t	nb;

	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (nb >= 9223372036854775807)
			ft_error(all, error);
		nb = nb * 10 + str[i++] - 48;
	}
	return (nb);
}
