/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:34:41 by aalhmoud          #+#    #+#             */
/*   Updated: 2023/05/05 04:26:05 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_arr_len(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

char	**ft_2d_dup(char **arr, size_t start, size_t size)
{
	size_t	i;
	size_t	j;
	char	**ret;

	if (!size)
		return (NULL);
	i = start;
	j = 0;
	ret = (char **)malloc((size + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	while ((i < (start + size)) && arr[i])
		ret[j++] = ft_strdup(arr[i++]);
	ret[j] = NULL;
	return (ret);
}

void	extra_imgs(t_all *all)
{
	all->mlx->tex3 = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[2], &all->mlx->w, &all->mlx->h);
	all->mlx->text3 = (int *)mlx_get_data_addr(all->mlx->tex3,
			&all->mlx->b, &all->mlx->h, &all->mlx->w);
	all->mlx->tex4 = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[3], &all->mlx->w, &all->mlx->h);
	all->mlx->text4 = (int *)mlx_get_data_addr(all->mlx->tex4,
			&all->mlx->b, &all->mlx->h, &all->mlx->w);
}

void	extracheck(t_all *all)
{
	if (all->ray->side == 0)
		all->ray->perpwalldist = (all->ray->sidedistx
				- all->ray->deltadistx);
	else
		all->ray->perpwalldist = (all->ray->sidedisty
				- all->ray->deltadisty);
	all->mlx->lineheight = (int)(WIN_HEIGHT / all->ray->perpwalldist);
	all->mlx->drawstart = -all->mlx->lineheight / 2
		+ ((WIN_HEIGHT / 2) + all->ray->updown);
	if (all->mlx->drawstart < 0)
		all->mlx->drawstart = 0;
	all->mlx->drawend = all->mlx->lineheight / 2
		+ ((WIN_HEIGHT / 2) + all->ray->updown);
}
