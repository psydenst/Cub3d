/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:24:48 by almelo            #+#    #+#             */
/*   Updated: 2023/06/26 18:01:11 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static	void	init_data(t_data *data)
{
	data->map.fd = 0;
	data->map.window_height = 0;
	data->map.window_width = 0;
	data->map.map_start = 0;
	data->map.path_no = NULL;
	data->map.path_so = NULL;
	data->map.path_ea = NULL;
	data->map.path_we = NULL;
	data->map.world_map = NULL;
	data->map.floor = NULL;
	data->map.ciel = NULL;
	data->map.pos_x = 0;
	data->map.pos_y = 0;
	data->map.direction = '\0';
	data->map.sign = 0;
	data->map.valid = 0;
	data->map.i = 0;
	data->map.j = 0;
	data->map.length = 0;
	data->map.a = 0;
	data->map.map_copy = NULL;
	return ;
}

int	main( int argc, char **argv)
{
	t_data	data;

	data = (t_data){0};
	data.map = (t_map){0};
	init_data(&data);
	if (!verification_main(argv, argc, &data))
	{
		free_main(&data);
		return (0);
	}
	data.mlx = mlx_init();
	load_textures(&data);
	load_colors(&data);
	set_player_position(&data);
	set_player_direction(&data);
	data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
	set_hooks(&data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
