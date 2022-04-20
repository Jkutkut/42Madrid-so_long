/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_filename.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:07:11 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/20 09:06:45 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/**
 * @brief Checks if the given mapfile has a correct name. If incorrect, ends 
 *  the program.
 * 
 * @param filename Filename to check
 */
void	check_map_filename(char *filename)
{
	if (!filename)
		end(1, ERROR_NO_MAP);
	if (!endswith(filename, ".ber"))
		end(1, ERROR_MAP_EXTENSION);
}
