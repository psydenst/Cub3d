
#include "cub3d.h"

void	set_image_data(t_img *img)
{
	img->addr = mlx_get_data_addr(
					img->img,
					&img->bits_per_pixel,
					&img->line_length,
					&img->endian
					);
	return;
}
