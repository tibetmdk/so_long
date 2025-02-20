/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:06:25 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/20 18:50:21 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initializations_1(t_data *d)
{
	char	*p[] = {"./textures/ship_right.xpm", "./textures/ship_left.xpm",
		"./textures/ship_up.xpm", "./textures/ship_down.xpm",
		"./textures/background.xpm", "./textures/wall.xpm",
		"./textures/exit.xpm", "./textures/collectible.xpm",
		"./textures/exit_ship.xpm"};
	void	**img[] = {&d->ship_right, &d->ship_left, &d->ship_up,
		&d->ship_down, &d->bg_img, &d->wall_img, &d->exit_img,
		&d->collectible_img, &d->exit_ship};
	int		*w[] = {&d->player_img_width, &d->player_img_width,
		&d->player_img_width, &d->player_img_width, &d->bg_img_width,
		&d->wall_img_width, &d->exit_img_width, &d->collectible_img_width,
		&d->player_img_width};
	int		*h[] = {&d->player_img_height, &d->player_img_height,
		&d->player_img_height, &d->player_img_height, &d->bg_img_height,
		&d->wall_img_height, &d->exit_img_height, &d->collectible_img_height,
		&d->player_img_height};
	int		i;

	i = -1;
	while (++i < 9)
		*(void **)img[i] = mlx_xpm_file_to_image(d->mlx, p[i], h[i], w[i]);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			return (free_all(data), 1);
		if (take_off(data, av[1]) == 1)
			return (free_all(data), 1);
		data->mlx = mlx_init();
		initializations_1(data);
		data->win = mlx_new_window(data->mlx, data->map->width \
		* 32, data->map->height * 32, "so_long");
		if (!data->mlx)
			return (ft_error("MiniLibX initialization failed"), 1);
		if (!data->ship_right || !data->bg_img || !data->wall_img
			|| !data->exit_img || !data->collectible_img)
			return (ft_error("One or more XPM images failed to load"), 1);
		render_map(data);
		mlx_hook(data->win, 17, 0, close_game, data);
		mlx_key_hook(data->win, key_hook, data);
		mlx_loop(data->mlx);
		free_all(data);
	}
	return (0);
}
