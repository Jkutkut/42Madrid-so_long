/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_enemies_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:29:34 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/31 16:32:39 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

/**
 * @brief Get the enemies form the map.
 * 
 * @param game Game to get the enemies form.
 */
void	get_enemies(t_game *game)
{
	int	x;
	int	y;
	int	index;

	game->enemies = malloc(sizeof(t_enemy *) * (count_enemy(game) + 1));
	if (!game->enemies)
		end(1, ERROR_MALLOC);
	y = 0;
	index = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'F')
				game->enemies[index++] = create_enemy(game, x, y);
			x++;
		}
		y++;
	}
	game->enemies[index] = NULL;
}
