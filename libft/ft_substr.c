/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:33:27 by arafeeq           #+#    #+#             */
/*   Updated: 2022/06/12 16:55:15 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	x;
	size_t	l;

	i = start;
	x = 0;
	if (!s)
		return (0);
	l = ft_strlen(s);
	if (len > l)
		len = l;
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	while (i < l && x < len)
		ret[x++] = s[i++];
	ret[x] = 0;
	return (ret);
}
