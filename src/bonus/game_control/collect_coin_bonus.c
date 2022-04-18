/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_coin_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:08:52 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/18 15:06:42 by jre-gonz         ###   ########.fr       */
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
	i = -1;
	while (++i < game->imgcoin->count)
	{
		if (game->imgcoin->instances[i].z == 0)
			continue ;
		if (game->imgcoin->instances[i].x / IMG_SIZE == game->player.x && \
			game->imgcoin->instances[i].y / IMG_SIZE == game->player.y)
			break ;
	}
	if (i == game->imgcoin->count)
		return ;
	game->imgcoin->instances[i].z = 0;
	game->coins--;
	game->map->map[game->player.y][game->player.x] = '0';
	if (game->coins == 0)
		show_exits(game);
}
