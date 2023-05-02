/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_parsing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:34:41 by aalhmoud          #+#    #+#             */
/*   Updated: 2023/05/02 12:21:29 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
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

static size_t	ft_countint(int n, size_t len)
{
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static size_t	ft_check_neg(int n)
{
	if (n > 0)
		return (0);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	size_t	len;

	nb = n;
	len = ft_check_neg(n);
	if (nb < 0)
		nb = -nb;
	len = ft_countint(n, len);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len--] = '\0';
	while (nb > 0)
	{
		str[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (!len && !str[1])
		str[len] = '0';
	else if (!len && str[1])
		str[len] = '-';
	return (str);
}
