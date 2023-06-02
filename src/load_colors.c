/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:28:33 by almelo            #+#    #+#             */
/*   Updated: 2023/06/02 00:48:29 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	free(rgb_ceil);
	free(rgb_floor);
	return ;
}
