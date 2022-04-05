/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_border_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:44:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/05 09:47:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui_bonus.h"

/**
 * @brief Show on screen the border of the given game.
 * 
 * @param game Game playing.
 */
void	show_border(t_game *game)
{
	int	i;

	i = 1;
	while (i < game->map->height - 1)
	{
		show_img(game->imgenv[ENV_L_L], 0, i, 0, game);
		show_img(game->imgenv[ENV_L_R], game->map->width - 1, i, 0, game);
		i++;
	}
	i = 1;
	while (i < game->map->width - 1)
		show_img(game->imgenv[ENV_L_B], i++, game->map->height - 1, 0, game);
	show_img(game->imgenv[ENV_C_TL], 0, 0, 0, game);
	show_img(game->imgenv[ENV_C_TR], game->map->width - 1, 0, 0, game);
	show_img(game->imgenv[ENV_C_BL], 0, game->map->height - 1, 0, game);
	show_img(game->imgenv[ENV_C_BR], game->map->width - 1,
		game->map->height - 1, 0, game);
}
