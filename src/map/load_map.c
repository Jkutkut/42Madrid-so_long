/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:28:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/03/28 11:26:37 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/**
 * @brief Reads the map file and returns a 2D array of chars. If file is
 * invalid, exits the program.
 * If empty map, ends the program.
 * If malloc fails when spliting, returns NULL.
 * 
 * @param filename 
 * @return char** 
 */
char	**load_map(char *filename)
{
	int		fd;
	int		r;
	char	line[BUFFER_SIZE];
	char	*m;
	char	**map;

	check_map_filename(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		end(1, "Map file not found\n");
	m = NULL;
	r = BUFFER_SIZE;
	while (r == BUFFER_SIZE)
	{
		r = read(fd, &line, BUFFER_SIZE);
		line[r] = '\0';
		ft_strextend(&m, line);
	}
	if (m == NULL)
		end(1, "Map file is empty\n");
	close(fd);
	map = ft_split(m, '\n');
	free(m);
	return (map);
}
