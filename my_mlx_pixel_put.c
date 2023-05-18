#include "cub3d.h"

 void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		offset;

	offset = y * img->line_length + x * (img->bits_per_pixel / 8);
	pixel = img->addr + offset;
	*(unsigned int *)pixel = color;
	return ;
}
