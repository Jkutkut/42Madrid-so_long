/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_coin_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:08:52 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/31 14:55:10 by jre-gonz         ###   ########.fr       */
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
	if (game->map->map[game->player.y][game->player.x] != 'C')
		return ;
	game->coins--;
	game->map->map[game->player.y][game->player.x] = '0';
	if (game->coins == 0)
		show_exits(game);
}
