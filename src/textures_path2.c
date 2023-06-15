/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_path2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:23:28 by psydenst          #+#    #+#             */
/*   Updated: 2023/06/14 21:00:08 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	get_no(t_map *map, int i)
{
	int	fd;

	map->path_NO = ft_substr(map->world_map[i], 2,
			ft_strlen(map->world_map[i]) - 2);
	fd = open(map->path_NO, O_RDONLY);
	if (fd > 0)
		return (1);
	else
	{
		free(map->path_NO);
		map->path_NO = NULL;
		return (0);
	}
}

int	get_so(t_map *map, int i)
{
	int	fd;

	map->path_SO = ft_substr(map->world_map[i], 2,
			ft_strlen(map->world_map[i]) - 2);
	fd = open(map->path_SO, O_RDONLY);
	if (fd > 0)
		return (1);
	else
	{
		free(map->path_SO);
		map->path_SO = NULL;
		return (0);
	}
}

int	get_we(t_map *map, int i)
{
	int	fd;

	map->path_WE = ft_substr(map->world_map[i], 2,
			ft_strlen(map->world_map[i]) - 2);
	fd = open(map->path_WE, O_RDONLY);
	if (fd > 0)
		return (1);
	else
	{
		free(map->path_WE);
		map->path_SO = NULL;
		return (0);
	}
}

int	get_ea(t_map *map, int i)
{
	int	fd;

	if (map->path_EA == NULL)
		map->path_EA = ft_substr(map->world_map[i], 2,
				ft_strlen(map->world_map[i]) - 2);
	fd = open(map->path_EA, O_RDONLY);
	if (fd > 0)
		return (1);
	else
	{
		free(map->path_EA);
		map->path_SO = NULL;
		return (0);
	}
}
