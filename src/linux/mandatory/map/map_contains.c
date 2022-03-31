/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_contains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:27:35 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/31 16:57:36 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/**
 * @brief If the given map contains all elements in the given String.
 * 
 * @param m Map to check
 * @param str String to search
 * @return int 0 if not found, 1 if found
 */
int	map_contains(t_map *m, char *str)
{
	int	c;
	int	i;
	int	j;

	i = 0;
	c = 0;
	while (str[c])
	{
		while (m->map[i])
		{
			j = 0;
			while (m->map[i][j])
				if (m->map[i][j++] == str[c])
					break ;
			if (m->map[i][j] == str[c])
				break ;
			i++;
		}
		if (!m->map[i])
			return (0);
		c++;
	}
	return (1);
}
