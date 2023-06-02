/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:23:51 by almelo            #+#    #+#             */
/*   Updated: 2023/06/02 01:07:44 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		offset;

	offset = y * img->line_length + x * (img->bits_per_pixel / 8);
	pixel = img->addr + offset;
	*(unsigned int *)pixel = color;
	return ;
}
