/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_coin_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:08:52 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/10 23:26:36 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control_bonus.h"

/**
 * @brief Removes the coin from the map, updating the game.
 * If there are no more coins, the exits are opened.
 * 
 * @param game Game structure.
 */
void	collect_coin(t_game *game)
{
	int	i;

	if (game->map->map[game->player.y][game->player.x] != 'C')
		return ;
	game->coins--;
	i = -1;
	while (++i)
		if (game->imgcoin->instances[i].x == game->player.x)
			if (game->imgcoin->instances[i].y == game->player.y)
				break;
	game->imgcoin->instances[i].z = 0;
	printf("Coin collected, %d remaining\n", game->coins);
	game->map->map[game->player.y][game->player.x] = '0';
	if (game->coins == 0)
		show_exits(game);
}
