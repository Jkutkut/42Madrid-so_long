/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_update_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:22:01 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/20 19:31:31 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/**
 * @brief Check if there's only one player on the map.
 * If the map is not valid, ends the program.
 * 
 * @param m Map to check
 */
static void	check_unique_player(t_map *m)
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
			if (m->map[i][j++] == 'P')
				if (++player_count > 1)
					end(1, "Too many players.");
		i++;
	}
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
		end(1, "Invalid map\n Map empty.");
	i = 0;
	m->width = ft_strlen(m->map[0]);
	while (m->map[i] != NULL)
	{
		line_len = ft_strlen(m->map[i]);
		if (line_len != m->width)
			end(1, "Invalid map:\n Map width is not constant.");
		if (m->map[i][0] != '1' || m->map[i][line_len - 1] != '1')
			end(1, "Invalid map:\n The map must be surronded by 1s.");
		check_valid_line(m->map[i]);
		i++;
	}
	m->height = i;
	while (--line_len)
		if (m->map[0][line_len] != '1' || m->map[i - 1][line_len] != '1')
			end(1, "Invalid map:\n The map must be surronded by 1s.");
	while (REQUIRED_ELEMENTS[line_len])
		if (!map_contains(m, REQUIRED_ELEMENTS[line_len++]))
			end(1, "Invalid map:\n The map must contain CEP");
	check_unique_player(m);
}
