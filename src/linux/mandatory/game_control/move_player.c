/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:23:59 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/29 22:03:39 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control.h"

/**
 * @brief Attempt to move the player to a given position.
 * 
 * @param dx Horizontal increment.
 * @param dy Vertical increment.
 * @param game Game structure.
 */
void	move_player(int dx, int dy, t_game *game)
{
	if (!can_move_there(dx, dy, game))
		return ;
	show_cell(game->player.x, game->player.y, game);
	game->player.x += dx;
	game->player.y += dy;
	update_moves(game);
	if (game->map->map[game->player.y][game->player.x] == 'C')
		collect_coin(game);
	if (game->map->map[game->player.y][game->player.x] == 'E')
		if (game->coins == 0)
			freeend(0, MSG_WIN, game);
	show_player(game);
}
