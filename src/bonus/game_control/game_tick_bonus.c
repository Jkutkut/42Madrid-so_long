/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_tick_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:17:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/11 12:11:29 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control_bonus.h"

static int	either_key_pressed(keys_t k1, keys_t k2, t_game *game)
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
void	game_tick(void *g)
{
	t_game	*game;

	game = (t_game *)g;
	tick(game);
	if (either_key_pressed(MLX_KEY_W, MLX_KEY_UP, game))
		move_player(0, -1, game);
	else if (either_key_pressed(MLX_KEY_S, MLX_KEY_DOWN, game))
		move_player(0, 1, game);
	else if (either_key_pressed(MLX_KEY_A, MLX_KEY_LEFT, game))
		move_player(-1, 0, game);
	else if (either_key_pressed(MLX_KEY_D, MLX_KEY_RIGHT, game))
		move_player(1, 0, game);
	else
		move_cooldown(1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		freeend(0, MSG_ENDGAME, game);
}
