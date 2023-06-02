/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_ceil_v_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:58:24 by almelo            #+#    #+#             */
/*   Updated: 2023/06/01 02:00:58 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	buffer_ceil_v_line(t_raycaster *rc, t_data *data, t_frame *frame)
{
	int	y;

	y = 0;
	while (y < rc->wall_top)
	{
		frame->buffer[y][rc->screen_x] = data->color_ceil;
		y++;
	}
	return ;
}
