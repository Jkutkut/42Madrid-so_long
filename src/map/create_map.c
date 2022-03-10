/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:52:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/10 13:52:50 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	*create_map(char **m)
{
	t_map	*map;

	if (!m)
		end(1, "Error: map is null");
	if (!(map = (t_map *) malloc(sizeof(t_map))))
		end(1, "Error: malloc failed");
	map->map = m;
	map->width = 0;
	map->height = 0;
	return (map);
}