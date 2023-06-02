/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray_step.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:06:33 by almelo            #+#    #+#             */
/*   Updated: 2023/06/02 00:09:09 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	calculate_ray_step(t_raycaster *rc)
{
	if (rc->ray_dir_x < 0)
		rc->step_x = -1;
	else
		rc->step_x = 1;
	if (rc->ray_dir_y < 0)
		rc->step_y = -1;
	else
		rc->step_y = 1;
	return ;
}
