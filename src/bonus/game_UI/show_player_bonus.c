/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:29:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/10 19:40:07 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_ui_bonus.h"

/**
 * @brief Show the player in the given position.
 * 
 * @param game The game.
 */
void	show_player(t_game *game)
{
	mlx_image_t	*img;
	int			i;

	i = 0;
	while (i < P_ANI)
	{
		img = game->imgplayer[i];
		show_entity(img, game->player.x, game->player.y, game);
		img->instances[0].z = 0;
		i++;
	}
	img = game->imgplayer[0];
	img->instances[0].z = 2;
}
