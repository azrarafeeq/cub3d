/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:59:02 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/02 21:16:12 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(float delta_time, t_player *player)
{
	float	move_step;
	float	newx;
	float	newy;

	player->rotation_angle += player->turn_direction
		* player->turn_speed * delta_time;
	move_step = player->walk_direction * player->walk_speed; // * deltaTime;
	newx = player->x + cos(player->rotation_angle) * move_step;
	newy = player->y + sin(player->rotation_angle) * move_step;
	player->x = newx;
	player->y = newy;
}
