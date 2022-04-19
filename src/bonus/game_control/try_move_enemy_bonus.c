/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_move_enemy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:48:50 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 15:11:45 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control_bonus.h"

/**
 * @brief Attemps to move the given enemy.
 * 
 * @param index Index of the enemy to move.
 * @param dx Horizontal increment.
 * @param dy Vertical increment.
 * @param game Game structure.
 * @return int 1 if the enemy can move to the given position, 0 otherwise.
 */
int	try_move_enemy(int index, int dx, int dy, t_game *game)
{
	t_enemy	*enemy;
	int		new_x;
	int		new_y;

	enemy = game->enemies[index];
	if (dx != 0 && dy != 0)
	{
		if (rand() % 2 == 0)
			dx = 0;
		else
			dy = 0;
	}
	new_x = enemy->x + dx;
	new_y = enemy->y + dy;
	if (new_x == 0 || new_x == game->map->width - 1)
		return (0);
	if (new_y == 0 || new_y == game->map->height - 1)
		return (0);
	if (ft_hasany("1CE", game->map->map[new_y][new_x]))
		return (0);
	if (enemy_collision(game, enemy, new_x, new_y))
		return (0);
	move_enemy(index, dx, dy, game);
	return (1);
}
