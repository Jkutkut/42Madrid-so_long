/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:28:15 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/31 16:29:20 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

/**
 * @brief Create a enemy object.
 * 
 * @param game Game structure.
 * @param x Horizontal position.
 * @param y Vertical position.
 * @return t_enemy* Enemy object.
 */
t_enemy	*create_enemy(t_game *game, int x, int y)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (!enemy)
		end(1, ERROR_MALLOC);
	enemy->x = x;
	enemy->y = y;
	game->map->map[y][x] = '0';
	return (enemy);
}