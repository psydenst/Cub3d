/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:33:00 by psydenst          #+#    #+#             */
/*   Updated: 2023/06/01 22:12:02 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_is_cub(char *haystack)
{
	if (ft_strnstr(haystack, ".cub", 4))
	{
		free(haystack);
		return (1);
	}
	else
	{
		free(haystack);
		return (0);
	}
}

int	validate_cub(char *map_name)
{
	int		a;
	int		b;
	int		x;
	char	*haystack;

	a = 4;
	x = 0;
	if (ft_strlen(map_name) < 5)
		return (0);
	b = ft_strlen(map_name) - 4;
	haystack = malloc(5 * sizeof(char));
	if (!haystack)
		return (0);
	while (a > 0)
	{
		haystack[x] = map_name[b];
		x++;
		b++;
		a--;
	}
	if (ft_is_cub(haystack) == 1)
		return (1);
	else
		return (0);
}

int	verification_main(char **argv, int argc, t_data *data)
{
	if (argc != 2)
	{
		ft_printf("Wrong input :/\nUsage: ./cub3d path_to_.cub\n");
		return (0);
	}
	if (validate_cub(argv[1]) == 0)
	{
		ft_printf("Not a .cub :/\n");
		return (0);
	}
	data->map.fd = open(argv[1], O_RDONLY);
	if (data->map.fd > 0)
		create_map(data);
	else
	{
		ft_printf("Map and textures instruction were not found\n");
		return (0);
	}
	if (validate_main(&data->map) == 0)
		return (0);
	return (1);
}

int	wall_spaces(t_map *map)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = ft_calloc(map->window_height, sizeof(char *));
	while (map->world_map[i])
	{
		map_copy[i] = ft_strdup(map->world_map[i]);
		while ((int)ft_strlen(map_copy[i]) < map->window_width)
		{
			map_copy[i] = ft_strjoin(map_copy[i], "k");
		}
		i++;
	}
	if (check_above(map_copy, map->window_height) == 0)
		map->valid = -1;
	i = 0;
	while (i < map->window_height)
	{
		free(map_copy[i]);
		i++;
	}
	if (map->valid == -1)
		return (0);
	return (1);
}

int	check_above(char **str, int height)
{
	int	i;
	int	j;

	i = 1;
	while (i < height)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '0')
			{
				if (str[i - 1][j] == 'k' || str[i][j + 1] == 'k' ||
				str[i][j - 1] == 'k')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
