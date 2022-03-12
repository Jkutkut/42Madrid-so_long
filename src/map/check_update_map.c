/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_update_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:22:01 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/12 12:50:23 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	check_update_map(t_map *m)
{
	int i;
	int lineLen;

	if (!m || !m->map || !m->map[0])
		end(1, "Invalid map\n Map empty.");
	i = 0;
	m->width = ft_strlen(m->map[0]);
	while (m->map[i])
	{
		lineLen = ft_strlen(m->map[i]);
		printf("%s\n", m->map[i]);
		if (lineLen != m->width)
			end(1, "Invalid map:\n Map width is not constant.");
		if (m->map[i][0] != '1' || m->map[i][lineLen - 1] != '1')
			end(1, "Invalid map:\n The map must be surronded by 1s.");
		i++;
	}
	while (lineLen--)
		if (m->map[0][lineLen] != '1' || m->map[i - 1][lineLen] != '1')
			end(1, "Invalid map:\n The map must be surronded by 1s.");
}