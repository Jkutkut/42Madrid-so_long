/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move_there.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:24:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/20 13:21:48 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control.h"

int	can_move_there(int x, int y, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = x + game->player.x;
	new_y = y + game->player.y;
	if (new_x <= 0 || new_x >= game->map->width - 1)
		return (0);
	if (new_y <= 0 || new_y >= game->map->height - 1)
		return (0);
	if (game->map->map[new_y][new_x] == '1')
		return (0);
	return (1);
}
