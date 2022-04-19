/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_collision_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:54:14 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 20:37:12 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control_bonus.h"

/**
 * @brief If the given enemy is on the same cell as another enemy
 * 
 * @param game Game to check.
 * @param enemy Enemy to keep in mind
 * @param x Horizontal position of the enemy.
 * @param y Vertical position of the enemy.
 * @return int 1 if the enemy is on the same cell as another enemy, else 0.
 */
int	enemy_collision(t_game *game, t_enemy *enemy, int x, int y)
{
	int	i;

	i = 0;
	while (game->enemies[i])
	{
		if (game->enemies[i]->x == x && game->enemies[i]->y == y)
			if (game->enemies[i] != enemy)
				return (1);
		i++;
	}
	return (0);
}
