/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:11:22 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/21 22:00:07 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collectibles(t_data *data, int x, int y)
{
	int	i;
	int	col_x;
	int	col_y;

	i = 0;
	while (i < data->collectible_count)
	{
		col_x = data->entity.collectibles[i][0];
		col_y = data->entity.collectibles[i][1];
		if (x == col_x && y == col_y)
		{
			data->entity.collectibles[i][0] = -1;
			data->entity.collectibles[i][1] = -1;
			data->collected++;
			return (1);
		}
		i++;
	}
	return (0);
}

void	count_move(t_data *data)
{
	data->move_count++;
	ft_printf("player move:%d\n", data->move_count);
}

static int	check_line_width(int fd, char *line, t_data *data)
{
	int	line_width;

	while (line)
	{
		line_width = ft_strlen(line);
		if (line[line_width - 1] == '\n')
			line_width--;
		if (line_width != data->map->width)
		{
			free(line);
			line = get_next_line(fd);
			while (line)
			{
				free(line);
				line = get_next_line(fd);
			}
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	is_map_rectangular(char *map_name, t_data *data)
{
	int		fd;
	char	*line;
	int		result;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	result = check_line_width(fd, line, data);
	close(fd);
	return (result);
}
