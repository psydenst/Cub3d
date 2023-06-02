/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_side_dist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:09:55 by almelo            #+#    #+#             */
/*   Updated: 2023/06/02 00:47:21 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	calculate_side_dist(t_raycaster *rc, t_data *data)
{
	if (rc->ray_dir_x < 0)
		rc->side_dist_x = (data->pos_x - rc->map_x) * rc->delta_dist_x;
	else
		rc->side_dist_x = (rc->map_x + 1.0 - data->pos_x) * rc->delta_dist_x;
	if (rc->ray_dir_y < 0)
		rc->side_dist_y = (data->pos_y - rc->map_y) * rc->delta_dist_y;
	else
		rc->side_dist_y = (rc->map_y + 1.0 - data->pos_y) * rc->delta_dist_y;
	return ;
}
