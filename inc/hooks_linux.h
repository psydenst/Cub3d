/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_linux.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:12:09 by almelo            #+#    #+#             */
/*   Updated: 2023/05/27 04:24:15 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_LINUX_H
# define HOOKS_LINUX_H

// Linux keycodes
enum
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	LEFT_ARROW = 65361,
	RIGHT_ARROW = 65363
};

// MLX events
enum
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17
};
#endif
