/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:48:35 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/20 19:07:23 by tmidik           ###   ########.fr       */
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

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			tile = data->map->map[y][x];
			mlx_put_image_to_window(data->mlx,
				data->win, data->bg_img, x * 32, y * 32);
			if (tile == '1')
				mlx_put_image_to_window(data->mlx,
					data->win, data->wall_img, x * 32, y * 32);
			else if (tile == 'X')
				mlx_put_image_to_window(data->mlx,
					data->win, data->exit_img, x * 32, y * 32);
			else if (tile == 'C')
				mlx_put_image_to_window(data->mlx,
					data->win, data->collectible_img, x * 32, y * 32);
			else if (tile == 'P')
				mlx_put_image_to_window(data->mlx,
					data->win, data->ship_right, x * 32, y * 32);
			x++;
		}
		y++;
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
