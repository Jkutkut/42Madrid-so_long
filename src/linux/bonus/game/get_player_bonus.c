/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 20:19:15 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/31 12:26:58 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

/**
 * @brief Get the player form the map.
 * 
 * @param game Game structure.
 */
void	get_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
				game->map->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}