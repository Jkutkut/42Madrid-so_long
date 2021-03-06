/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unique_player_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 20:02:01 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 19:11:03 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"

/**
 * @brief Check if there's only one player on the map.
 * If the map is not valid, ends the program.
 * 
 * @param m Map to check
 */
void	check_unique_player(t_map *m)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j++] == 'P')
			{
				if (++player_count > 1)
				{
					freemap(m);
					end(1, ERROR_MULTIPLE_PLAYERS);
				}
			}
		}
		i++;
	}
}
