/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_update_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:22:01 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/20 09:13:51 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/**
 * @brief Frees the map and ends execution.
 * 
 * @param map Map to free.
 * @param endtype Type of end. See end function.
 * @param msg Message to show when ended.
 */
static void	free_map_end(t_map *map, int endtype, char *msg)
{
	freemap(map);
	end(endtype, msg);
}

/**
 * @brief Checks if the top and the bottom lines are valid.
 * 
 * @param m Map to check
 */
static void	check_border_lines(t_map *m)
{
	int	l;

	l = m->width;
	while (--l)
		if (m->map[0][l] != '1' || m->map[m->height - 1][l] != '1')
			free_map_end(m, 1, ERROR_MAP_BORDER);
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
	check_border_lines(m);
	if (!map_contains(m, REQUIRED_ELEMENTS))
		free_map_end(m, 1, ERROR_MAP_CEP);
	check_unique_player(m);
}
