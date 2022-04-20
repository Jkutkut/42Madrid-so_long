/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:52:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/20 09:09:57 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/**
 * @brief Create the map from the matrix.
 * 
 * @param m Matrix of chars.
 * @return t_map* 
 */
t_map	*create_map(char **m)
{
	t_map	*map;
	int		i;

	if (!m)
		end(1, ERROR_MAP_NULL);
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
	{
		i = 0;
		while (m[i])
			free(m[i++]);
		free(m);
		end(1, ERROR_MALLOC);
	}
	map->map = m;
	check_update_map(map);
	print_map(map);
	return (map);
}
