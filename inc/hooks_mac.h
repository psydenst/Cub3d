/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mac.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almelo <almelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 01:22:28 by almelo            #+#    #+#             */
/*   Updated: 2023/06/02 01:23:25 by almelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_MAC_H
# define HOOKS_MAC_H

// macOS keycodes
enum
{
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124
};

// MLX events
enum
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17
};
#endif // HOOKS_MAC_H
