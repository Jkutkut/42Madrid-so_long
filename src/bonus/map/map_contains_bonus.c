/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_contains_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:27:35 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 19:09:52 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"

/**
 * @brief If a matrix has the given char
 * 
 * @param m Char matrix to check
 * @param c Char to check
 * @return int 1 if found, else 0
 */
static int	matrix_hasany(char **m, char c)
{
	int	i;
	int	j;

	i = 0;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
			if (m[i][j++] == c)
				return (1);
		i++;
	}
	return (0);
}

/**
 * @brief If the given map contains all elements in the given String.
 * 
 * @param m Map to check
 * @param str String to search
 * @return int 0 if not found, 1 if found
 */
int	map_contains(t_map *m, char *str)
{
	while (*str)
		if (!matrix_hasany(m->map, *str++))
			return (0);
	return (1);
}
