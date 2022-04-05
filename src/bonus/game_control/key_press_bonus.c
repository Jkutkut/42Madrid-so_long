/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:17:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/05 08:24:49 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control_bonus.h"

static int	either_key(int k1, int k2, t_game *game)
{
	if (mlx_is_key_down(game->mlx, k1))
		return (1);
	if (mlx_is_key_down(game->mlx, k2))
		return (1);
	return (0);
}

/**
 * @brief Handles the key press event.
 * 
 * @param game Game structure.
 * @return int Value to return for the mlx function.
 */
int	key_press(t_game *game)
{
	if (either_key(KEY_W, KEY_UP, game))
		move_player(0, -1, game);
	else if (either_key(KEY_S, KEY_DOWN, game))
		move_player(0, 1, game);
	else if (either_key(KEY_A, KEY_LEFT, game))
		move_player(-1, 0, game);
	else if (either_key(KEY_D, KEY_RIGHT, game))
		move_player(1, 0, game);
	return (0);
}
