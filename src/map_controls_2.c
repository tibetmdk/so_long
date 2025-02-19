/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controls_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:01:22 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/19 19:29:01 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_to_map_copy(t_data *data)
{
	int	i;
	int	j;
	data->map->map_copy = (char **)malloc(sizeof(char *) * data->map->height);
	if (!data->map->map_copy)
		return (free(data->map), 1);//free_all(data) olucak.
	i = 0;
	while (i < data->map->height)
	{
		data->map->map_copy[i] = (char *)malloc(sizeof(char) * data->map->width);
		if (!data->map->map_copy[i])
		{
			while (--i >= 0)
				free(data->map->map_copy[i]);
			free(data->map->map_copy);
			//free_all(data) olucak.
			return (1);
		}
		j = 0;
		while (j < data->map->width)
		{
			data->map->map_copy[i][j] = data->map->map[i][j];
			j++;
		}
		i++;
	}
	return (0);
}

int	is_entities_valid(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			if (data->map->map[i][j] == 'C')
				data->collectible_count++;
			else if (data->map->map[i][j] == 'X')
				data->exit_count++;
			else if (data->map->map[i][j] == 'P')
				data->player_count++;
			j++;
		}
		i++;
	}
	if (data->collectible_count == 0 || data->player_count != 1 || data->exit_count != 1)
		return (1);
	return (0);
}

int	count_collectibles(t_data *data)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			if (data->map->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return count;
}
