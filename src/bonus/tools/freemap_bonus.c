/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:08:45 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 15:33:00 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools_bonus.h"

/**
 * @brief Frees the map.
 * 
 * @param m Map to free.
 */
void	freemap(t_map *m)
{
	int	i;

	printf("%p -> %p\n", m, m->map);
	if (!m)
		return ;
	if (m->map)
	{
		i = 0;
		while (i < m->height && m->map[i])
		{
			free(m->map[i]);
			i++;
		}
		free(m->map);
	}
	free(m);
}
