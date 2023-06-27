NAME		= cub3d

SRC			=	src/main.c \
				src/set_image_data.c \
				src/hooks.c \
				src/my_mlx_pixel_put.c \
				src/render_next_frame.c \
				src/draw_next_frame.c \
			  	src/verification.c \
				src/create_map.c \
				src/validate_map.c \
				src/textures_path.c \
				src/free_main.c \
				src/load_textures.c \
				src/set_player_position.c \
				src/set_player_direction.c \
				src/load_colors.c \
				src/buffer_wall_vertical_line.c \
				src/set_texture_x.c \
				src/set_wall_pixel_x.c \
				src/buffer_ceil_v_line.c \
				src/buffer_floor_v_line.c \
				src/raycaster_loop.c \
				src/calculate_ray_position.c \
				src/calculate_ray_direction.c \
				src/calculate_ray_step.c \
				src/calculate_side_dist.c \
				src/dda_loop.c \
				src/set_wall_texture.c \
				src/calculate_camera_dist.c \
				src/calculate_wall_data.c \
				src/set_delta_dist.c \
				src/move.c \
				src/rotate.c \
				src/clear_frame_buffer.c \
				src/textures_path2.c
OBJ			= $(SRC:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g

MLX			= mlx/libmlx.a

MLX_LINUX	= mlx_linux/libmlx.a

LIBFT		= libft/libft.a

DETECTED_OS	= $(shell uname)

ifeq ($(DETECTED_OS), Linux)
$(NAME)		: $(OBJ) $(MLX_LINUX) $(LIBFT) inc/cub3d.h
	$(CC) $(OBJ) -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
%.o			: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
else
$(NAME)		: $(OBJ) $(MLX) $(LIBFT)
	$(CC) $(OBJ) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o			: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
endif

$(MLX)		:
	make -C mlx

$(MLX_LINUX):
	make -C mlx_linux

$(LIBFT)	:
	make -C libft

all			: $(NAME)

clean		:
	$(RM) $(OBJ)

fclean		: clean
	$(RM) $(NAME)
	make -C libft fclean

re			: fclean all

.PHONY		: mlx all clean fclean re
