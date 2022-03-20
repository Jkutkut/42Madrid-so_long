/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:35:23 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/20 13:24:16 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	print_map(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->height)
	{
		j = 0;
		while (j < m->width)
		{
			if (m->map[i][j] == '0')
				ft_putchar_fd(' ', 1);
			else if (m->map[i][j] == '1')
				ft_putchar_fd('#', 1);
			else if (m->map[i][j] == 'C')
				ft_putchar_fd('.', 1);
			else
				ft_putchar_fd(m->map[i][j], 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
}
