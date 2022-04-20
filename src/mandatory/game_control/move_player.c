/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:11:58 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/20 10:05:21 by jre-gonz         ###   ########.fr       */
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
	int	i;

	if (!move_cooldown(0) || !can_move_there(dx, dy, game))
		return ;
	game->player.x += dx;
	game->player.y += dy;
	update_moves(game);
	game->imgplayer->instances[0].x += dx * IMG_SIZE;
	game->imgplayer->instances[0].y += dy * IMG_SIZE;
	if (game->map->map[game->player.y][game->player.x] == 'C')
		collect_coin(game);
	if (game->map->map[game->player.y][game->player.x] == 'E')
		if (game->coins == 0)
			freeend(0, MSG_WIN, game);
}
