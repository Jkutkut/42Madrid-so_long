/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_coin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:08:52 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/20 12:09:56 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control.h"

void	collect_coin(t_game *game)
{
	game->coins--;
	game->map->map[game->player.y][game->player.x] = '0';
	if (game->coins == 0)
		freeend(0, "\n\nYou win UwU", game);
}