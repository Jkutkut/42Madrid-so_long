/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:48:05 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 19:14:07 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_control_bonus.h"

/**
 * @brief Updates the position of enemies.
 * 
 * @param game Game structure.
 */
void	update_enemies(t_game *game)
{
	int	i;
	int	dx;
	int	dy;

	i = 0;
	while (game->enemies[i])
	{
		while (1)
		{
			dx = rand() % 3 - 1;
			dy = rand() % 3 - 1;
			if (try_move_enemy(i, dx, dy, game))
				break ;
		}
		i++;
	}
}
