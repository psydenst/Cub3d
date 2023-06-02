/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:55:33 by almelo            #+#    #+#             */
/*   Updated: 2023/06/01 23:52:49 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	render_next_frame(t_data *data)
{
	t_raycaster	rc;
	t_frame		frame;

	frame.img.img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	set_image_data(&frame.img);
	raycaster_loop(&rc, data, &frame);
	draw_next_frame(&frame.img, frame.buffer);
	clear_frame_buffer(&frame);
	mlx_put_image_to_window(data->mlx, data->win, frame.img.img, 0, 0);
	mlx_destroy_image(data->mlx, frame.img.img);
	return (0);
}
