/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asdw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:23:35 by psydenst          #+#    #+#             */
/*   Updated: 2023/05/17 22:26:07 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keyhook_w(t_map *map)
{
	printf("w\n");
	return (0);
}

int	keyhook_d(t_map *map)
{
	printf("d\n");
	return (0);
}

int	keyhook_a(t_map *map)
{
	printf("a\n");
	return (0);
}

int	keyhook_s(t_map *map)
{
	printf("s\n");
	return (0);
}

int	keyhook_esc(t_map *map)
{
	exit_func(map, "You have pressed esc");
	return (0);
}
