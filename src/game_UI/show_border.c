/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_border.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:44:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/19 17:44:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui.h"

/**
 * @brief Show on screen the border of the given game.
 * 
 * @param game 
 */
void	show_border(t_game *game)
{
	int	i;

	i = 1;
	while (i < game->map->height - 1)
	{
		showimg(game->imgenv[ENV_L_L], 0, i, game);
		showimg(game->imgenv[ENV_L_R], game->map->width - 1, i, game);
		i++;
	}
	i = 1;
	while (i < game->map->width - 1)
		showimg(game->imgenv[ENV_L_B], i++, game->map->height - 1, game);
	showimg(game->imgenv[ENV_C_TL], 0, 0, game);
	showimg(game->imgenv[ENV_C_TR], game->map->width - 1, 0, game);
	showimg(game->imgenv[ENV_C_BL], 0, game->map->height - 1, game);
	showimg(game->imgenv[ENV_C_BR], game->map->width - 1,
		game->map->height - 1, game);
}