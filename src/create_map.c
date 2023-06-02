/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:00:29 by psydenst          #+#    #+#             */
/*   Updated: 2023/06/01 22:34:30 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	create_map(t_data *data)
{
	char	*str;
	char	*joker;
	int		len;

	len = 0;
	str = NULL;
	joker = get_next_line(data->map.fd);
	joker = remove_sp(joker);
	while (1)
	{
		str = get_next_line(data->map.fd);
		str = remove_sp(str);
		if (str == NULL)
			break ;
		joker = ft_strjoin(joker, str);
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
	char	*ret;
	char	*joker;	
	int		begin;
	int		end;

	if (str == NULL)
		return (NULL);
	ret = "";
	joker = NULL;
	begin = 0;
	end = 0;
	while (str[begin])
	{
		begin = end;
		while (str[end] != ' ' && str[end] != '\t' && str[end] != '\0')
			end++;
		joker = ft_substr(str, begin, end - begin);
		while ((str[end] == ' ' || str[end] == '\t') && str[end] != '\0')
				end++;
		ret = ft_strjoin(ret, joker);
	}
	free(str);
	return (ret);
}
