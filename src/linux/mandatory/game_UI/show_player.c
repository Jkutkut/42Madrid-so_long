/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:29:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/31 15:43:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui.h"

/**
 * @brief Show the player in the given position.
 * 
 * @param game The game.
 */
void	show_player(t_game *game)
{
	show_entity(game->imgplayer, game->player.x, game->player.y, game);
}