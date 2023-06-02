/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:31:45 by almelo            #+#    #+#             */
/*   Updated: 2023/06/01 01:36:26 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_texture_x(t_raycaster *rc, t_data *data)
{
	rc->tex.x = (int)(rc->wall_x * (double)(data->tex_width));
	if (rc->side == 0 && rc->ray_dir_x > 0)
		rc->tex.x = data->tex_width - rc->tex.x - 1;
	if (rc->side == 1 && rc->ray_dir_y < 0)
		rc->tex.x = data->tex_width - rc->tex.x - 1;
	return ;
}
