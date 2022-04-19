/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:08:45 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 16:52:33 by jre-gonz         ###   ########.fr       */
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

	if (!m)
		return ;
	if (m->map)
	{
		i = 0;
		while (m->map[i])
		{
			free(m->map[i]);
			i++;
		}
		free(m->map);
	}
	free(m);
}
