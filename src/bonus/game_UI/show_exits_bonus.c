/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_exits_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:56:42 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 19:11:11 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui_bonus.h"

/**
 * @brief Show the exits on the game board.
 * This function is executed when the player has all the coins.
 * 
 * @param game Game playing.
 */
void	show_exits(t_game *game)
{
	int	j;

	j = 0;
	while (j < game->imgexit[EXIT_O]->count)
	{
		game->imgexit[EXIT_O]->instances[j++].z = 1;
	}
	j = 0;
	while (j < game->imgexit[EXIT_C]->count)
	{
		game->imgexit[EXIT_C]->instances[j++].z = 0;
	}
}
