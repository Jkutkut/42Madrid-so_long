/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move_there.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:24:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/19 13:30:29 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control.h"

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
	if (game->map->map[newY][newX] == '1')
		return (0);
	return (1);
}