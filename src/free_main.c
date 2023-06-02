/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:36:22 by psydenst          #+#    #+#             */
/*   Updated: 2023/06/02 15:18:29 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h" 

void	free_main(t_data *data)
{
	if (data->map.path_NO != NULL)
		free(data->map.path_NO);
	if (data->map.path_SO != NULL)
		free(data->map.path_SO);
	if (data->map.path_WE != NULL)
		free(data->map.path_WE);
	if (data->map.path_EA != NULL)
		free(data->map.path_EA);
	if (data->map.floor != NULL)
		free(data->map.floor);
	if (data->map.ciel != NULL)
		free(data->map.ciel);
	if (data->map.world_map != NULL)
		free_matrix(&data->map);
}

void	free_matrix(t_map *map)
{
	while (map->world_map[map->map_start])
	{
		free(map->world_map[map->map_start]);
		map->map_start++;
	}
}
