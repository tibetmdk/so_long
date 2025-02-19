/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:23:45 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/19 19:28:26 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>
# include "../mlx/mlx.h"

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	char	**map_copy;
}				t_map;

typedef struct s_entity
{
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		**collectibles;
}				t_entity;  

typedef struct  s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*ship_right;
	void		*ship_left;
	void		*ship_up;
	void		*ship_down;
	void		*bg_img;
	void		*wall_img;
	void		*exit_img;
	void		*exit_ship;
	void		*collectible_img;
	int			bg_img_width;
	int			bg_img_height;
	int			collectible_img_width;
	int			collectible_img_height;
	int			exit_img_width;
	int			exit_img_height;
	int			wall_img_width;
	int			wall_img_height;
	int			player_img_width;
	int			player_img_height;
	int			collectible_count;
	int			collected;
	int			player_count;
	int			exit_count;
	t_map		*map;
	t_entity	entity;
}               t_data;

int ft_strcmp(const char *s1, const char *s2);
int	ft_strlen(char *str);
int	ft_printf(const char *str, ...);


char	*get_next_line(int fd);



int	name_control(char *str);
int	get_size(char *map_name, t_data *data);
int	ft_error(char *str);
int	take_off(t_data *data, char *map_name);
int	get_map(char *map_name, t_data *data);
int	get_map_to_map_copy(t_data *data);
int	is_map_rectangular(t_data *data);
int	is_map_surrounded(t_data *data);
int	is_entities_valid(t_data *data);
int	count_collectibles(t_data *data);


void	get_entities_location(t_data *data);
void	free_all(t_data *data);
void	free_map(t_data *data);
void	free_entities(t_data *data);
void	free_textures(t_data *data);

#endif