/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 02:16:11 by almelo            #+#    #+#             */
/*   Updated: 2023/05/31 02:17:11 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_H
# define FRAME_H

# include "img.h"

typedef struct s_frame
{
	t_img		img;
	t_img		wall_tex;
	uint32_t	buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
}				t_frame;
#endif
