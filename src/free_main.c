/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:36:22 by psydenst          #+#    #+#             */
/*   Updated: 2023/06/12 22:54:58 by almelo           ###   ########.fr       */
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
  if (data->map.map_copy != NULL)
    free_copy(&data->map);
}

void  free_copy(t_map *map)
{
  int i;

  i = -1;
  while (++i <= map->window_height)
    free(map->map_copy[i]);
  free(map->map_copy);
}

void	free_matrix(t_map *map)
{
  int i;

  i = -1;
  while (map->world_map[map->map_start])
	{
		free(map->world_map[map->map_start]);
		map->map_start++;
	}
	free(map->world_map);
}
