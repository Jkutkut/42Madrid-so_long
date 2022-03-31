/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move_there_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:24:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/31 14:54:59 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control_bonus.h"

/**
 * @brief Whenever a player can move to a given position.
 * 
 * @param x Horizonal position.
 * @param y Vertical position.
 * @param game Game structure.
 * @return int 1 if the player can move to the given position, 0 otherwise.
 */
int	can_move_there(int x, int y, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = x + game->player.x;
	new_y = y + game->player.y;
	if (new_x <= 0 || new_x >= game->map->width - 1)
		return (0);
	if (new_y <= 0 || new_y >= game->map->height - 1)
		return (0);
	if (game->map->map[new_y][new_x] == '1')
		return (0);
	return (1);
}
