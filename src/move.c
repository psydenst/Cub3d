/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:36:23 by almelo            #+#    #+#             */
/*   Updated: 2023/06/02 00:46:56 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_forward(t_data *data)
{
	char	**world_map;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;

	world_map = data->map.world_map;
	pos_x = data->pos_x;
	pos_y = data->pos_y;
	dir_x = data->dir_x;
	dir_y = data->dir_y;
	if (world_map[(int)(pos_x + dir_x * MOVE_SPEED)][(int)pos_y] != '1')
		data->pos_x += dir_x * MOVE_SPEED;
	if (world_map[(int)pos_x][(int)(pos_y + dir_y * MOVE_SPEED)] != '1')
		data->pos_y += dir_y * MOVE_SPEED;
	return ;
}

void	move_backwards(t_data *data)
{
	char	**world_map;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;

	world_map = data->map.world_map;
	pos_x = data->pos_x;
	pos_y = data->pos_y;
	dir_x = data->dir_x;
	dir_y = data->dir_y;
	if (world_map[(int)(pos_x - dir_x * MOVE_SPEED)][(int)pos_y] != '1')
		data->pos_x -= dir_x * MOVE_SPEED;
	if (world_map[(int)pos_x][(int)(pos_y - dir_y * MOVE_SPEED)] != '1')
		data->pos_y -= dir_y * MOVE_SPEED;
	return ;
}

void	move_right(t_data *data)
{
	char	**world_map;
	double	pos_x;
	double	pos_y;
	double	plane_x;
	double	plane_y;

	world_map = data->map.world_map;
	pos_x = data->pos_x;
	pos_y = data->pos_y;
	plane_x = data->plane_x;
	plane_y = data->plane_y;
	if (world_map[(int)(pos_x + plane_x * MOVE_SPEED)][(int)pos_y] != '1')
		data->pos_x += plane_x * MOVE_SPEED;
	if (world_map[(int)pos_x][(int)(pos_y + plane_y * MOVE_SPEED)] != '1')
		data->pos_y += plane_y * MOVE_SPEED;
	return ;
}

void	move_left(t_data *data)
{
	char	**world_map;
	double	pos_x;
	double	pos_y;
	double	plane_x;
	double	plane_y;

	world_map = data->map.world_map;
	pos_x = data->pos_x;
	pos_y = data->pos_y;
	plane_x = data->plane_x;
	plane_y = data->plane_y;
	if (world_map[(int)(pos_x - plane_x * MOVE_SPEED)][(int)pos_y] != '1')
		data->pos_x -= plane_x * MOVE_SPEED;
	if (world_map[(int)pos_x][(int)(pos_y - plane_y * MOVE_SPEED)] != '1')
		data->pos_y -= plane_y * MOVE_SPEED;
	return ;
}
