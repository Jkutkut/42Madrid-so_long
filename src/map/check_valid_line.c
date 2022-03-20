/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:28:54 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/20 19:51:30 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

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

	printf("required '%s'\n", REQUIRED_ELEMENTS);
	printf("%d\n", BONUS);
	i = 1;
	while (line[i] && line[i + 1])
	{
		if (!ft_hasany("01", line[i]))
			if (!ft_hasany(REQUIRED_ELEMENTS, line[i]))
				end(1, "Invalid charactes in map.");
		i++;
	}
}
