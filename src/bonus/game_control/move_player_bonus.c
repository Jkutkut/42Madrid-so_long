/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:11:58 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/11 10:47:07 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control_bonus.h"

/**
 * @brief Attempt to move the player to a given position.
 * 
 * @param dx Horizontal increment.
 * @param dy Vertical increment.
 * @param game Game structure.
 */
void	move_player(int dx, int dy, t_game *game)
{
	static int	move_cooldown = 0;
	int			i;

	if (move_cooldown-- <= 0 && can_move_there(dx, dy, game))
	{
		game->player.x += dx;
		game->player.y += dy;
		update_moves(game);
		i = 0;
		while (i < P_ANI)
		{
			game->imgplayer[i]->instances[0].x += dx * IMG_SIZE;
			game->imgplayer[i]->instances[0].y += dy * IMG_SIZE;
			i++;
		}
		if (game->map->map[game->player.y][game->player.x] == 'C')
			collect_coin(game);
		if (game->map->map[game->player.y][game->player.x] == 'E')
			if (game->coins == 0)
				freeend(0, MSG_WIN, game);
		update_enemies(game);
		i = -1;
		while (game->enemies[++i])
			if (game->enemies[i]->x == game->player.x)
				if (game->enemies[i]->y == game->player.y)
					freeend(0, MSG_LOSE, game);
		move_cooldown = 5;
	}
}
