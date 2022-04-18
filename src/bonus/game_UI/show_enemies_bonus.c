/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_enemies_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:04:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/18 15:08:56 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui_bonus.h"

static void	show_enemy(t_game *game, int x, int y)
{
	int			i;
	int			instance;
	mlx_image_t	*img;

	i = 0;
	instance = game->imgenemy[0]->count;
	while (i < E_ANI)
	{
		img = game->imgenemy[i];
		show_entity(img, x, y, game);
		img->instances[instance].z = 0;
		i++;
	}
	game->imgenemy[0]->instances[instance].z = 2;
}

/**
 * @brief Show the enemies on the game board.
 * 
 * @param game Game playing.
 */
void	show_enemies(t_game *game)
{
	int	i;

	i = -1;
	while (game->enemies[++i])
		show_enemy(game, game->enemies[i]->x, game->enemies[i]->y);
}
