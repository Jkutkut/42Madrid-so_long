/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_level_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:53:18 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 19:11:09 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui_bonus.h"

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
			show_cell(j++, i, game);
		i++;
	}
	show_player(game);
	show_enemies(game);
}
