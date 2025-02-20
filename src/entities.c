/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:11:22 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/20 17:55:15 by tmidik           ###   ########.fr       */
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
