/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controls_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:24:07 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/19 17:58:10 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	name_control(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '.')
		i++;
	if (str[i] == '\0')
		return (1);
	if (ft_strcmp(&str[i], ".ber") == 0)
		return (0);
	else
		return (1);
}

int	get_size(char *map_name, t_data *data)
{
	int		fd;
	char	*line;

	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (free(data->map), 1);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (free(data->map), 1);
	line = get_next_line(fd);
	while (line)
	{
		data->map->width = ft_strlen(line);
		data->map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (data->map->height == 0 || data->map->width == 0)
		return (free(data->map), 1);
	printf("width = %d\n", data->map->width);
	printf("height = %d\n", data->map->height);
	return (0);
}

int	get_map(char *map_name, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (1);
	data->map->map = (char **)malloc(sizeof(char *) * data->map->height);
	if (!data->map->map)
		return (free(data->map), 1);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		data->map->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	close (fd);
	return (0);
}

int	is_map_rectangular(t_data *data)
{
	int		i;
	int		row_width;
	char	**map;

	map = data->map->map;
	i = 0;
	if (data->map->width == data->map->height)
		return (1);
	while (i < data->map->height)
	{
		row_width = 0;
		while (map[i][row_width] != '\0' && map[i][row_width] != '\n')
			row_width++;
		if (row_width != data->map->width)
			return (1);
		i++;
	}
	return (0);
}

int	is_map_surrounded(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	map = data->map->map;
	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			if (i == 0 || i == data->map->height - 1
				|| j == 0 || j == data->map->width - 1)
			{
				if (map[i][j] != '1')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
