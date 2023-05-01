/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhmoud <aalhmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:34:41 by aalhmoud          #+#    #+#             */
/*   Updated: 2023/05/01 22:35:29 by aalhmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	ft_quit(t_all *all)
{
	int	i;
	int	excode;

	i = -1;
	excode = all->exit;
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
	if (all->mlx->tex5)
		mlx_destroy_image(all->mlx->mlx, all->mlx->tex5);
	if (all->mlx->tex6)
		mlx_destroy_image(all->mlx->mlx, all->mlx->tex6);
	if (all->mlx->buffer)
		while (++i < all->size->win_y)
			free(all->mlx->buffer[i]);
	free(all->mlx->buffer);
	ft_free_all(all);
	exit(excode);
}

void	ft_error(t_all *all, int error)
{
	all->exit = error;
	if (error != 0)
		ft_putstr_fd(R"Error: ", 2);
	if (error == 1)
		ft_putstr_fd(Y"Wrong number of arguments\n", 2);
	else if (error == 2)
		ft_putstr_fd(Y"Invalid map extension\n", 2);
	else if (error == 3)
		ft_putstr_fd(Y"File reading failed\n", 2);
	else if (error == 4)
		ft_putstr_fd(Y"Memory allocation failed\n", 2);
	else if (error == 5)
		ft_putstr_fd(Y"Invalid Map\n", 2);
	else if (error == 6)
		ft_putstr_fd(Y"Invalid Color\n", 2);
	else if (error == 7)
		ft_putstr_fd(Y"Invalid chars in map\n", 2);
	else if (error == 8)
		ft_putstr_fd(Y"Unclosed map\n", 2);
	else if (error == 9)
		ft_putstr_fd(Y"Unclosed map on space\n", 2);
	else if (error == 10)
		ft_putstr_fd(Y"Invalid texture\n", 2);
	ft_quit(all);
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
