/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:34:41 by aalhmoud          #+#    #+#             */
/*   Updated: 2023/05/05 04:01:46 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_destroy_free(t_all *all)
{
	int	i;

	i = -1;
	if (all->mlx->mlx_win)
		mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
	if (all->mlx->tex)
		mlx_destroy_image(all->mlx->mlx, all->mlx->tex);
	if (all->mlx->tex2)
		mlx_destroy_image(all->mlx->mlx, all->mlx->tex2);
	if (all->mlx->tex3)
		mlx_destroy_image(all->mlx->mlx, all->mlx->tex3);
	if (all->mlx->tex4)
		mlx_destroy_image(all->mlx->mlx, all->mlx->tex4);
	if (all->mlx->buffer)
		while (++i < WIN_HEIGHT)
			free(all->mlx->buffer[i]);
	free(all->mlx->buffer);
	ft_free_all(all);
	exit(0);
}

void	ft_error(t_all *all, int error)
{
	ft_putstr_fd(RED, 2);
	if (error != 0)
		ft_putstr_fd("Error: ", 2);
	if (error == 2)
		ft_putstr_fd("Invalid map extension\n", 2);
	else if (error == 3)
		ft_putstr_fd("File reading failed\n", 2);
	else if (error == 4)
		ft_putstr_fd("Memory allocation failed\n", 2);
	else if (error == 5)
		ft_putstr_fd("Invalid Map\n", 2);
	else if (error == 6)
		ft_putstr_fd("Invalid Color\n", 2);
	else if (error == 7)
		ft_putstr_fd("Invalid chars in map\n", 2);
	else if (error == 8)
		ft_putstr_fd("Unclosed map\n", 2);
	else if (error == 9)
		ft_putstr_fd("Unclosed map on space\n", 2);
	ft_putstr_fd(RESET, 2);
	ft_destroy_free(all);
}

void	ft_free_all(t_all *all)
{
	if (all->map_file)
		free(all->map_file);
	if (all->mapl)
		free(all->mapl);
	ft_free_arr(all->splmap);
	ft_free_arr(all->textures);
	ft_free_arr(all->colors);
	ft_free_arr(all->map);
}
