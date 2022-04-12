/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_enemy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:24:50 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/12 10:13:48 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

/**
 * @brief Counts the number of enemies in the map.
 * 
 * @param game Game structure.
 * @return int Number of enemies.
 */
int	count_enemy(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map[i][j] == 'F')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
