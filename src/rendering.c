/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:48:35 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/22 14:05:01 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_data *data)
{
	free_all(data);
	exit(0);
	return (0);
}

void	render_map(t_data *data)
{
	int		x;
	int		y;
	char	tile;
	void	*img;

	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			tile = data->map->map[y][x];
			img = data->bg_img;
			if (tile == '1')
				img = data->wall_img;
			else if (tile == 'E')
				img = data->exit_img;
			else if (tile == 'C')
				img = data->collectible_img;
			else if (tile == 'P')
				img = data->ship_right;
			mlx_put_image_to_window(data->mlx, data->win, img, x * 32, y * 32);
		}
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65361)
		move_left(data);
	else if (keycode == 65362)
		move_up(data);
	else if (keycode == 65363)
		move_right(data);
	else if (keycode == 65364)
		move_down(data);
	else if (keycode == 65307)
	{
		free_all(data);
		exit(0);
	}
	return (0);
}
