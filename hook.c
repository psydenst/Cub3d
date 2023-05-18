/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:42:48 by psydenst          #+#    #+#             */
/*   Updated: 2023/05/17 22:17:49 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keyhook_main(int keycode, t_map *map)
{
	if (keycode == 13)
		keyhook_w(map);
	if (keycode == 0)
		keyhook_a(map);
	if (keycode == 1)
		keyhook_s(map);
	if (keycode == 2)
		keyhook_d(map);
	if (keycode == 53)
		keyhook_esc(map);
	return (0);
}

int	close_window(t_map *map)
{
	exit_func(map, "You closed the window with 🅧 ");
	return (0);
}

void	exit_func(t_map *map, const char *str)
{
	printf("%s\n", str);
	if (map->mlx_win)
		mlx_clear_window(map->mlx_ptr, map->mlx_win);
	if (map->mlx_ptr)
		mlx_clear_window(map->mlx_ptr, map->mlx_win);
	exit_images(map);
	if (map->mlx_win)
		mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	if (map->mlx_ptr)
		free(map->mlx_ptr);
//	if (map->map)
//		free_map(map->map);
	exit(0);
}

void	exit_images(t_map *map)
{
	(void) map;
	/*
	if (map->wall)
		mlx_destroy_image(map->mlx_ptr, map->wall);
	if (map->floor)
		mlx_destroy_image(map->mlx_ptr, map->floor);
	if (map->collect)
		mlx_destroy_image(map->mlx_ptr, map->collect);
	if (map->player)
		mlx_destroy_image(map->mlx_ptr, map->player);
	if (map->exit)
		mlx_destroy_image(map->mlx_ptr, map->exit);
	*/
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free (map);
}

