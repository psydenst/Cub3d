# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 16:06:05 by psydenst          #+#    #+#              #
#    Updated: 2023/05/17 22:24:03 by psydenst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

SRC			= cub3d.c \
			  hook.c \
			  asdw.c \
			  draw_vertical_lines.c \
			  my_mlx_pixel_put.c \
			  set_image_data.c

OBJ			= $(SRC:.c=.o)

CFLAGS		= #-Wall -Wextra -Werror

MLX			= mlx/libmlx.a

INCLUDE		= cub3d.h

MLX_LINUX	= mlx_linux/libmlx_Linux.a

DETECTED_OS	= $(shell uname)

ifeq ($(DETECTED_OS), Linux)
$(NAME)		: $(OBJ) $(MLX_LINUX)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o			: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
else
$(NAME)		: $(OBJ) $(MLX)
	$(CC) $(OBJ) -Lmlx -lmlx  mlx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

%.o			: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
endif

$(MLX)		:
	make -C mlx

$(MLX_LINUX):
	make -C mlx_linux

all			: $(NAME)

clean		:
	$(RM) $(OBJ)

fclean		: clean
	$(RM) $(NAME)

re			: fclean all

.PHONY		: mlx all clean fclean re
