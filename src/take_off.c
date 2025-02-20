/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_off.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:08:14 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/20 13:33:23 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	return (0);
}

/*static void	write_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map->height)
	{
		ft_printf("%s", data->map->map[i]);
		i++;
	}
}

static void write_map_copy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map->height)
	{
		ft_printf("%s\n", data->map->map_copy[i]);
		i++;
	}
}*/

int	take_off(t_data *data, char *map_name)
{
	if (name_control(map_name))
		return (ft_error("Invalid map name"), 1);
	if (get_size(map_name, data))
		return (ft_error("Invalid map size"), 1);
	if (get_map(map_name, data))
		return (ft_error("Invalid map"), 1);
	if (is_map_rectangular(data))
		return (ft_error("Map is not rectangular"), 1);
	if (is_map_surrounded(data))
		return (ft_error("Map is not surrounded by walls"), 1);
	if (get_map_to_map_copy(data))
		return (ft_error("Invalid map copy"), 1);
	if (is_entities_valid(data))
		return (ft_error("Invalid entities"), 1);
	get_entities_location(data);
	flood_fill(data, data->entity.player_x, data->entity.player_y);
	if (is_map_valid(data))
		return (ft_error("Invalid path int map"), 1);
	return (0);
}
