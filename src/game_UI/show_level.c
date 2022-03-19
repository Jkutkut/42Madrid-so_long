/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:53:18 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/19 18:40:58 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui.h"

/**
 * @brief Show on screen the given game.
 * 
 * @param game 
 */
void	show_level(t_game *game)
{
	int	i;
	int	j;

	show_border(game);
	i = 0;
	while (i < game->map->height - 1)
	{
		j = 1;
		while (j < game->map->width - 1)
		{
			if (game->map->map[i][j] == '0')
				show_img(game->imgenv[ENV_FLOOR], j, i, game);
			else if (game->map->map[i][j] == '1')
				show_wall(game, j, i);
			else if (game->map->map[i][j] == 'E')
				show_img(game->imgexit[EXIT_C], j, i, game);
			else if (game->map->map[i][j] == 'C')
				show_img(game->imgcoin, j, i, game);
			else if (game->map->map[i][j] == 'P')
				show_img(game->imgplayer[0], j, i, game);
			j++;
		}
		i++;
	}
	show_player(game);
}
