/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:23:59 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/19 19:48:36 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control.h"

void	move_player(int dx, int dy, t_game *game)
{
	if (can_move_there(dx, dy, game))
	{
		// show_img(game->imgenv[ENV_FLOOR], game->player.x, game->player.y, game);
		show_cell(game->player.x, game->player.y, game);
		game->player.x += dx;
		game->player.y += dy;
		show_player(game);
	}
}