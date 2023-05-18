// INCLUDE 42 HEADER
//
//
#include "cub3d.h"

void	draw_vertical_line(t_img *img, t_line *line)
{
	int offset;

	offset = 0;
	while (offset < (line->y_end - line->y_start))
	{
		my_mlx_pixel_put(img, line->x, line->y_start + offset, line->color);
		offset++;
	}
	return ;
}
