/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:36:10 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/29 22:05:57 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control.h"

/**
 * @brief Loads the controls for the game.
 * 
 * @param game Game to load the controls to.
 */
void	load_controls(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 17, 1L << 17, close_game, game);
}
