/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_filename.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:07:11 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/07 10:11:54 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	end(int endtype, char *msg);

/**
 * @brief Checks if the given mapfile has a correct name. If incorrect, ends 
 *  the program.
 * 
 * @param filename Filename to check
 */
void	check_map_filename(char *filename)
{
	if (!filename)
		end(1, "No map file specified\n");
	if (!endswith(filename, ".ber"))
		end(1, "File should be a .ber file\n");
}
