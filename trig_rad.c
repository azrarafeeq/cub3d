/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:56:52 by arafeeq           #+#    #+#             */
/*   Updated: 2023/05/02 22:29:52 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
 #include "cub3d.h"

double	pythagoras(double x1, double x2, double y1, double y2)
{
	return (sqrt(((y2 - y1) * (y2 - y1)) + ((x2 - x1) * (x2 - x1))));
}

 double	degree_to_radians(double a)
{
    double radians;

    radians = (a * M_PI) / 180;
	return (radians);
}
