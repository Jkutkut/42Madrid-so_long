/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:36:10 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/20 10:02:45 by jre-gonz         ###   ########.fr       */
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
	mlx_loop_hook(game->mlx, &game_tick, game);
}
