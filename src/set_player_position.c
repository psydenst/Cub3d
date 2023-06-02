/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 04:49:13 by almelo            #+#    #+#             */
/*   Updated: 2023/06/02 00:52:59 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	is_player(int c)
{
	return (c == 'N'
		|| c == 'S'
		|| c == 'E'
		|| c == 'W');
}

void	set_player_position(t_data *data)
{
	t_map	map;
	int		x;
	int		y;

	map = data->map;
	x = map.map_start;
	y = 0;
	while (map.world_map[x])
	{
		y = 0;
		while (map.world_map[x][y] && !is_player(map.world_map[x][y]))
			y++;
		if (is_player(map.world_map[x][y]))
			break ;
		x++;
	}
	data->pos_x = (float)x;
	data->pos_y = (float)y;
	data->spawn_orientation = map.world_map[x][y];
	return ;
}
