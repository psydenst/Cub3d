/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:26:02 by psydenst          #+#    #+#             */
/*   Updated: 2023/05/17 21:55:04 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx/mlx.h" 

typedef struct s_map
{
    void *mlx_ptr;
    void *mlx_win;
} t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_img;

typedef	struct	s_line
{
	int	x;
	int	height;
	int	y_start;
	int	y_end;
	int	color;
} t_line;

typedef	struct	s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

void	set_image_data(t_img *img);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_vertical_line(t_img *img, t_line *line);
void	set_hooks(t_mlx *mlx);

// ASDW.C
int			keyhook_w(t_map *map);
int			keyhook_d(t_map *map);
int			keyhook_a(t_map *map);
int			keyhook_s(t_map *map);
int			keyhook_esc(t_map *map);

// KEY_EVENTS.C
int			keyhook_main(int keycode, t_map *map);
void		exit_func(t_map *map, const char *str);
void		exit_images(t_map *map);
void		free_map(char **map);
int			close_window(t_map *map);

#define screenWidth 640
#define screenHeight 680
#define mapWidth 24
#define mapHeight 24


#endif
