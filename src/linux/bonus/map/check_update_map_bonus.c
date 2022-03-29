/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_update_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:22:01 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/29 20:01:10 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"

static void	free_map_end(t_map *map, int endtype, char *msg)
{
	freemap(map);
	end(endtype, msg);
}

/**
 * @brief Checks if the given map is valid.
 * Also updates the with and height of the map.
 * 
 * @param m Map to verify and update.
 */
void	check_update_map(t_map *m)
{
	int	i;
	int	line_len;

	if (!m || !m->map || !m->map[0])
		free_map_end(m, 1, ERROR_MAP_EMPTY);
	i = 0;
	m->width = ft_strlen(m->map[0]);
	while (m->map[i] != NULL)
	{
		line_len = ft_strlen(m->map[i]);
		if (line_len != m->width)
			free_map_end(m, 1, ERROR_MAP_WIDTH);
		if (m->map[i][0] != '1' || m->map[i][line_len - 1] != '1')
			free_map_end(m, 1, ERROR_MAP_BORDER);
		check_valid_line(m->map[i]);
		i++;
	}
	m->height = i;
	if (m->width > MAX_WIDTH || m->height > MAX_HEIGHT)
		free_map_end(m, 1, ERROR_MAP_BIG);
	while (--line_len)
		if (m->map[0][line_len] != '1' || m->map[i - 1][line_len] != '1')
			free_map_end(m, 1, ERROR_MAP_BORDER);
	while (REQUIRED_ELEMENTS[line_len])
		if (!map_contains(m, REQUIRED_ELEMENTS[line_len++]))
			free_map_end(m, 1, ERROR_MAP_CEP);
	check_unique_player(m);
}
