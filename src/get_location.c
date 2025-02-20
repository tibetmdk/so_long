/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_location.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:17:47 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/20 18:09:18 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_player_location(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			if (data->map->map[i][j] == 'P')
			{
				data->entity.player_x = j;
				data->entity.player_y = i;
				printf("Player found at: [%d, %d]\n", j, i);
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	get_exit_location(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			if (data->map->map[i][j] == 'X')
			{
				data->entity.exit_x = j;
				data->entity.exit_y = i;
				printf("Exit found at: [%d, %d]\n", j, i);
				return ;
			}
			j++;
		}
		i++;
	}
	printf("ERROR: No exit found on the map!\n");
	free_all(data);
	exit(1);
}

static void	free_collectibles(t_data *data, int index)
{
	while (--index >= 0)
		free(data->entity.collectibles[index]);
	free(data->entity.collectibles);
	free_all(data);
}

static void	get_collectibles_location(t_data *data)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	data->collectible_count = count_collectibles(data);
	data->entity.collectibles = malloc(sizeof(int *) * data->collectible_count);
	if (!data->entity.collectibles)
		return (free_all(data));
	i = -1;
	while (++i < data->map->height && (j = -1))
		while (++j < data->map->width)
			if (data->map->map[i][j] == 'C')
			{
				data->entity.collectibles[k] = malloc(sizeof(int) * 2);
				if (!data->entity.collectibles[k])
					return (free_collectibles(data, k));
				data->entity.collectibles[k][0] = j;
				data->entity.collectibles[k][1] = i;
				printf("Collectible found at: [%d, %d]\n", j, i);
				k++;
			}
}

void	get_entities_location(t_data *data)
{
	get_player_location(data);
	get_exit_location(data);
	get_collectibles_location(data);
}
