/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:54:17 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/20 19:04:37 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_conditions(t_data *data)
{
	if (data->collected == data->collectible_count)
	{
		printf("You won!\n");
		free_all(data);
		exit(0);
		return (1);
	}
	else
	{
		printf("You need to collect all collectibles!\n");
	}
	return (0);
}

void	move_up(t_data *data)
{
	int	x;
	int	y;

	x = data->entity.player_x;
	y = data->entity.player_y;
	if (data->map->map[y - 1][x] != '1')
	{
		check_collectibles(data, x, (y - 1));
		mlx_put_image_to_window(data->mlx,
			data->win, data->bg_img, x * 32, y * 32);
		if (x == data->entity.exit_x && y == data->entity.exit_y)
			mlx_put_image_to_window(data->mlx,
				data->win, data->exit_img, x * 32, y * 32);
		if (x == data->entity.exit_x && (y - 1) == data->entity.exit_y)
		{
			if (check_conditions(data))
				return ;
			mlx_put_image_to_window(data->mlx,
				data->win, data->exit_ship, x * 32, (y - 1) * 32);
		}
		else
			mlx_put_image_to_window(data->mlx,
				data->win, data->ship_up, x * 32, (y - 1) * 32);
		data->entity.player_y--;
	}
}

void	move_down(t_data *data)
{
	int	x;
	int	y;

	x = data->entity.player_x;
	y = data->entity.player_y;
	if (data->map->map[y + 1][x] != '1')
	{
		check_collectibles(data, x, (y + 1));
		mlx_put_image_to_window(data->mlx,
			data->win, data->bg_img, x * 32, y * 32);
		if (x == data->entity.exit_x && y == data->entity.exit_y)
			mlx_put_image_to_window(data->mlx,
				data->win, data->exit_img, x * 32, y * 32);
		if (x == data->entity.exit_x && (y + 1) == data->entity.exit_y)
		{
			if (check_conditions(data))
				return ;
			mlx_put_image_to_window(data->mlx,
				data->win, data->exit_ship, x * 32, (y + 1) * 32);
		}
		else
			mlx_put_image_to_window(data->mlx,
				data->win, data->ship_down, x * 32, (y + 1) * 32);
		data->entity.player_y++;
	}
}

void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->entity.player_x;
	y = data->entity.player_y;
	if (data->map->map[y][x + 1] != '1')
	{
		check_collectibles(data, x + 1, y);
		mlx_put_image_to_window(data->mlx,
			data->win, data->bg_img, x * 32, y * 32);
		if (x == data->entity.exit_x && y == data->entity.exit_y)
			mlx_put_image_to_window(data->mlx,
				data->win, data->exit_img, x * 32, y * 32);
		if ((x + 1) == data->entity.exit_x && y == data->entity.exit_y)
		{
			if (check_conditions(data))
				return ;
			mlx_put_image_to_window(data->mlx,
				data->win, data->exit_ship, (x + 1) * 32, y * 32);
		}
		else
			mlx_put_image_to_window(data->mlx,
				data->win, data->ship_right, (x + 1) * 32, y * 32);
		data->entity.player_x++;
	}
}

void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->entity.player_x;
	y = data->entity.player_y;
	if (data->map->map[y][x - 1] != '1')
	{
		check_collectibles(data, x - 1, y);
		mlx_put_image_to_window(data->mlx,
			data->win, data->bg_img, x * 32, y * 32);
		if (x == data->entity.exit_x && y == data->entity.exit_y)
			mlx_put_image_to_window(data->mlx,
				data->win, data->exit_img, x * 32, y * 32);
		if ((x - 1) == data->entity.exit_x && y == data->entity.exit_y)
		{
			if (check_conditions(data))
				return ;
			mlx_put_image_to_window(data->mlx,
				data->win, data->exit_ship, (x - 1) * 32, y * 32);
		}
		else
			mlx_put_image_to_window(data->mlx,
				data->win, data->ship_left, (x - 1) * 32, y * 32);
		data->entity.player_x--;
	}
}
