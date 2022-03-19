/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:00:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/19 13:09:12 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	can_move_there(int x, int y, t_game *game)
{
	int	newX;
	int	newY;

	newX = x + game->player.x;
	newY = y + game->player.y;
	if (newX <= 0 || newX >= game->map->width - 1)
		return (0);
	if (newY <= 0 || newY >= game->map->height - 1)
		return (0);
	if (game->map->map[newY][newX] != '0')
		return (0);
	return (1);
}

void	move_player(int dx, int dy, t_game *game)
{
	if (can_move_there(dx, dy, game))
	{
		showimg(game->imgenv[ENV_FLOOR], game->player.x, game->player.y, game);
		game->player.x += dx;
		game->player.y += dy;
		show_player(game);
	}
}