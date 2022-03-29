/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:37:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/29 22:01:39 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control.h"

/**
 * @brief Function used to close the game.
 * 
 * @param game Game structure.
 * @return int Value to return for the mlx function.
 */
int	close_game(t_game *game)
{
	freeend(0, MSG_ENDGAME, game);
	return (0);
}
