/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:41:06 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/06 18:42:18 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui_bonus.h"

/**
 * @brief Detects the correct sprite to show on the given wall.
 * If the cell down is a wall, it will show the full-wall sprite.
 * 
 * @param game Game to show the sprite on.
 * @param x Horizontal index of the cell.
 * @param y Vertical index of the cell.
 */
void	show_wall(t_game *game, int x, int y)
{
	if (game->map->map[y][x] != '1')
		return ;
	if (game->map->height > y + 1 && game->map->map[y + 1][x] == '1')
	{
		printf("wall at %d %d %d\n", x, y, 0);
		show_img(game->imgenv[ENV_WALL], x, y, 0, game);
	}
	else
	{
		printf("Wall line at %d %d %d\n", x, y, 0);
		show_img(game->imgenv[ENV_L_T], x, y, 0, game);
	}
}
