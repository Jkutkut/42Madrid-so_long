/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:08:45 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/29 22:13:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

/**
 * @brief Frees the map.
 * 
 * @param m Map to free.
 */
void	freemap(t_map *m)
{
	int	i;

	i = 0;
	if (!m)
		return ;
	if (m->map)
	{
		while (i < m->height)
		{
			free(m->map[i]);
			i++;
		}
		free(m->map);
	}
	free(m);
}
