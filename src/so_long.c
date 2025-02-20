/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:06:25 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/20 16:07:56 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	(void)ac;
    t_data  *data;
    
    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
    {
        free_all(data);
        return (0);
    }
    if (take_off(data, av[1]) == 1)
    {
        free_all(data);
        return (0);
    }
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->map->width * 32, data->map->height * 32, "so_long");
    if (!data->mlx)
    {
        ft_error("MiniLibX initialization failed");
        return (0);
    }
    printf("deneme1\n");
    data->ship_right = mlx_xpm_file_to_image(data->mlx, "./textures/ship_right.xpm", &data->player_img_height, &data->player_img_height);
    data->ship_left = mlx_xpm_file_to_image(data->mlx, "./textures/ship_left.xpm", &data->player_img_height, &data->player_img_height);
    data->ship_up = mlx_xpm_file_to_image(data->mlx, "./textures/ship_up.xpm", &data->player_img_height, &data->player_img_height);
    data->ship_down = mlx_xpm_file_to_image(data->mlx, "./textures/ship_down.xpm", &data->player_img_height, &data->player_img_height);
    data->bg_img = mlx_xpm_file_to_image(data->mlx, "./textures/background.xpm", &data->bg_img_height, &data->bg_img_width);
    data->wall_img = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm", &data->wall_img_height, &data->wall_img_width);
    data->exit_img = mlx_xpm_file_to_image(data->mlx, "./textures/exit.xpm", &data->exit_img_height, &data->exit_img_width);
    data->collectible_img = mlx_xpm_file_to_image(data->mlx, "./textures/collectible.xpm", &data->collectible_img_height, &data->collectible_img_width);
    data->exit_ship = mlx_xpm_file_to_image(data->mlx, "./textures/exit_ship.xpm", &data->player_img_height, &data->player_img_width);

    if (!data->ship_right || !data->bg_img || !data->wall_img || !data->exit_img || !data->collectible_img)
    {
        ft_error("One or more XPM images failed to load");
        return (0);
    }
    render_map(data);
    
    mlx_hook(data->win, 17, 0, close_game, data);
    mlx_key_hook(data->win, key_hook, data);
    mlx_loop(data->mlx);
    free_all(data);
    return (0);
}
