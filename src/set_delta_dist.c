/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_delta_dist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:28:28 by almelo            #+#    #+#             */
/*   Updated: 2023/06/02 00:29:30 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_delta_dist(t_raycaster *rc)
{
	if (rc->ray_dir_x == 0)
		rc->delta_dist_x = INFINITY;
	else
		rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
	if (rc->ray_dir_y == 0)
		rc->delta_dist_y = INFINITY;
	else
		rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
	return ;
}
