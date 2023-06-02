/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:18:20 by almelo            #+#    #+#             */
/*   Updated: 2023/06/02 01:47:22 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_wall_texture(t_raycaster *rc, t_data *data, t_frame *frame)
{
	if (rc->side == 0)
	{
		if (rc->map_x > data->pos_x)
			frame->wall_tex = data->tex_so;
		else
			frame->wall_tex = data->tex_no;
	}
	else
	{
		if (rc->map_y > data->pos_y)
			frame->wall_tex = data->tex_ea;
		else
			frame->wall_tex = data->tex_we;
	}
	return ;
}
