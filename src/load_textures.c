/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:38:12 by almelo            #+#    #+#             */
/*   Updated: 2023/06/02 01:20:21 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	load_texture_no(t_data *data)
{
	data->tex_no.img = mlx_xpm_file_to_image
		(
			data->mlx,
			data->map.path_NO,
			&data->tex_width,
			&data->tex_height
			);
	set_image_data(&data->tex_no);
	return ;
}

static void	load_texture_so(t_data *data)
{
	data->tex_so.img = mlx_xpm_file_to_image
		(
			data->mlx,
			data->map.path_SO,
			&data->tex_width,
			&data->tex_height
			);
	set_image_data(&data->tex_so);
	return ;
}

static void	load_texture_we(t_data *data)
{
	data->tex_we.img = mlx_xpm_file_to_image
		(
			data->mlx,
			data->map.path_WE,
			&data->tex_width,
			&data->tex_height
			);
	set_image_data(&data->tex_we);
	return ;
}

static void	load_texture_ea(t_data *data)
{
	data->tex_ea.img = mlx_xpm_file_to_image
		(
			data->mlx,
			data->map.path_EA,
			&data->tex_width,
			&data->tex_height
			);
	set_image_data(&data->tex_ea);
	return ;
}

void	load_textures(t_data *data)
{
	load_texture_no(data);
	load_texture_so(data);
	load_texture_we(data);
	load_texture_ea(data);
	return ;
}
