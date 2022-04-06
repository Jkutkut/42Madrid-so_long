/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_cell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:44:36 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/06 15:31:34 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui_bonus.h"

/**
 * @brief Shows the cell represented by the given coordinates.
 * 
 * @param x Horizontal coordinate.
 * @param y Vertical coordinate.
 * @param game Game playing.
 */
void	show_cell(int x, int y, t_game *game)
{
	// // else if (game->map->map[y][x] == '0')
	// else
		// show_img(game->imgenv[ENV_FLOOR], x, y, 0, game);
	if (game->map->map[y][x] == 'E')
	{
		printf("exit\n");
		if (game->coins == 0)
			show_img(game->imgexit[EXIT_O], x, y, 0, game);
		else
			show_img(game->imgexit[EXIT_C], x, y, 0, game);
	}
	if (game->map->map[y][x] == 'C')
		show_img(game->imgcoin, x, y, 1, game);
	if (game->map->map[y][x] == '1')
		show_wall(game, x, y);
}
