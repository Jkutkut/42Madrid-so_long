/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:22:01 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/10 11:37:57 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	check_map(char **map)
{
	int i;
	int mapWidth;
	int lineLen;

	if (!map || !map[0])
		end(1, "Invalid map\n Map empty.");
	mapWidth = ft_strlen(map[0]);
	while (map[i])
	{
		lineLen = ft_strlen(map[i]);
		if (lineLen != mapWidth)
			end(1, "Invalid map:\n Map width is not constant.");
		if (map[i][0] != '1' || map[i][lineLen - 1] != '1')
			end(1, "Invalid map:\n All rows must start and end with 1.");
		
		printf("-%s-\n", map[i++]);
	}
}