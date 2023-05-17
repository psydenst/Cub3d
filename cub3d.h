/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:26:02 by psydenst          #+#    #+#             */
/*   Updated: 2023/05/16 22:22:57 by psydenst         ###   ########.fr       */
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


#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24





#endif