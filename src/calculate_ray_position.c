/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 23:55:40 by almelo            #+#    #+#             */
/*   Updated: 2023/06/02 00:48:59 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	calculate_ray_position(t_raycaster *rc)
{
	rc->camera_x = 2 * rc->screen_x / (double)(SCREEN_WIDTH) - 1;
	return ;
}
