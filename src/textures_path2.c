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

	map->path_no = ft_substr(map->world_map[i], 2,
			ft_strlen(map->world_map[i]) - 2);
	fd = open(map->path_no, O_RDONLY);
	if (fd > 0)
		return (1);
	else
	{
		free(map->path_no);
		map->path_no = NULL;
		return (0);
	}
}

int	get_so(t_map *map, int i)
{
	int	fd;

	map->path_so = ft_substr(map->world_map[i], 2,
			ft_strlen(map->world_map[i]) - 2);
	fd = open(map->path_so, O_RDONLY);
	if (fd > 0)
		return (1);
	else
	{
		free(map->path_so);
		map->path_so = NULL;
		return (0);
	}
}

int	get_we(t_map *map, int i)
{
	int	fd;

	map->path_we = ft_substr(map->world_map[i], 2,
			ft_strlen(map->world_map[i]) - 2);
	fd = open(map->path_we, O_RDONLY);
	if (fd > 0)
		return (1);
	else
	{
		free(map->path_we);
		map->path_we = NULL;
		return (0);
	}
}

int	get_ea(t_map *map, int i)
{
	int	fd;

	if (map->path_ea == NULL)
		map->path_ea = ft_substr(map->world_map[i], 2,
				ft_strlen(map->world_map[i]) - 2);
	fd = open(map->path_ea, O_RDONLY);
	if (fd > 0)
		return (1);
	else
	{
		free(map->path_ea);
		map->path_ea = NULL;
		return (0);
	}
}
