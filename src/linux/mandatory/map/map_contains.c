/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_contains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:27:35 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/20 19:37:21 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/**
 * @brief If the given map contains the given char.
 * 
 * @param m Map to check
 * @param c Char to search
 * @return int 0 if not found, 1 if found
 */
int	map_contains(t_map *m, char c)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
			if (m->map[i][j++] == c)
				return (1);
		i++;
	}
	return (0);
}
