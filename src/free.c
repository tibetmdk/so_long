/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:24:43 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/21 21:49:14 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *data)
{
	int	i;

	if (!data || !data->map)
		return ;
	if (data->map->map)
	{
		i = 0;
		while (i < data->map->height)
			free(data->map->map[i++]);
		free(data->map->map);
	}
	if (data->map->map_copy)
	{
		i = 0;
		while (i < data->map->height)
			free(data->map->map_copy[i++]);
		free(data->map->map_copy);
	}
	free(data->map);
	data->map = NULL;
}

void	free_entities(t_data *data)
{
	int	i;

	i = 0;
	if (data->entity.collectibles)
	{
		while (i < data->collectible_count)
		{
			if (data->entity.collectibles[i])
				free(data->entity.collectibles[i]);
			i++;
		}
		free(data->entity.collectibles);
	}
}

void	free_textures(t_data *data)
{
	if (data->mlx)
	{
		if (data->ship_right)
			mlx_destroy_image(data->mlx, data->ship_right);
		if (data->ship_left)
			mlx_destroy_image(data->mlx, data->ship_left);
		if (data->ship_up)
			mlx_destroy_image(data->mlx, data->ship_up);
		if (data->ship_down)
			mlx_destroy_image(data->mlx, data->ship_down);
		if (data->bg_img)
			mlx_destroy_image(data->mlx, data->bg_img);
		if (data->wall_img)
			mlx_destroy_image(data->mlx, data->wall_img);
		if (data->exit_img)
			mlx_destroy_image(data->mlx, data->exit_img);
		if (data->collectible_img)
			mlx_destroy_image(data->mlx, data->collectible_img);
		if (data->exit_ship)
			mlx_destroy_image(data->mlx, data->exit_ship);
	}
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	free_map(data);
	free_entities(data);
	free_textures(data);
	if (data->mlx)
	{
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
}
