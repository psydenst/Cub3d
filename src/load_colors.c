/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:28:33 by almelo            #+#    #+#             */
/*   Updated: 2023/06/12 20:59:58 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	free_rgb_ceil(char **rgb_ceil)
{
	int	i;

	i = 0;
	while (rgb_ceil[i])
	{
		free(rgb_ceil[i]);
		i++;
	}
	free(rgb_ceil);
	return ;
}

static void	free_rgb_floor(char **rgb_floor)
{
	int	i;

	i = 0;
	while (rgb_floor[i])
	{
		free(rgb_floor[i]);
		i++;
	}
	free(rgb_floor);
	return ;
}

void	load_colors(t_data *data)
{
	char	**rgb_ceil;
	char	**rgb_floor;
	int		red;
	int		green;
	int		blue;

	rgb_ceil = ft_split(data->map.ciel, ',');
	red = ft_atoi(rgb_ceil[0]);
	green = ft_atoi(rgb_ceil[1]);
	blue = ft_atoi(rgb_ceil[2]);
	data->color_ceil = (red << 16) | (green << 8) | blue;
	rgb_floor = ft_split(data->map.floor, ',');
	red = ft_atoi(rgb_floor[0]);
	green = ft_atoi(rgb_floor[1]);
	blue = ft_atoi(rgb_floor[2]);
	data->color_floor = (red << 16) | (green << 8) | blue;
	free_rgb_ceil(rgb_ceil);
	free_rgb_floor(rgb_floor);
	return ;
}
