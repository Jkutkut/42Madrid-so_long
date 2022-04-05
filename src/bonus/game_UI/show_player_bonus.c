/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:29:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/05 07:51:32 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui_bonus.h"

/**
 * @brief Show the player in the given position.
 * 
 * @param game The game.
 */
void	show_player(t_game *game)
{
	mlx_image_t	*img;

	img = game->imgplayer[game->p_index];
	show_entity(img, game->player.x, game->player.y, game);
}
