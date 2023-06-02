/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:23:28 by psydenst          #+#    #+#             */
/*   Updated: 2023/06/02 15:09:40 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	textures_main(t_map *map)
{
	int i;
	int j;

	j = 0;
	i = 0;

	while (not_map(map, i))
	{
		if (ft_strncmp(map->world_map[i], "NO", 2) == 0)
		{
			if(get_NO(map, i) == 0)
				return (printf("Texture not found\n"));
		}
		else if (ft_strncmp(map->world_map[i], "SO", 2) == 0)
		{
			if(get_SO(map, i) == 0)
				return (printf("Texture not found\n"));
		}
		else if (ft_strncmp(map->world_map[i], "WE", 2) == 0)
		{
			if(get_WE(map, i) == 0)
				return (printf("Texture not found\n"));
		}
	}
	return (1);

}

int	textures_main2(t_map *map, int i, int j)
{
	while(not_map(map, i))
	{
		if (ft_strncmp(map->world_map[i], "EA", 2) == 0)
		{
			if(get_EA(map, i) == 0)
				return (printf("Texture not found\n"));
		}
		else if (map->world_map[i][0] == 'F' || map->world_map[i][0] == 'C')
		{
			if(floor_ciel(map, i) == 0)
				return (printf("Texture not found\n"));
		}
		i++;
	}
	while (j < i)
	{
		free(map->world_map[j]);
		map->world_map[j] = NULL;
		j++;
	}
	map->world_map += i;
	return (1);
}

int	floor_ciel(t_map *map, int i)
{
	if (map->world_map[i][0] == 'F')
			map->floor = ft_substr(map->world_map[i], 1, 
						ft_strlen(map->world_map[i]) - 1);
	else
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

int	get_NO(t_map *map, int i)
{
	int fd;

	map->path_NO = ft_substr(map->world_map[i], 2, 
						ft_strlen(map->world_map[i]) - 2);
	if ((fd = open(map->path_NO, O_RDONLY) > 0))
		return (1);
	else
	{
		free(map->path_NO);
		return (0);
	}
}

int	get_SO(t_map *map, int i)
{
	int fd;
	map->path_SO = ft_substr(map->world_map[i], 2, 
						ft_strlen(map->world_map[i]) - 2);
	if ((fd = open(map->path_SO, O_RDONLY) > 0))
		return (1);
	else
	{
		free(map->path_SO);
		return (0);
	}
}

int	get_WE(t_map *map, int i)
{
	int fd;

	map->path_WE = ft_substr(map->world_map[i], 2, 
						ft_strlen(map->world_map[i]) - 2);
	if ((fd = open(map->path_WE, O_RDONLY) > 0))
		return (1);
	else
	{
		free(map->path_WE);
		return (0);
	}
}

int	get_EA(t_map *map, int i)
{
	int fd;

	map->path_EA = ft_substr(map->world_map[i], 2, 
						ft_strlen(map->world_map[i]) - 2);
	if ((fd = open(map->path_EA, O_RDONLY) > 0))
		return (1);
	else
	{
		free(map->path_EA);
		return (0);
	}
}

