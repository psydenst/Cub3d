/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:00:29 by psydenst          #+#    #+#             */
/*   Updated: 2023/06/02 18:27:33 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	create_map(t_data *data)
{
	char	*str;
	char	*joker;
	char	*temp;
	int		len;

	len = 0;
	temp = NULL;
	str = NULL;
	joker = get_next_line(data->map.fd);
	joker = remove_sp(joker);
	while (1)
	{
		str = get_next_line(data->map.fd);
		str = remove_sp(str);
		if (str == NULL)
			break ;
		temp = joker;
		joker = ft_strjoin(joker, str);
		free(temp);
		free(str);
		len++;
	}
	free(str);
	close(data->map.fd);
	to_matrix(data, joker);
}

void	to_matrix(t_data *data, char *joker)
{
	int	i;

	i = 0;
	data->map.world_map = ft_split(joker, '\n');
	while (data->map.world_map[i])
		i++;
	data->map.window_height = i;
	i = -1;
	free(joker);
}

char	*remove_sp(char *str)
{
	t_wl	wl;

	if (str == NULL)
		return (NULL);
	wl.ret = "";
	wl.joker = NULL;
	wl.begin = 0;
	wl.end = 0;
	while (str[wl.begin])
	{
		wl.begin = wl.end;
		while (str[wl.end] != ' ' && str[wl.end] != '\t' && str[wl.end] != '\0')
			wl.end++;
		wl.joker = ft_substr(str, wl.begin, wl.end - wl.begin);
		while ((str[wl.end] == ' ' || str[wl.end] == '\t')
			&& str[wl.end] != '\0')
				wl.end++;
		wl.temp = wl.ret;
		wl.ret = ft_strjoin(wl.ret, wl.joker);
		free(wl.joker);
		if (wl.begin > 0)
			free(wl.temp);
	}
	free(str);
	return (wl.ret);
}
