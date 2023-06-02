/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_pixel_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:41:17 by almelo            #+#    #+#             */
/*   Updated: 2023/06/02 01:11:46 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_wall_pixel_x(t_raycaster *rc, t_data *data)
{
	if (rc->side == 0)
		rc->wall_x = data->pos_y + rc->perp_wall_dist * rc->ray_dir_y;
	else
		rc->wall_x = data->pos_x + rc->perp_wall_dist * rc->ray_dir_x;
	rc->wall_x -= floor((rc->wall_x));
	return ;
}
