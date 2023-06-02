/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_floor_v_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:02:43 by almelo            #+#    #+#             */
/*   Updated: 2023/06/01 02:09:00 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	buffer_floor_v_line(t_raycaster *rc, t_data *data, t_frame *frame)
{
	int	y;

	y = rc->wall_bottom;
	while (y < SCREEN_HEIGHT)
	{
		frame->buffer[y][rc->screen_x] = data->color_floor;
		y++;
	}
	return ;
}
