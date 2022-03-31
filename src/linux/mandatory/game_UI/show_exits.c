/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_exits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:56:42 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/31 17:23:28 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui.h"

/**
 * @brief Show the exits on the game board.
 * This function is executed when the player has all the coins.
 * 
 * @param game Game playing.
 */
void	show_exits(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map->height)
	{
		i = 0;
		while (i < game->map->width)
		{
			if (game->map->map[j][i] == 'E')
				show_cell(i, j, game);
			i++;
		}
		j++;
	}
}
