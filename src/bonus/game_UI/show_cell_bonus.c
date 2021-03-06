/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_cell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:44:36 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 19:12:29 by jre-gonz         ###   ########.fr       */
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
	int	i;

	if (game->map->map[y][x] == '0' || game->map->map[y][x] == 'C')
		show_img(game->imgenv[ENV_FLOOR], x, y, game);
	else if (game->map->map[y][x] == 'E')
	{
		show_img(game->imgexit[EXIT_O], x, y, game);
		show_img(game->imgexit[EXIT_C], x, y, game);
		i = game->imgexit[EXIT_C]->count - 1;
		game->imgexit[EXIT_C]->instances[i].z = 1;
	}
	else if (game->map->map[y][x] == '1')
		show_wall(game, x, y);
	if (game->map->map[y][x] == 'C')
		show_entity(game->imgcoin, x, y, game);
}
