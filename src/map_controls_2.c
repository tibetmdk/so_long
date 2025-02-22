/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controls_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:01:22 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/22 14:50:12 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_to_map_copy(t_data *data)
{
	int	i;
	int	j;

	data->map->map_copy = malloc(sizeof(char *) * data->map->height);
	if (!data->map->map_copy)
		return (free_all(data), 1);
	i = -1;
	while (++i < data->map->height)
	{
		data->map->map_copy[i] = malloc(sizeof(char) * data->map->width);
		if (!data->map->map_copy[i])
		{
			while (--i >= 0)
				free(data->map->map_copy[i]);
			return (free(data->map->map_copy), free_all(data), 1);
		}
		j = -1;
		while (++j < data->map->width)
			data->map->map_copy[i][j] = data->map->map[i][j];
	}
	return (0);
}

int	is_entities_valid(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			if (data->map->map[i][j] == 'C')
				data->collectible_count++;
			else if (data->map->map[i][j] == 'E')
				data->exit_count++;
			else if (data->map->map[i][j] == 'P')
				data->player_count++;
			j++;
		}
		i++;
	}
	if (data->collectible_count == 0 || data->player_count != 1
		|| data->exit_count != 1)
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
	return (count);
}

void	flood_fill(t_data *data, int x, int y)
{
	if (!data || !data->map || !data->map->map_copy)
		return ;
	if (x < 0 || y < 0 || x >= data->map->width || y >= data->map->height)
		return ;
	if (data->map->map_copy[y][x] == '1' || data->map->map_copy[y][x] == 'x')
		return ;
	data->map->map_copy[y][x] = 'x';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}

int	is_map_valid(t_data *data)
{
	int	i;
	int	j;

	if (!data || !data->map || !data->map->map_copy)
	{
		ft_error("data, map veya map_copy NULL!");
		return (1);
	}
	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			if (data->map->map_copy[i][j] == '1'
				|| data->map->map_copy[i][j] == 'x')
				j++;
			else
				return (free_map(data), 1);
		}
		i++;
	}
	return (0);
}
