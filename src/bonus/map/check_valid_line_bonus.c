/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_line_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:28:54 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/29 20:01:06 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"

/**
 * @brief Verify if the given line is valid.
 * This is done by checking if the only chararcters used are required ones,
 * 0 or 1.
 * Ends the program if the line is invalid.
 * 
 * @param line Line to check.
 */
void	check_valid_line(char *line)
{
	int	i;

	i = 1;
	while (line[i] && line[i + 1])
	{
		if (!ft_hasany(ALL_ELEMENTS, line[i]))
			end(1, ERROR_MAP_INVALID_CHAR);
		i++;
	}
}