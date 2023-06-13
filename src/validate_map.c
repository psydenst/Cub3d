/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:03:20 by psydenst          #+#    #+#             */
/*   Updated: 2023/06/09 20:46:32 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/cub3d.h"

int	validate_main(t_map *map)
{
	if (textures_main(map) == 0)
	{
		printf("Invalid textures\n");
		return (0);
	}
	biggest_width(map);
	if (is_valid(map) == 0)
	{
		printf("Invalid map\n");
		return (0);
	}
	return (1);
}

int	is_valid(t_map *map)
{
	int	height;
	int	i;

	i = map->map_start + 1;
	height = 0;
	while (map->world_map[height])
		height++;
	if (is_one(map, map->map_start) == 0 || is_one(map, map->window_height - 1) == 0)
		return (0);
	if (nsow10(map, i) == 0 || map->sign > 1)
		return (0);
	wall_spaces(map);
	if (check_above(map) == 0)
		return (0);
	return (1);
}

int	is_one(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->world_map[i][j])
	{
		if (map->world_map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

void	biggest_width(t_map *map)
{
	int	y;
	int i;
	int length;

	i = map->map_start;
	y = i;
	while (map->world_map[y])
			y++;
	map->window_height = y;
	map->window_width = ft_strlen(map->world_map[i]);
	while (i < map->window_height)
	{
		length = ft_strlen(map->world_map[i]);
		if (length > map->window_width)
				map->window_width = length;
		i++;		
	}
}

int	nsow10(t_map *map, int x)
{
	int	i;

	while (x < map->window_height)
	{
		i = 0;
		while (map->world_map[x][i])
		{
			if (map->world_map[x][i] != '1' && map->world_map[x][i] != '0' &&
				map->world_map[x][i] != 'N' && map->world_map[x][i] != 'E'
				&& map->world_map[x][i] != 'W' && map->world_map[x][i] != 'S')
				return (0);
			if (map->world_map[x][i] == 'N' || map->world_map[x][i] == 'S' ||
				map->world_map[x][i] == 'O' || map->world_map[x][i] == 'W')
			{
				map->pos_x = x;
				map->pos_y = i;
				map->direction = map->world_map[x][i];
				map->sign++;
			}
			i++;
		}
		x++;
	}
	return (1);
}
