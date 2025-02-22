/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:54:17 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/22 14:28:54 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_conditions(t_data *data)
{
	if (data->collected == data->collectible_count)
	{
		ft_printf("You won!\n");
		free_all(data);
		exit(0);
		return (1);
	}
	else
	{
		ft_printf("You need to collect all collectibles!\n");
	}
	return (0);
}

void	move_up(t_data *data)
{
	int		x;
	int		y;
	void	*img;

	x = data->entity.player_x;
	y = data->entity.player_y;
	if (data->map->map[y - 1][x] == '1')
		return ;
	check_collectibles(data, x, y - 1);
	mlx_put_image_to_window(data->mlx, data->win, data->bg_img, x * 32, y * 32);
	if (x == data->entity.exit_x && y == data->entity.exit_y)
		mlx_put_image_to_window(data->mlx,
			data->win, data->exit_img, x * 32, y * 32);
	img = data->ship_up;
	if (x == data->entity.exit_x && y - 1 == data->entity.exit_y)
	{
		if (check_conditions(data))
			return ;
		img = data->exit_ship;
	}
	mlx_put_image_to_window(data->mlx, data->win, img, x * 32, (y - 1) * 32);
	data->entity.player_y--;
	count_move(data);
}

void	move_down(t_data *data)
{
	int		x;
	int		y;
	void	*img;

	x = data->entity.player_x;
	y = data->entity.player_y;
	if (data->map->map[y + 1][x] == '1')
		return ;
	check_collectibles(data, x, y + 1);
	mlx_put_image_to_window(data->mlx, data->win, data->bg_img, x * 32, y * 32);
	if (x == data->entity.exit_x && y == data->entity.exit_y)
		mlx_put_image_to_window(data->mlx,
			data->win, data->exit_img, x * 32, y * 32);
	img = data->ship_down;
	if (x == data->entity.exit_x && y + 1 == data->entity.exit_y)
	{
		if (check_conditions(data))
			return ;
		img = data->exit_ship;
	}
	mlx_put_image_to_window(data->mlx, data->win, img, x * 32, (y + 1) * 32);
	data->entity.player_y++;
	count_move(data);
}

void	move_right(t_data *data)
{
	int		x;
	int		y;
	void	*img;

	x = data->entity.player_x;
	y = data->entity.player_y;
	if (data->map->map[y][x + 1] == '1')
		return ;
	check_collectibles(data, x + 1, y);
	mlx_put_image_to_window(data->mlx, data->win, data->bg_img, x * 32, y * 32);
	if (x == data->entity.exit_x && y == data->entity.exit_y)
		mlx_put_image_to_window(data->mlx,
			data->win, data->exit_img, x * 32, y * 32);
	img = data->ship_right;
	if (x + 1 == data->entity.exit_x && y == data->entity.exit_y)
	{
		if (check_conditions(data))
			return ;
		img = data->exit_ship;
	}
	mlx_put_image_to_window(data->mlx, data->win, img, (x + 1) * 32, y * 32);
	data->entity.player_x++;
	count_move(data);
}

void	move_left(t_data *data)
{
	int		x;
	int		y;
	void	*img;

	x = data->entity.player_x;
	y = data->entity.player_y;
	if (data->map->map[y][x - 1] == '1')
		return ;
	check_collectibles(data, x - 1, y);
	mlx_put_image_to_window(data->mlx, data->win, data->bg_img, x * 32, y * 32);
	if (x == data->entity.exit_x && y == data->entity.exit_y)
		mlx_put_image_to_window(data->mlx,
			data->win, data->exit_img, x * 32, y * 32);
	img = data->ship_left;
	if (x - 1 == data->entity.exit_x && y == data->entity.exit_y)
	{
		if (check_conditions(data))
			return ;
		img = data->exit_ship;
	}
	mlx_put_image_to_window(data->mlx, data->win, img, (x - 1) * 32, y * 32);
	data->entity.player_x--;
	count_move(data);
}
