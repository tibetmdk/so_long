/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:06:25 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/19 17:39:10 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_data	*data;
	
	if (ac == 2)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (free(data), 1);
		if (take_off(data, av[1]))
			return (free(data), 1);//free_all(data) olucak
	}
	return (0);
	
	
}
