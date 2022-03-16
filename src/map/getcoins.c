/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcoins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 22:16:30 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/16 22:20:48 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/**
 * @brief Calculates the number of coins in the map.
 * 
 * @param map Map to calculate the number of coins.
 * @return int Total number of coins of the map.
 */
int	getcoins(t_map *map)
{
	int	i;
	int	j;
	int	coins;

	i = 0;
	coins = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	return (coins);
}