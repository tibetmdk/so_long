/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:11:22 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/16 17:04:46 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collectibles(t_data *data, int x, int y)
{
    int i;

    i = 0;
    while (i < data->collectible_count) // Tüm collectible'ları kontrol et
    {
        int col_x = data->entity.collectibles[i][0]; // i. collectible'ın X koordinatı
        int col_y = data->entity.collectibles[i][1]; // i. collectible'ın Y koordinatı

        if (x == col_x && y == col_y)
        {
            data->entity.collectibles[i][0] = -1; // Collectible'ı toplandı olarak işaretle
            data->entity.collectibles[i][1] = -1; // Collectible'ı toplandı olarak işaretle
            data->collected++; // Oyuncu bir collectible'ı topladı
            return (1); // Oyuncu bir collectible'ın üzerine geldi
        }
        i++;
    }
    return (0); // Oyuncu hiçbir collectible'ın üzerine gelmedi
}

