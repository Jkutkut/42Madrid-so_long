/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_update_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:22:01 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/12 13:00:45 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

#define REQUIRED_ELEMENTS "CEP"

static int	map_contains(t_map *m, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("Checking %c\n", c);
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

void	check_update_map(t_map *m)
{
	int	i;
	int	line_len;

	if (!m || !m->map || !m->map[0])
		end(1, "Invalid map\n Map empty.");
	i = 0;
	m->width = ft_strlen(m->map[0]);
	while (m->map[i])
	{
		line_len = ft_strlen(m->map[i]);
		printf("%s\n", m->map[i]);
		if (line_len != m->width)
			end(1, "Invalid map:\n Map width is not constant.");
		if (m->map[i][0] != '1' || m->map[i][line_len - 1] != '1')
			end(1, "Invalid map:\n The map must be surronded by 1s.");
		i++;
	}
	while (--line_len)
		if (m->map[0][line_len] != '1' || m->map[i - 1][line_len] != '1')
			end(1, "Invalid map:\n The map must be surronded by 1s.");
	while (REQUIRED_ELEMENTS[line_len])
		if (!map_contains(m, REQUIRED_ELEMENTS[line_len++]))
			end(1, "Invalid map:\n The map must contain CEP");
}
