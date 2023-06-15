/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:24:48 by almelo            #+#    #+#             */
/*   Updated: 2023/06/12 22:56:32 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
static	void	init_data(t_data *data)
{
	data->map.sign = 0;
	data->map.path_NO = NULL;
	data->map.path_SO = NULL;
	data->map.path_EA = NULL;
	data->map.path_WE = NULL;
	data->map.floor = NULL;
	data->map.ciel = NULL;
	data->map.world_map = NULL;
}
*/

int	main( int argc, char **argv)
{
	t_data	data;

	data = (t_data){0};
    data.map = (t_map){0};
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
