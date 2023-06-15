/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:23:28 by psydenst          #+#    #+#             */
/*   Updated: 2023/06/14 21:00:45 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	textures_main(t_map *map, t_wl *wl)
{
	wl->i = 0;
	while (not_map(map, wl->i))
	{
		if (ft_strncmp(map->world_map[wl->i], "NO", 2) == 0)
		{
			if (get_no(map, wl->i) == 0)
				return (printf("Texture not found\n"));
		}
		else if (ft_strncmp(map->world_map[wl->i], "SO", 2) == 0)
		{
			if (get_so(map, wl->i) == 0)
				return (printf("Texture not found\n"));
		}
		else if (ft_strncmp(map->world_map[wl->i], "WE", 2) == 0)
		{
			if (get_we(map, wl->i) == 0)
				return (printf("Texture not found\n"));
		}
		textures_main2(map, wl->i);
		wl->i++;
	}
	textures_main3(map, wl->i);
	return (1);
}

int	textures_main2(t_map *map, int i)
{
	while (not_map(map, i))
	{
		if (ft_strncmp(map->world_map[i], "EA", 2) == 0)
		{
			if (get_ea(map, i) == 0)
				return (printf("Texture not found\n"));
		}
		else if (map->world_map[i][0] == 'F' || map->world_map[i][0] == 'C')
		{
			if (floor_ciel(map, i) == 0)
				return (printf("Texture not found\n"));
		}
		i++;
	}
	return (1);
}

int	textures_main3(t_map *map, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(map->world_map[j]);
		map->world_map[j] = NULL;
		j++;
	}
	map->map_start = i;
	return (1);
}

int	floor_ciel(t_map *map, int i)
{
	if (map->world_map[i][0] == 'F' && map->floor == NULL)
			map->floor = ft_substr(map->world_map[i], 1,
				ft_strlen(map->world_map[i]) - 1);
	else
		if (map->ciel == NULL)
			map->ciel = ft_substr(map->world_map[i], 1,
					ft_strlen(map->world_map[i]) - 1);
	return (1);
}

int	not_map(t_map *map, int i)
{
	if (map->world_map[i][0] == '1' || map->world_map[i] == NULL)
		return (0);
	return (1);
}
