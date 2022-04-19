/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:50:43 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 19:14:54 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control_bonus.h"

/**
 * @brief Moves the given enemy the given amount.
 * 
 * @param index Index of the chosen enemy.
 * @param dx Horizontal amount.
 * @param dy Vertical amount.
 * @param game Game.
 */
void	move_enemy(int index, int dx, int dy, t_game *game)
{
	t_enemy	*enemy;
	int		i;

	enemy = game->enemies[index];
	enemy->x += dx;
	enemy->y += dy;
	i = 0;
	while (i < E_ANI)
	{
		game->imgenemy[i]->instances[index].x = enemy->x * IMG_SIZE;
		game->imgenemy[i]->instances[index].y = enemy->y * IMG_SIZE;
		i++;
	}
}
