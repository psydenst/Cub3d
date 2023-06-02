/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray_direction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:03:15 by almelo            #+#    #+#             */
/*   Updated: 2023/06/02 00:49:18 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	calculate_ray_direction(t_raycaster *rc, t_data *data)
{
	rc->ray_dir_x = data->dir_x + data->plane_x * rc->camera_x;
	rc->ray_dir_y = data->dir_y + data->plane_y * rc->camera_x;
	return ;
}
