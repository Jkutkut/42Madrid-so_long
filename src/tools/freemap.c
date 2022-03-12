/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:08:45 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/12 13:32:42 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

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
